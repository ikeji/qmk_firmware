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
#define _L 1
#define _R 2
#define _GUI 3
#define _FN 6

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define CANDE   CTL_T(KC_ESC)
#define FN_BACK LALT(KC_LEFT)
#define FN_FORD LALT(KC_RGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
  KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T                     ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSPC, \
  CANDE  ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G                     ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT, \
  KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B                     ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_ENT , \
                  XXXXXXX,XXXXXXX,XXXXXXX,                                  XXXXXXX,XXXXXXX,XXXXXXX,                 \
                          XXXXXXX,                                                  XXXXXXX,                         \
                                     KC_LCTL, KC_LALT,         KC_RALT,KC_RCTL,                                      \
                                  MO(_L) ,KC_SPC ,KC_LGUI,  MO(_GUI),KC_SPC ,MO(_R) ,                                 \
                          XXXXXXX,   MO(_FN), XXXXXXX,         XXXXXXX,MO(_FN),     XXXXXXX                          \

  ),
[_L] = LAYOUT(
  KC_TILD,KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC                  ,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,_______, \
  _______,_______,_______,_______,_______,_______                  ,_______,KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR,KC_PIPE, \
  _______,_______,_______,_______,_______,_______                  ,_______,_______,_______,_______,_______,_______, \
                  _______,_______,_______,                                  _______,_______,_______,                 \
                          _______,                                                  _______,                         \
                                     _______, _______,         _______,_______,                                      \
                                  _______,_______,_______,  _______,_______,_______,                                 \
                          _______,   _______, _______,         _______,_______,     _______                          \

  ),
[_R] = LAYOUT(
  KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5                     ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,_______, \
  _______,_______,_______,_______,_______,_______                  ,_______,KC_MINS,KC_EQL ,KC_LBRC,KC_RBRC,KC_BSLS, \
  _______,_______,_______,_______,_______,_______                  ,_______,_______,_______,_______,_______,_______, \
                  _______,_______,_______,                                  _______,_______,_______,                 \
                          _______,                                                  _______,                         \
                                     _______, _______,         _______,_______,                                      \
                                  _______,_______,_______,  _______,_______,_______,                                 \
                          _______,   _______, _______,         _______,_______,     _______                          \

  ),
#define G(kc) LGUI(kc)

[_GUI] = LAYOUT(
  _______,G(KC_1),G(KC_2),G(KC_3),G(KC_4),G(KC_5)                  ,G(KC_6),G(KC_7),G(KC_8),G(KC_9),G(KC_0),_______, \
  _______,G(KC_Q),G(KC_W),G(KC_E),G(KC_R),_______                  ,_______,_______,_______,_______,_______,_______, \
  _______,G(KC_Z),G(KC_X),G(KC_C),G(KC_V),_______                  ,_______,_______,_______,_______,_______,_______, \
                  _______,_______,_______,                                  _______,_______,_______,                 \
                          _______,                                                  _______,                         \
                                     _______, _______,         _______,_______,                                      \
                                  _______,_______,_______,  _______,_______,_______,                                 \
                          _______,   _______, _______,         _______,_______,     _______                          \

  ),
#undef G
[_FN] = LAYOUT(
  _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5                    ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,_______, \
  _______,KC_F11 ,KC_F12 ,_______,_______,_______                  ,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_PGUP,_______, \
  _______,_______,_______,_______,_______,_______                  ,KC_HOME,KC_END ,FN_BACK,FN_FORD,KC_PGDN,_______, \
                  _______,_______,_______,                                  _______,_______,_______,                 \
                          _______,                                                  _______,                         \
                                     _______, _______,         _______,_______,                                      \
                                  _______,_______,_______,  _______,_______,_______,                                 \
                          _______,   _______, _______,         _______,_______,     _______                          \

  ),
/*
[_] = LAYOUT(
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX                  ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, \
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX                  ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, \
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX                  ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, \
                  XXXXXXX,XXXXXXX,XXXXXXX,                                  XXXXXXX,XXXXXXX,XXXXXXX,                 \
                          XXXXXXX,                                                  XXXXXXX,                         \
                                     XXXXXXX, XXXXXXX,         XXXXXXX,XXXXXXX,                                      \
                                  XXXXXXX,XXXXXXX,XXXXXXX,  XXXXXXX,XXXXXXX,XXXXXXX,                                 \
                          XXXXXXX,   XXXXXXX, XXXXXXX,         XXXXXXX,XXXXXXX,     XXXXXXX                          \

  ),
[_] = LAYOUT(
  _______,_______,_______,_______,_______,_______                  ,_______,_______,_______,_______,_______,_______, \
  _______,_______,_______,_______,_______,_______                  ,_______,_______,_______,_______,_______,_______, \
  _______,_______,_______,_______,_______,_______                  ,_______,_______,_______,_______,_______,_______, \
                  _______,_______,_______,                                  _______,_______,_______,                 \
                          _______,                                                  _______,                         \
                                     _______, _______,         _______,_______,                                      \
                                  _______,_______,_______,  _______,_______,_______,                                 \
                          _______,   _______, _______,         _______,_______,     _______                          \

  ),
*/
};

