/* Copyright 2018 REPLACE_WITH_YOUR_NAME
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

#define _BASE 0
#define _UP 1
#define _DOWN 2
#define _FN 3

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  MYKEY = SAFE_RANGE,
};

#define ALT_M   ALT_T(KC_M)
#define ALT_X   ALT_T(KC_X)
#define ALT_DOT ALT_T(KC_DOT)
#define CTR_ESC CTL_T(KC_ESC)
#define CTR_SLA CTL_T(KC_SLSH)
#define DOWN_B  LT(_DOWN, KC_B)
#define DOWN_V  LT(_DOWN, KC_V)
#define FN_ENT  LT(_FN, KC_ENT)
#define FN_Z    LT(_FN, KC_Z)
#define GUI_C   GUI_T(KC_C)
#define GUI_COM GUI_T(KC_COMM)
#define GUI_N   GUI_T(KC_N)
#define SFT_SPC SFT_T(KC_SPC)
#define UP_B    LT(_UP, KC_B)
#define UP_M    LT(_UP, KC_M)
#define UP_N    LT(_UP, KC_N)
#define UP_V    LT(_UP, KC_V)

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        CTR_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        SFT_SPC, FN_Z,    ALT_X,   GUI_C,   DOWN_V,  DOWN_B,  UP_N,    UP_M,    GUI_COM, ALT_DOT, CTR_SLA, FN_ENT
  ),
  [_UP] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______
  ),
  [_DOWN] = LAYOUT(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_FN] = LAYOUT(
        RESET  , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        _______, KC_F11,  KC_F12,  KC_HOME, KC_END,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP, KC_PGDN,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
//[] = LAYOUT(
//      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
