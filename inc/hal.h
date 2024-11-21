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

#ifndef HAL_H
#define HAL_H

/**
 * @file hal.h
 * @brief Declaración de funciones para manejar la configuración y control de pines GPIO a través
 *        de una capa de abstracción de hardware (HAL).
 *
 * Este archivo contiene funciones para configurar la dirección de los pines GPIO, establecer su
 * salida, y leer su estado. Está diseñado para ser utilizado en un nivel de abstracción sobre el
 * hardware específico.
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

/* No se definen tipos de datos en este archivo */

/* === Declaraciones de variables públicas =================================================== */

/* No se definen variables globales en este archivo */

/* === Declaraciones de funciones públicas =================================================== */

/**
 * @brief Configura la dirección de un pin GPIO.
 *
 * Esta función configura un pin GPIO como entrada o salida según el parámetro `output`.
 *
 * @param port El puerto del microcontrolador al que está conectado el pin.
 * @param bit El bit dentro del puerto que se desea configurar.
 * @param output Valor booleano que indica si el pin debe ser configurado como salida (true) o
 * entrada (false).
 */
void hal_gpio_set_direction(uint8_t port, uint8_t bit, bool output);

/**
 * @brief Establece el estado de un pin GPIO configurado como salida.
 *
 * Esta función configura el estado de un pin GPIO que está configurado como salida. El pin puede
 * ser activado (alto) o desactivado (bajo).
 *
 * @param port El puerto del microcontrolador al que está conectado el pin.
 * @param bit El bit dentro del puerto que se desea configurar.
 * @param active Valor booleano que indica si el pin debe ser activado (true) o desactivado (false).
 */
void hal_gpio_set_output(uint8_t port, uint8_t bit, bool active);

/**
 * @brief Lee el estado de un pin GPIO configurado como entrada.
 *
 * Esta función lee el estado de un pin GPIO que ha sido configurado como entrada.
 *
 * @param port El puerto del microcontrolador al que está conectado el pin.
 * @param bit El bit dentro del puerto que se desea leer.
 *
 * @return El estado actual del pin (true = alto, false = bajo).
 */
bool hal_gpio_get_input(uint8_t port, uint8_t bit);

/* === Fin de la documentación ============================================================= */

#ifdef __cplusplus
}
#endif

#endif /* HAL_H */
