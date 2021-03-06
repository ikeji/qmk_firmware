/* Copyright 2021 Shun Ikejima
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _TEN,
    _TEN2,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL,
    ZZ
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_C, KC_D, KC_E, KC_F,
        KC_8, KC_9, KC_A, KC_B,
        KC_4, KC_5, KC_6, KC_7,
        KC_0, KC_1, KC_2, KC_3
    ),
    [_TEN] = LAYOUT(
        KC_P7, KC_P8, KC_P9,   KC_NLCK,
        KC_P4, KC_P5, KC_P6,   KC_BSPC,
        KC_P1, KC_P2, KC_P3,   KC_TAB,
        KC_P0, ZZ,    KC_PDOT, KC_PENT
    ),
    [_TEN2] = LAYOUT(
        KC_7, KC_8, KC_9,    KC_NO,
        KC_4, KC_5, KC_6,    KC_BSPC,
        KC_1, KC_2, KC_3,    KC_TAB,
        KC_0, ZZ,   KC_DOT, KC_PENT
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}
