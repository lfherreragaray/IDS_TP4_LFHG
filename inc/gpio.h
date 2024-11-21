/************************************************************************************************
Copyright (c) 2024, Luis Francisco Herrera Garay <lf.herreragaray@gmail.com>

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

#ifndef GPIO_H
#define GPIO_H

/**
 * @file gpio.h
 * @brief Declaración de funciones y tipos de datos para controlar un GPIO (General Purpose
 * Input/Output).
 *
 * Este archivo define una interfaz para la creación y manipulación de pines GPIO en un
 * microcontrolador. Se proporciona funciones para configurar pines como salida, cambiar su estado y
 * obtener su estado.
 */

/* === Inclusión de archivos de cabecera ====================================================== */

#include <stdint.h>
#include <stdbool.h>

/* === Cabecera para C++ ====================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* === Definición de macros públicas ========================================================= */

/* No se definen macros en este archivo */

/* === Declaraciones de tipos de datos públicos ============================================ */

/**
 * @typedef gpio_t
 * @brief Tipo de dato para representar un objeto GPIO.
 *
 * Este tipo es un puntero a una estructura interna que representa el estado y configuración de un
 * GPIO.
 */
typedef struct gpio_s * gpio_t;

/* === Declaraciones de variables públicas =================================================== */

/* No se definen variables globales en este archivo */

/* === Declaraciones de funciones públicas =================================================== */

/**
 * @brief Crea y configura un objeto GPIO.
 *
 * Esta función permite crear un objeto GPIO, especificando el puerto y el bit que se desea
 * controlar.
 *
 * @param port Puerto del microcontrolador al que está conectado el pin.
 * @param bit Bit dentro del puerto que se desea configurar.
 *
 * @return Un puntero a un objeto gpio_t que representa el pin configurado.
 */
gpio_t gpioCreate(uint8_t port, uint8_t bit);

/**
 * @brief Configura un GPIO como salida.
 *
 * Esta función configura un pin GPIO como salida, permitiendo cambiar su estado (alto o bajo).
 *
 * @param gpio Objeto gpio_t que representa el pin a configurar.
 * @param output Valor booleano que indica si el pin debe ser una salida (true) o no (false).
 */
void gpioSetOutput(gpio_t gpio, bool output);

/**
 * @brief Establece el estado de un GPIO.
 *
 * Esta función permite cambiar el estado de un pin GPIO. El estado puede ser alto (true) o bajo
 * (false).
 *
 * @param gpio Objeto gpio_t que representa el pin a configurar.
 * @param state Estado deseado para el pin (true = alto, false = bajo).
 */
void gpioSetState(gpio_t gpio, bool state);

/**
 * @brief Obtiene el estado de un GPIO.
 *
 * Esta función permite leer el estado actual de un pin GPIO. El estado puede ser alto (true) o bajo
 * (false).
 *
 * @param gpio Objeto gpio_t que representa el pin cuyo estado se desea leer.
 *
 * @return El estado actual del pin (true = alto, false = bajo).
 */
bool gpioGetState(gpio_t gpio);

/* === Fin de la documentación ============================================================= */

#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */
