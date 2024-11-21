/************************************************************************************************
Copyright (c) 2024, Luis Francisco Herrera Garay<lf.herreragaray@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/**
 * @file gpio.c
 * @brief Implementación de funciones para la manipulación de pines GPIO.
 *
 * Este archivo contiene la implementación de las funciones necesarias para controlar pines GPIO
 * a través de una abstracción. Permite crear instancias de pines, configurar su dirección y
 * establecer su estado.
 *
 * @author Luis Francisco Herrera Garay
 * @date 2024
 */

/* === Headers files inclusions =============================================================== */
#include "gpio.h" /**< Archivo de cabecera que contiene las definiciones y prototipos de funciones para el manejo de GPIO. */
#include <string.h> /**< Biblioteca estándar para manipulación de cadenas. */
#include <stddef.h> /**< Biblioteca estándar que define los macros para NULL y tamaños. */
#include "hal.h" /**< Archivo que abstrae las funciones de hardware para controlar los pines GPIO. */

/* === Macros definitions ====================================================================== */

#ifndef GPIO_MAX_INSTANCES
#define GPIO_MAX_INSTANCES 10 /**< Número máximo de instancias de GPIO que pueden ser creadas. */
#endif

/* === Private data type declarations ========================================================== */

/**
 * @brief Estructura que representa una instancia de un pin GPIO.
 *
 * Esta estructura almacena la información necesaria para controlar un pin específico,
 * como el puerto y el bit del pin, así como su estado (si es de salida o entrada).
 */
struct gpio_s {
    uint8_t port; /**< Puerto donde se encuentra el pin GPIO. */
    uint8_t bit;  /**< Número de bit dentro del puerto para el pin GPIO. */
    bool output;  /**< Indica si el pin está configurado como salida (true) o entrada (false). */
#ifndef USE_DYNAMIC_MEM
    bool used; /**< Indica si la instancia de GPIO está en uso (solo para asignación estática). */
#endif
};

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/**
 * @brief Asigna una instancia de GPIO de manera estática.
 *
 * Esta función asigna una instancia libre del arreglo estático de GPIOs. Si no hay instancias
 * libres, retorna NULL.
 *
 * @return gpio_t Instancia asignada de GPIO o NULL si no hay espacio.
 */
#ifndef USE_DYNAMIC_MEM
static gpio_t allocateInstance(void);
#endif

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/**
 * @brief Asigna una instancia de GPIO de manera estática.
 *
 * Esta función busca una instancia no utilizada en el arreglo estático de instancias de GPIO y
 * la marca como utilizada. Si no se encuentran instancias libres, retorna NULL.
 *
 * @return gpio_t Instancia de GPIO libre o NULL si no hay instancias disponibles.
 */
#ifndef USE_DYNAMIC_MEM
static gpio_t allocateInstance() {
    static struct gpio_s instances[GPIO_MAX_INSTANCES] = {
        0}; /**< Arreglo estático que almacena las instancias de GPIO. */

    gpio_t result = NULL;
    for (int index = 0; index < GPIO_MAX_INSTANCES; index++) {
        if (!instances[index].used) {
            result = &instances[index]; /**< Asigna la instancia disponible. */
            result->used = true;        /**< Marca la instancia como usada. */
            break;
        }
    }
    return result;
}
#endif

/* === Public function implementation ========================================================== */

/**
 * @brief Crea una nueva instancia de GPIO.
 *
 * Esta función crea una nueva instancia de un pin GPIO y la configura con el puerto y bit
 * especificados. Si se utiliza memoria dinámica, se reserva espacio para la nueva instancia;
 * de lo contrario, se asigna de manera estática.
 *
 * @param port El puerto en el que se encuentra el pin GPIO.
 * @param bit El bit dentro del puerto del pin GPIO.
 * @return gpio_t Instancia de GPIO creada, o NULL si hubo un error al crearla.
 */
gpio_t gpioCreate(uint8_t port, uint8_t bit) {
#ifdef USE_DYNAMIC_MEM
    gpio_t self = malloc(
        sizeof(struct gpio_s)); /**< Reserva memoria dinámica para una nueva instancia de GPIO. */
#else
    gpio_t self = allocateInstance(); /**< Asigna una instancia estática de GPIO. */
#endif

    if (self) {
        self->port = port;    /**< Establece el puerto del GPIO. */
        self->bit = bit;      /**< Establece el bit del GPIO. */
        self->output = false; /**< Establece el pin como entrada por defecto. */
    }
    return self; /**< Retorna la instancia creada o NULL si falló la creación. */
}

/**
 * @brief Configura un pin GPIO como salida o entrada.
 *
 * Esta función configura el pin GPIO como salida o entrada, dependiendo del valor del parámetro
 * `output`. Además, ajusta la dirección del pin a través de la capa de abstracción de hardware.
 *
 * @param self Instancia de GPIO que se desea configurar.
 * @param output Valor booleano que indica si el pin debe ser configurado como salida (true) o
 * entrada (false).
 */
void gpioSetOutput(gpio_t self, bool output) {
    self->output = output; /**< Establece si el pin es salida o entrada. */
    hal_gpio_set_direction(self->port, self->bit, output); /**< Configura la dirección del pin. */
}

/**
 * @brief Establece el estado de un pin GPIO (solo para pines de salida).
 *
 * Esta función establece el estado del pin GPIO (alto o bajo) si está configurado como salida.
 *
 * @param self Instancia de GPIO cuyo estado se desea cambiar.
 * @param state Valor booleano que indica el estado del pin (true para alto, false para bajo).
 */
void gpioSetState(gpio_t self, bool state) {
    if (self->output) {
        hal_gpio_set_output(self->port, self->bit,
                            state); /**< Establece el estado del pin si es salida. */
    }
}

/**
 * @brief Obtiene el estado de un pin GPIO (solo para pines de entrada).
 *
 * Esta función obtiene el estado de un pin GPIO configurado como entrada.
 *
 * @param self Instancia de GPIO cuyo estado de entrada se desea obtener.
 * @return bool El estado del pin (true si está alto, false si está bajo).
 */
bool gpioGetState(gpio_t self) {
    return hal_gpio_get_input(self->port,
                              self->bit); /**< Retorna el estado del pin como entrada. */
}

/* === End of documentation ==================================================================== */
