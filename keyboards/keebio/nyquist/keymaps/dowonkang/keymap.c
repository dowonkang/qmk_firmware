#include "dowonkang.h"

#define LTH LOW
// #define LTL NUM_TAB
#define LTL ALT_DEL
#define LTR CTL_ESC
#define RTH RSE_ENT
#define RTL SFT_SPC
#define RTR FN_BSPC

#undef ______BASE_LEFT_2___________
#define ______BASE_LEFT_2___________ ______QWERTY_LEFT2__________
#undef ______BASE_LEFT_3___________
#define ______BASE_LEFT_3___________ ______QWERTY_LEFT3__________
#undef ______BASE_RIGHT_2__________
#define ______BASE_RIGHT_2__________ ______QWERTY_RIGHT2_________
#undef ______BASE_RIGHT_3__________
#define ______BASE_RIGHT_3__________ ______QWERTY_RIGHT3_________

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

// Combo
enum combos {
    // clang-format off
    CB_TAB,
    CB_GRV,
    CB_LSFT,
    CB_LCTL,
    CB_LALT,
    CB_LGUI,
    CB_RSFT,
    CB_RCTL,
    CB_RALT,
    CB_RGUI,
    CB_HAEN
    // clang-format on
};

const uint16_t PROGMEM tab_combo[]  = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM grv_combo[]  = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM lsft_combo[] = {KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM lctl_combo[] = {KC_F, KC_V, COMBO_END};
const uint16_t PROGMEM lalt_combo[] = {KC_S, KC_X, COMBO_END};
const uint16_t PROGMEM lgui_combo[] = {KC_A, KC_Z, COMBO_END};
const uint16_t PROGMEM rsft_combo[] = {KC_K, KC_COMMA, COMBO_END};
const uint16_t PROGMEM rctl_combo[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM ralt_combo[] = {KC_L, KC_DOT, COMBO_END};
const uint16_t PROGMEM rgui_combo[] = {KC_SCOLON, KC_SLASH, COMBO_END};
const uint16_t PROGMEM haen_combo[] = {KC_H, KC_N, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    // clang-format off
    [CB_TAB] = COMBO(tab_combo, KC_TAB),
    [CB_GRV] = COMBO(grv_combo, KC_GRV),
    [CB_LSFT] = COMBO(lsft_combo, KC_LSHIFT),
    [CB_LCTL] = COMBO(lctl_combo, KC_LCTRL),
    [CB_LALT] = COMBO(lalt_combo, KC_LALT),
    [CB_LGUI] = COMBO(lgui_combo, KC_LGUI),
    [CB_RSFT] = COMBO(rsft_combo, KC_RSHIFT),
    [CB_RCTL] = COMBO(rctl_combo, KC_RCTRL),
    [CB_RALT] = COMBO(ralt_combo, KC_LALT),
    [CB_RGUI] = COMBO(rgui_combo, KC_LGUI),
    [CB_HAEN] = COMBO(haen_combo, KC_HAEN),
    // clang-format on
};
