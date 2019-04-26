#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _L 1
#define _R 2
#define _GUI 3
#define _FN 6

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  CANDE ,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______, \
  MO(_FN), KC_LCTL, KC_LALT, KC_LGUI, EANDL,   SANDS,   SANDS,   EANDR,   MO(_GUI),KC_RGUI, KC_RSFT, MO(_FN) \
),

[_L] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______,_______,_______, \
  _______, _______, _______, _______, _______, KC_ENT,  KC_ENT,  _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

[_R] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______, _______, KC_ENT,  KC_ENT,  _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

#define G(kc) LGUI(kc)

[_GUI] =  LAYOUT( \
  _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0), _______, \
  _______, G(KC_Q), G(KC_W), G(KC_E), G(KC_R), _______, _______, _______, _______, _______, _______, _______, \
  _______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

#undef G


[_FN] =  LAYOUT( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  _______, KC_F11,  KC_F12,  _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP, _______, \
  _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  FN_BACK, FN_FORD, KC_PGDN, _______, \
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
