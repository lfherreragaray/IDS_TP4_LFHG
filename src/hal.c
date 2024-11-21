/************************************************************************************************
 * Copyright (c) 2024, Luis Francisco Herrera Garay<lf.herreragaray@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 * associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
 * NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 *DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT
 *OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * SPDX-License-Identifier: MIT
 ************************************************************************************************/
/**
 * @file hal.c
 * @brief Implementación de funciones HAL para el control de GPIO.
 *
 * Este archivo contiene las implementaciones de las funciones principales para configurar y
 * manipular pines GPIO en una plataforma embebida. Las funciones permiten configurar la dirección
 * de los pines (entrada/salida), establecer el valor de salida de los pines y leer los valores de
 * los pines configurados como entrada.
 *
 * @note Las funciones definidas aquí aún no están implementadas. Se espera que se implementen en
 * función del hardware específico.
 */

/* === Headers files inclusions =============================================================== */
#include "hal.h"

/* === Macros definitions ====================================================================== */
/**
 * @defgroup HAL_MACROS Macros de HAL
 * @{
 * Aquí se pueden definir macros útiles para la manipulación de GPIOs u otros componentes de
 * hardware.
 */

/** @} */ // end of HAL_MACROS

/* === Private data type declarations ========================================================== */
/**
 * @defgroup HAL_TYPES Tipos de datos privados
 * @{
 * Aquí se pueden declarar tipos de datos específicos utilizados solo dentro de este archivo.
 */

/** @} */ // end of HAL_TYPES

/* === Private variable declarations =========================================================== */
/**
 * @defgroup HAL_PRIVATE_VARIABLES Variables privadas
 * @{
 * Aquí se pueden declarar las variables privadas utilizadas en este archivo.
 */

/** @} */ // end of HAL_PRIVATE_VARIABLES

/* === Private function declarations =========================================================== */
/**
 * @defgroup HAL_PRIVATE_FUNCTIONS Funciones privadas
 * @{
 * Aquí se pueden declarar funciones que solo serán utilizadas dentro de este archivo.
 */

/** @} */ // end of HAL_PRIVATE_FUNCTIONS

/* === Public function implementation ========================================================== */

/**
 * @brief Configura la dirección (entrada o salida) de un pin GPIO.
 *
 * Esta función permite configurar un pin GPIO como entrada o salida.
 *
 * @param port El número del puerto GPIO (por ejemplo, puerto A, B, etc.).
 * @param bit El número del pin dentro del puerto (por ejemplo, pin 0, 1, etc.).
 * @param output Valor booleano que indica si el pin se configura como salida (true) o como entrada
 * (false).
 */
void hal_gpio_set_direction(uint8_t port, uint8_t bit, bool output) {
    // Implementación pendiente
}

/**
 * @brief Establece el valor de salida de un pin GPIO.
 *
 * Esta función permite configurar el valor de un pin GPIO que está configurado como salida.
 *
 * @param port El número del puerto GPIO (por ejemplo, puerto A, B, etc.).
 * @param bit El número del pin dentro del puerto (por ejemplo, pin 0, 1, etc.).
 * @param active El valor a establecer en el pin: `true` para alto (1) y `false` para bajo (0).
 */
void hal_gpio_set_output(uint8_t port, uint8_t bit, bool active) {
    // Implementación pendiente
}

/**
 * @brief Lee el valor de entrada de un pin GPIO.
 *
 * Esta función permite leer el valor de un pin GPIO configurado como entrada.
 *
 * @param port El número del puerto GPIO (por ejemplo, puerto A, B, etc.).
 * @param bit El número del pin dentro del puerto (por ejemplo, pin 0, 1, etc.).
 *
 * @return El valor del pin: `true` si está alto, `false` si está bajo.
 */
bool hal_gpio_get_input(uint8_t port, uint8_t bit) {
    // Implementación pendiente
}

/* === End of documentation ==================================================================== */
