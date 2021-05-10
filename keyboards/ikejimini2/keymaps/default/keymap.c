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
    _HYPER,
    _FN,
    _L,
    _R,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

#undef F1
#undef F2
#undef F3
#undef F4
#undef F5
#undef F6
#undef F7
#undef F8
#undef F9
#undef F10
#undef F11
#undef F12

#define KC_cA   CTL_T(KC_A)
#define KC_Ah   LT(_HYPER, KC_A)
#define KC__    _______
#define KC_REST RESET
#define KC_Zf   LT(_FN, KC_Z)
#define KC_SLf  LT(_FN, KC_SLSH)
#define KC_cW   LCTL(KC_W)
#define KC_cZ   LCTL(KC_Z)
#define KC_cX   LCTL(KC_X)
#define KC_cC   LCTL(KC_C)
#define KC_cV   LCTL(KC_V)
#define KC_Qg   GUI_T(KC_Q)
#define KC_Pg   GUI_T(KC_P)
#define KC_Xc   CTL_T(KC_X)
#define KC_Ca   ALT_T(KC_C)
#define KC_Vl   LT(_L, KC_V)
#define KC_Bs   SFT_T(KC_B)
#define KC_Ns   SFT_T(KC_N)
#define KC_Mr   LT(_R, KC_M)
#define KC_COMa ALT_T(KC_COMM)
#define KC_DOTc CTL_T(KC_DOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        Qg,  W,   E,   R,   T,   Y,   U,   I,   O,   Pg,
        Ah,  S,   D,   F,   G,   H,   J,   K,   L,   SCLN,
        Zf,  Xc,  Ca,  Vl,  Bs,  Ns,  Mr,  COMa,DOTc,SLf
    ),
    [_HYPER] = LAYOUT(
        _,   cW,  ESC, _,   _,   _,   _,   TAB, _,   _,
        _,   SPC, _,   _,   _,   BSPC,_,   _,   _,   _,
        cZ,  cX,  cC,  cV,  _,   _,   ENT, _,   _,   _
    ),
    [_FN] = LAYOUT(
        F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10,
        F11, F12, HOME,END, _,   LEFT,DOWN,UP,  RGHT,PGUP,
        REST,_,   _,   _,   _,   _,   _,   _,   _,   PGDN
    ),
    [_L] = LAYOUT(
        EXLM,AT,  HASH,DLR, PERC,CIRC,AMPR,ASTR,LPRN,RPRN,
        TILD,_,   _,   _,   _,   _,   UNDS,PLUS,LCBR,RCBR,
        _,   _,   _,   _,   _,   _,   _,   _,   _,   PIPE
    ),
    [_R] = LAYOUT(
        1,   2,   3,   4,   5,   6,   7,   8,   9,   0,
        GRV, _,   _,   _,   _,   _,   MINS,EQL, LBRC,RBRC,
        _,   _,   _,   _,   _,   _,   _,   _,   _,   BSLS
    ),
//    [] = LAYOUT(
//        _,   _,   _,   _,   _,   _,   _,   _,   _,   _,
//        _,   _,   _,   _,   _,   _,   _,   _,   _,   _,
//        _,   _,   _,   _,   _,   _,   _,   _,   _,   _
//    ),
};

