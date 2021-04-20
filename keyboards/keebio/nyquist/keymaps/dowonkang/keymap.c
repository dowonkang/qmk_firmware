#include "dowonkang.h"

// clang-format off
#define LTH LOW
#define LTL ALT_ESC
#define LTR CTL_TAB
#define RTH RSE
#define RTL CTL_SPC
#define RTR FN_BSPC

// Mod-taps
#define MT_A LSFT_T(KC_A)
#define MT_S LGUI_T(KC_S)
#define MT_D LALT_T(KC_D)
#define MT_F LCTL_T(KC_F)
#define MT_C RALT_T(KC_C)
#define MT_J RCTL_T(KC_J)
#define MT_K LALT_T(KC_K)
#define MT_L RGUI_T(KC_L)
#define MT_SCLN RSFT_T(KC_SCLN)
#define MT_COMM RALT_T(KC_COMM)

#undef  ______BASE_LEFT_2___________
#define ______BASE_LEFT_2___________ MT_A, MT_S, MT_D, MT_F, KC_G
#undef  ______BASE_LEFT_3___________
#define ______BASE_LEFT_3___________ KC_Z, KC_X, MT_C, KC_V, KC_B
#undef  ______BASE_RIGHT_2__________
#define ______BASE_RIGHT_2__________ KC_H, MT_J, MT_K, MT_L, MT_SCLN
#undef  ______BASE_RIGHT_3__________
#define ______BASE_RIGHT_3__________ KC_N, KC_M, MT_COMM, KC_DOT, KC_SLSH
#undef  ______LOWER_LEFT_2__________
#define ______LOWER_LEFT_2__________ KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, KC_GRV
#undef  ______LOWER_LEFT_3__________
#define ______LOWER_LEFT_3__________ KC_CAPS, KC_APP, KC_RALT, XXXX, XXXX
#undef  ______RAISE_LEFT_2__________
#define ______RAISE_LEFT_2__________ ______LOWER_LEFT_2__________
#undef  ______RAISE_LEFT_3__________
#define ______RAISE_LEFT_3__________ ______LOWER_LEFT_3__________
// clang-format on

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_BASE] = LAYOUT_wrapper(
        ______BASE_LEFT_1___________,              ______BASE_RIGHT_1__________,
        ______BASE_LEFT_2___________,              ______BASE_RIGHT_2__________,
        ______BASE_LEFT_3___________,              ______BASE_RIGHT_3__________,
                    LTL , LTH , LTR ,              RTL , RTH , RTR
    ),

    [_LOWER] = LAYOUT_wrapper(
        ______LOWER_LEFT_1__________,              ______LOWER_RIGHT_1_________,
        ______LOWER_LEFT_2__________,              ______LOWER_RIGHT_2_________,
        ______LOWER_LEFT_3__________,              ______LOWER_RIGHT_3_________,
                    XXXX, ____, XXXX,              ____, ____, BSPC
    ),

    [_RAISE] = LAYOUT_wrapper(
        ______RAISE_LEFT_1__________,              ______RAISE_RIGHT_1_________,
        ______RAISE_LEFT_2__________,              ______RAISE_RIGHT_2_________,
        ______RAISE_LEFT_3__________,              ______RAISE_RIGHT_3_________,
                    ____, ____, ____,              XXXX, ____, XXXX
    ),

    [_NUMPAD] = LAYOUT_wrapper(
        ______NUMPAD_LEFT_1_________,              ______NUMPAD_RIGHT_1________,
        ______NUMPAD_LEFT_2_________,              ______NUMPAD_RIGHT_2________,
        ______NUMPAD_LEFT_3_________,              ______NUMPAD_RIGHT_3________,
                    ____, ____, XXXX,              P0  , PDOT, XXXX
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        ______FN_LEFT_1_____________,              ______FN_RIGHT_1____________,
        ______FN_LEFT_2_____________,              ______FN_RIGHT_2____________,
        ______FN_LEFT_3_____________,              ______FN_RIGHT_3____________,
                    ____, ____, ____,              XXXX, XXXX, ____
    ),
    // clang-format on
};

