/* Copyright 2019 Shun Ikejima
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
#include "pointing_device.h"

#define _BASE 0
#define _L 1
#define _R 2
#define _GUI 3
#define _FN 6

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  MYKEY = SAFE_RANGE,
  MBTN1,
  MBTN2,
  MBTN3
};

#define CANDE   CTL_T(KC_ESC)
#define AANDT   ALT_T(KC_TAB)
#define SANDE   SFT_T(KC_ENT)
#define SANDS   SFT_T(KC_SPC)
#define FN_BACK LALT(KC_LEFT)
#define FN_FORD LALT(KC_RGHT)
#define FN_BACK LALT(KC_LEFT)
#define FN_FORD LALT(KC_RGHT)
#define EANDL   LT(_L, KC_ENT)
#define EANDR   LT(_R, KC_ENT)
#define EANDG   GUI_T(KC_ENT)
#define EANDLG  LT(_GUI, KC_ENT)
//#define MBTN1   KC_MS_BTN1
//#define MBTN2   KC_MS_BTN2

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  CANDE ,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______, \
  MO(_FN), KC_LCTL, KC_LALT, KC_LGUI, EANDL,   SANDS,   SANDS,   EANDR,   MO(_GUI),KC_RGUI, KC_RSFT, MO(_FN) \
),

[_L] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, _______, _______, _______, _______, _______, MBTN1,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, _______, _______, _______, _______, _______, MBTN2, S(KC_NUHS),S(KC_NUBS),_______,_______,_______, \
  _______, _______, _______, _______, _______, _______, MBTN3,   _______, _______, _______, _______, _______ \
),

[_R] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  _______, _______, _______, _______, _______, _______, MBTN1,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, _______, _______, _______, _______, _______, MBTN2,   KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, MBTN3,   _______, _______, _______, _______, _______ \
),

#define G(kc) LGUI(kc)

[_GUI] =  LAYOUT( \
  _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0), _______, \
  _______, G(KC_Q), G(KC_W), G(KC_E), G(KC_R), _______, KC_INS,  _______, _______, _______, _______, _______, \
  _______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

#undef G


[_FN] =  LAYOUT( \
  RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,  \
  _______, KC_F11,  KC_F12,  _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP, KC_HOME, \
  _______, _______, _______, _______, _______, _______, MBTN1,   MBTN2,   FN_BACK, FN_FORD, KC_PGDN, KC_END, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

};

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case SANDS:
      return 3000;
    case EANDL:
    case EANDR:
      return 100;
    case CANDE:
      return 200;
    default:
      return 500;
  }
}

report_mouse_t currentReport;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MBTN1:
      currentReport = pointing_device_get_report();
      if (record->event.pressed) {
        currentReport.buttons |= MOUSE_BTN1;
      } else {
        currentReport.buttons &= ~MOUSE_BTN1;
      }
      pointing_device_set_report(currentReport);
      return false;
    case MBTN2:
      currentReport = pointing_device_get_report();
      if (record->event.pressed) {
        currentReport.buttons |= MOUSE_BTN2;
      } else {
        currentReport.buttons &= ~MOUSE_BTN2;
      }
      pointing_device_set_report(currentReport);
      return false;
    case MBTN3:
      currentReport = pointing_device_get_report();
      if (record->event.pressed) {
        currentReport.buttons |= MOUSE_BTN3;
      } else {
        currentReport.buttons &= ~MOUSE_BTN3;
      }
      pointing_device_set_report(currentReport);
      return false;
  }
  return true;
}

