#include QMK_KEYBOARD_H

#define _BASE 0
#define _L 1
#define _R 2
#define _GUI 3
#define _FN 4
#define _MOUSE 5
#define _EMPTY 6
#define _DVTM 7

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    MYKEY = SAFE_RANGE,
    MACRO1,
    MACRO2,
    MACRO3,
    MACRO4,
    MACRO5,
};

#define CANDE CTL_T(KC_ESC)
#define AANDT ALT_T(KC_TAB)
#define SANDE SFT_T(KC_ENT)
#define SANDS SFT_T(KC_SPC)
#define FN_BACK LALT(KC_LEFT)
#define FN_FORD LALT(KC_RGHT)
#define FN_BACK LALT(KC_LEFT)
#define FN_FORD LALT(KC_RGHT)
#define EANDL LT(_L, KC_ENT)
#define BANDL LT(_L, KC_BSPC)
#define EANDR LT(_R, KC_ENT)
#define TANDD LT(_DVTM, KC_TAB)
#define EANDG GUI_T(KC_ENT)
#define EANDLG LT(_GUI, KC_ENT)
#define MBTN1 KC_MS_BTN1
#define MBTN2 KC_MS_BTN2
#define MBTN3 KC_MS_BTN3
#define SINS S(KC_INSERT)
#define SPSCR S(KC_PRINT_SCREEN)
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
[_BASE] = LAYOUT( \
  TANDD   , KC_Q    , KC_W    , KC_E  , KC_R  , KC_T    , KC_Y     , KC_U  , KC_I    , KC_O    , KC_P    , KC_BSPC   , \
  CANDE   , KC_A    , KC_S    , KC_D  , KC_F  , KC_G    , KC_H     , KC_J  , KC_K    , KC_L    , KC_SCLN , KC_QUOT   , \
  KC_LSFT , KC_Z    , KC_X    , KC_C  , KC_V  , KC_B    , KC_N     , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT    , \
  MO(_FN) , KC_LALT , KC_LCTL , BANDL , SANDS , KC_LGUI , MO(_GUI) , SANDS , EANDR   , KC_RGUI , KC_RALT , MO(_FN) \
)         ,

[_L] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, _______, _______, _______, _______, _______, _______,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, _______, _______, _______, _______, _______, _______, S(KC_NUHS),S(KC_NUBS),_______,_______,_______, \
  _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______ \
),

[_R] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  _______, _______, _______, _______, _______, _______, _______,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, _______, _______, _______, _______, _______, _______,   KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______ \
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
  QK_BOOT,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,  \
  _______, KC_F11,  KC_F12,  _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP, KC_HOME, \
  _______, MACRO1,  MACRO2,  MACRO3,  MACRO4,  MACRO5,  SINS,    SPSCR,   FN_BACK, FN_FORD, KC_PGDN, KC_END, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),
[_MOUSE] =  LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, MBTN1,   MBTN2,   MBTN3,   _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),
[_DVTM] =  LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),
[_EMPTY] =  LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),
    // clang-format on

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (IS_LAYER_ON(_DVTM) && record->event.pressed) {
        register_code(KC_LCTL);
        tap_code(KC_G);
        unregister_code(KC_LCTL);
    }
    switch (keycode) {
        case MACRO1:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_LALT);
                tap_code(KC_1);
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
            }
            break;
        case MACRO2:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_LALT);
                tap_code(KC_2);
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
            }
            break;
        case MACRO3:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_LALT);
                tap_code(KC_3);
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
            }
            break;
        case MACRO4:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_LALT);
                tap_code(KC_4);
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
            }
            break;
        case MACRO5:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_LALT);
                tap_code(KC_5);
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
            }
            break;
    }
    return true;
}

// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case SANDS:
//       return 3000;
//     case EANDL:
//     case EANDR:
//       return 100;
//     case CANDE:
//       return 200;
//     default:
//       return 500;
//   }
// }

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable = true;
    // debug_matrix=true;
    // debug_keyboard=true;
    debug_mouse = true;
    // pointing_device_set_cpi_on_side(true, 1000); //Set cpi on left side to a low value for slower scrolling.
    // pointing_device_set_cpi_on_side(false, 8000); //Set cpi on right side to a reasonable value for mousing.
    set_auto_mouse_layer(_MOUSE); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);  // always required before the auto mouse feature will work
}
int8_t cap1(int8_t in, int16_t *p) {
    const int8_t CAP = 50;
    *p += in;
    if (*p > CAP) {
        *p -= CAP;
        return 1;
    }
    if (*p < -CAP) {
        *p += CAP;
        return -1;
    }
    return 0;
    // return in == 0 ? 0 : (in < 0 ? -1 : 1);
}
report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    static int16_t hp = 0, yp = 0;
    left_report.h = cap1(left_report.x, &hp);
    left_report.v = cap1(left_report.y, &yp);
    left_report.x = 0;
    left_report.y = 0;

    if (!get_auto_mouse_toggle()) {
        if (-10 < right_report.x && right_report.x < 10 && -10 < right_report.y && right_report.y < 10) {
            right_report.x = 0;
            right_report.y = 0;
        }
    }
    if (layer_state_is(_L) || layer_state_is(_R)) {
        right_report.x /= 10;
        right_report.y /= 10;
    }
    return pointing_device_combine_reports(left_report, right_report);
}

const uint16_t PROGMEM test_combo1[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM test_combo3[] = {KC_F, KC_G, COMBO_END};
combo_t                key_combos[]  = {
    COMBO(test_combo1, MBTN1),
    COMBO(test_combo2, MBTN2),
};
