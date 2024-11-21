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
 * @file main.c
 * @brief Definición de la función principal del programa
 *
 * Este archivo contiene la implementación de la función principal del programa, que configura y
 * controla un LED rojo utilizando un puerto GPIO.
 *
 * @author Luis Francisco Herrera Garay
 * @date 2024
 */

/* === Headers files inclusions =============================================================== */
#include "main.h" /**< Archivo de cabecera para la definición de funciones principales. */
#include "gpio.h" /**< Archivo de cabecera para la configuración y manejo de pines GPIO. */

/* === Macros definitions ====================================================================== */
#define LED_RED_BIT  7 /**< Número de bit del LED rojo en el puerto GPIO. */
#define LED_RED_PORT 1 /**< Puerto donde está conectado el LED rojo. */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

/**
 * @brief Función principal del programa.
 *
 * Esta es la función principal que se ejecuta al iniciar el programa. Su propósito es configurar un
 * puerto GPIO para controlar un LED rojo, configurándolo como salida y apagándolo al inicio.
 *
 * @return int Retorna 0 para indicar que el programa finalizó correctamente.
 */
int main(void) {
    gpio_t red_led = gpioCreate(LED_RED_PORT, LED_RED_BIT); /**< Crea el objeto para el LED rojo. */
    gpioSetOutput(red_led, true);                           /**< Configura el pin como salida. */
    gpioSetState(red_led, false); /**< Establece el estado del LED rojo en apagado. */

    return 0; /**< Finaliza la ejecución del programa. */
}

/* === End of documentation ==================================================================== */
