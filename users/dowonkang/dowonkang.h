#pragma once

#include QMK_KEYBOARD_H

// This should be already included in QMK_KEYBOARD_H.
// But VS Code doesn't handle it very well.
// Including it again provides way better IntelliSense experience.
#include "quantum.h"

enum userspace_layers {
    // clang-format off
    _BASE,
    _LOWER,
    _RAISE,
    _NUMPAD,
    _FUNCTION,
    _FN_ONEHAND,
    _MOUSE,
    _GAME,
    _GAMEXTRA,
    _ADJUST,
    // clang-format on
};

enum userspace_keycodes {
    // clang-format off
    LAYER_LOCK = SAFE_RANGE,
    LAYER_CLEAR,
    NEW_SAFE_RANGE
    // clang-format on
};

// Tap dance
#ifdef TAP_DANCE_ENABLE
typedef struct {
    // clang-format off
    bool is_press_action;
    uint8_t state;
    // clang-format on
} tap;

enum {
    // clang-format off
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD
    // clang-format on
};

uint8_t cur_dance(qk_tap_dance_state_t *state);
#endif

// clang-format off
// Layers
#define LOW     MO(_LOWER)
#define RSE     MO(_RAISE)
#define NUM     MO(_NUMPAD)
#define FN      MO(_FUNCTION)
#define MOUS    MO(_MOUSE)
#define ADJ     MO(_ADJUST)
#define GAME    TO(_GAME)
#define GEXT    MO(_GAMEXTRA)

// Layer-tap
#define NUM_ESC LT(_NUMPAD, KC_ESCAPE)
#define LT_Q    LT(_FUNCTION, KC_Q)
#define LT_A    LT(_NUMPAD, KC_A)
#define LT_SCLN LT(_MOUSE, KC_SCLN)
#define LT_ENT  LT(_MOUSE, KC_ENT)
#define LT_MENU LT(_FUNCTION, KC_APP)

// Mod-tap keys
#define MT_SPC  LCTL_T(KC_SPACE)
#define MT_ESC  LALT_T(KC_ESCAPE)
#define MT_TAB  LCTL_T(KC_TAB)
#define MT_BSPC LGUI_T(KC_BSPACE)
#define MT_A    LSFT_T(KC_A)
#define MT_S    LGUI_T(KC_S)
#define MT_D    LALT_T(KC_D)
#define MT_F    LCTL_T(KC_F)
#define MT_Z    LSFT_T(KC_Z)
#define MT_C    RALT_T(KC_C)
#define MT_V    HYPR_T(KC_V)
#define MT_J    RCTL_T(KC_J)
#define MT_K    LALT_T(KC_K)
#define MT_L    RGUI_T(KC_L)
#define MT_SCLN RSFT_T(KC_SCLN)
#define MT_M    HYPR_T(KC_M)
#define MT_COMM RALT_T(KC_COMM)
#define MT_SLSH RSFT_T(KC_SLASH)
#define MT_MINS RCTL_T(KC_MINS)
#define MT_LBRC LALT_T(KC_LBRC)
#define MT_RBRC RGUI_T(KC_RBRC)
#define MT_EQL  HYPR_T(KC_EQL)
#define MT_CAPS LSFT_T(KC_CAPSLOCK)

// Ctrl Combos
#define CTRL_A  LCTL(KC_A)
#define CTRL_S  LCTL(KC_S)
#define CTRL_D  LCTL(KC_D)
#define CTRL_F  LCTL(KC_F)
#define CTRL_G  LCTL(KC_G)
#define CTRL_Z  LCTL(KC_Z)
#define CTRL_X  LCTL(KC_X)
#define CTRL_C  LCTL(KC_C)
#define CTRL_V  LCTL(KC_V)
#define CTRL_B  LCTL(KC_B)

// Less than 4-letter shortcuts
#define ____    KC_TRANSPARENT
#define XXXX    KC_NO
#define RSET    RESET

#define SPC     KC_SPACE
#define BSPC    KC_BSPACE
#define ENT     KC_ENTER
#define ESC     KC_ESCAPE
#define TAB     KC_TAB
#define DEL     KC_DELETE
#define INS     KC_INSERT
#define MENU    KC_APP
#define PSCR    KC_PSCR
#define SLCK    KC_SLCK
#define PAUS    KC_PAUS

// Modifiers
#define CTRL    KC_LCTL
#define ALT     KC_LALT
#define SFTL    KC_LSFT
#define SFTR    KC_RSFT
#define ALTG    KC_RALT
#define GUI     KC_LGUI
#define CTLR    KC_RCTL
#define GUIR    KC_RGUI

// Numpad
#define P0      KC_P0
#define PDOT    KC_PDOT
#define PENT    KC_PENT

// Movements
#define UARR    KC_UP
#define DARR    KC_DOWN
#define LARR    KC_LEFT
#define RARR    KC_RIGHT
#define HOME    KC_HOME
#define END     KC_END
#define PGUP    KC_PGUP
#define PGDN    KC_PGDN

// Web navigations
#define WBCK    LALT(KC_LEFT)
#define WFWD    LALT(KC_RIGHT)
#define WREF    LCTL(KC_R)
#define WTOP    KC_HOME
#define WBTM    KC_END

// Media
#define VOLU    KC_VOLU
#define VOLD    KC_VOLD
#define MUTE    KC_MUTE
#define MPRV    KC_MPRV
#define MPLY    KC_MPLY
#define MNXT    KC_MNXT

// Mouse
#define BTN1    KC_MS_BTN1
#define BTN2    KC_MS_BTN2
#define BTN3    KC_MS_BTN3
#define ACL0    KC_ACL0
#define ACL1    KC_ACL1
#define ACL2    KC_ACL2

// Etc.
#define GRV     KC_GRAVE
#define CAPS    KC_CAPSLOCK

// XXXXXXX
#define XXXXXXXXXXXXXXXXXXXXXXXXXXXX XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

// _______
#define ____________________________ _______, _______, _______, _______, _______

// Number row
     // XXXX, XXXX, XXXX, XXXX, XXXX
#define ______NUMBER_12345__________ KC_1   , KC_2   , KC_3   , KC_4   , KC_5
#define ______NUMBER_67890__________ KC_6   , KC_7   , KC_8   , KC_9   , KC_0
#define ______SHIFTED_12345_________ KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC
#define ______SHIFTED_67890_________ KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN

// QWERTY
#define ______QWERTY_LEFT_1_________ KC_Q   , KC_W   , KC_E   , KC_R   , KC_T
#define ______QWERTY_LEFT_2_________ KC_A   , KC_S   , KC_D   , KC_F   , KC_G
#define ______QWERTY_LEFT_3_________ KC_Z   , KC_X   , KC_C   , KC_V   , KC_B
#define ______QWERTY_RIGHT_1________ KC_Y   , KC_U   , KC_I   , KC_O   , KC_P
#define ______QWERTY_RIGHT_2________ KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN
#define ______QWERTY_RIGHT_3________ KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH

// Fn row
     // XXXX, XXXX, XXXX, XXXX, XXXX, XXXX
#define ______F_ROW_1_________       KC_F1  , KC_F2  , KC_F3  , KC_F4
#define ______F_ROW_2_________       KC_F5  , KC_F6  , KC_F7  , KC_F8
#define ______F_ROW_3_________       KC_F9  , KC_F10 , KC_F11 , KC_F12
#define ______F_12345_______________ KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5
#define ______F_678910______________ KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10
#define ______F_123456____________________ KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6
#define ______F_789101112_________________ KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12

// Base
#ifdef HOME_ROW_MODS
#   ifdef FIVE_COLS_PER_HAND
#       define ______BASE_LEFT_1___________ LT_Q   , KC_W   , KC_E   , KC_R   , KC_T
#       define ______BASE_LEFT_2___________ LT_A   , MT_S   , MT_D   , MT_F   , KC_G
#       define ______BASE_LEFT_3___________ MT_Z   , KC_X   , MT_C   , MT_V   , KC_B
#       define ______BASE_RIGHT_1__________ ______QWERTY_RIGHT_1________
#       define ______BASE_RIGHT_2__________ KC_H   , MT_J   , MT_K   , MT_L   , LT_ENT
#       define ______BASE_RIGHT_3__________ KC_N   , MT_M   , MT_COMM, KC_DOT , MT_SLSH
#   else
#       define ______BASE_LEFT_1___________ KC_Q   , KC_W   , KC_E   , KC_R   , KC_T
#       define ______BASE_LEFT_2___________ KC_A   , MT_S   , MT_D   , MT_F   , KC_G
#       define ______BASE_LEFT_3___________ KC_Z   , KC_X   , MT_C   , MT_V   , KC_B
#       define ______BASE_RIGHT_1__________ ______QWERTY_RIGHT_1________
#       define ______BASE_RIGHT_2__________ KC_H   , MT_J   , MT_K   , MT_L   , KC_SCLN
#       define ______BASE_RIGHT_3__________ KC_N   , MT_M   , MT_COMM, KC_DOT , MT_SLSH
#   endif
#else
#   define ______BASE_LEFT_1___________ ______QWERTY_LEFT_1_________
#   define ______BASE_LEFT_2___________ ______QWERTY_LEFT_2_________
#   define ______BASE_LEFT_3___________ ______QWERTY_LEFT_3_________
#   define ______BASE_RIGHT_1__________ ______QWERTY_RIGHT_1________
#   define ______BASE_RIGHT_2__________ KC_H   , KC_J   , KC_K   , KC_L   , LT_SCLN
#   define ______BASE_RIGHT_3__________ ______QWERTY_RIGHT_3________
#endif

// Lower
#ifdef HOME_ROW_MODS
#   ifdef FIVE_COLS_PER_HAND
#       define ______LOWER_LEFT_1__________ ______NUMBER_12345__________
#       define ______LOWER_LEFT_2__________ KC_ESC, KC_LGUI, KC_LALT, KC_LCTL, KC_GRV
#       define ______LOWER_LEFT_3__________ KC_LSFT, KC_APP , KC_RALT, KC_HYPR, _______
#       define ______LOWER_RIGHT_1_________ ______NUMBER_67890__________
#       define ______LOWER_RIGHT_2_________ KC_QUOT, MT_MINS, MT_LBRC, MT_RBRC, KC_SCLN
#       define ______LOWER_RIGHT_3_________ KC_BSLS, MT_EQL , _______, _______, _______
#   else
#       define ______LOWER_LEFT_1__________ ______NUMBER_12345__________
#       define ______LOWER_LEFT_2__________ _______, KC_LGUI, KC_LALT, KC_LCTL, _______
#       define ______LOWER_LEFT_3__________ _______, KC_APP , KC_RALT, KC_HYPR, _______
#       define ______LOWER_RIGHT_1_________ ______NUMBER_67890__________
#       define ______LOWER_RIGHT_2_________ KC_QUOT, MT_MINS, MT_LBRC, MT_RBRC, KC_SCLN
#       define ______LOWER_RIGHT_3_________ KC_BSLS, MT_EQL , _______, _______, _______
#   endif
#else
#   define ______LOWER_LEFT_1__________ ______NUMBER_12345__________
#   define ______LOWER_LEFT_2__________ CTRL_A , CTRL_S , CTRL_D , CTRL_F , CTRL_G
#   define ______LOWER_LEFT_3__________ CTRL_Z , CTRL_X , CTRL_C , CTRL_V , CTRL_B
#   define ______LOWER_RIGHT_1_________ ______NUMBER_67890__________
#   define ______LOWER_RIGHT_2_________ KC_QUOT, KC_MINS, KC_LBRC, KC_RBRC, _______
#   define ______LOWER_RIGHT_3_________ KC_BSLS, KC_EQL , _______, _______, _______
#endif

// Raise
#define ______RAISE_LEFT_1__________ ______LOWER_LEFT_1__________
#define ______RAISE_LEFT_2__________ ______LOWER_LEFT_2__________
#define ______RAISE_LEFT_3__________ ______LOWER_LEFT_3__________

#ifdef FIVE_COLS_PER_HAND
#    define ______RAISE_RIGHT_1_________ KC_PSCR, XXXXXXX, KC_INS , KC_DEL , KC_BSPC
#    define ______RAISE_RIGHT_2_________ KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_ENT
#    define ______RAISE_RIGHT_3_________ KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_RSFT
#else
#    define ______RAISE_RIGHT_1_________ ______LOWER_RIGHT_1_________
#    define ______RAISE_RIGHT_2_________ KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______
#    define ______RAISE_RIGHT_3_________ KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______
#endif

// Numpad
#ifdef FIVE_COLS_PER_HAND
#    define ______NUMPAD_LEFT_1_________ KC_TAB , WBCK   , KC_UP  , WFWD   , WTOP
#    define ______NUMPAD_LEFT_2_________ KC_ESC , KC_LEFT, KC_DOWN, KC_RGHT, WBTM
#    define ______NUMPAD_LEFT_3_________ KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, KC_SPC
#else
#    define ______NUMPAD_LEFT_1_________ WBCK   , KC_UP  , WFWD   , WTOP   , KC_VOLU
#    define ______NUMPAD_LEFT_2_________ KC_LEFT, KC_DOWN, KC_RGHT, WBTM   , KC_VOLD
#    define ______NUMPAD_LEFT_3_________ KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, KC_MUTE
#endif

#define ______NUMPAD_RIGHT_1________ KC_NLCK, KC_P7  , KC_P8  , KC_P9  , KC_PMNS
#define ______NUMPAD_RIGHT_2________ KC_PAST, KC_P4  , KC_P5  , KC_P6  , KC_PPLS
#define ______NUMPAD_RIGHT_3________ KC_PSLS, KC_P1  , KC_P2  , KC_P3  , KC_PEQL

// Function
#ifdef FIVE_COLS_PER_HAND
#    define ______FN_LEFT_1_____________ RESET  , KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU
#    define ______FN_LEFT_2_____________ KC_ESC , KC_LGUI, KC_LALT, KC_LCTL, KC_VOLD
#    define ______FN_LEFT_3_____________ KC_LSFT, KC_APP , KC_RALT, KC_HYPR, KC_MUTE
#else
#    define ______FN_LEFT_1_____________ KC_F1  , KC_F2  , KC_F3  , KC_F4 , KC_VOLU
#    define ______FN_LEFT_2_____________ KC_F5  , KC_F6  , KC_F7  , KC_F8 , KC_VOLD
#    define ______FN_LEFT_3_____________ KC_F9  , KC_F10 , KC_F11 , KC_F12, KC_MUTE
#endif
#define ______FN_RIGHT_1____________ KC_PSCR, KC_F1  , KC_F2  , KC_F3  , KC_F4
#define ______FN_RIGHT_2____________ KC_SLCK, KC_F5  , KC_F6  , KC_F7  , KC_F8
#define ______FN_RIGHT_3____________ KC_PAUS, KC_F9  , KC_F10 , KC_F11 , KC_F12

// Mouse
#define ______MOUSE_VI_CURSOR_______ KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX
#define ______MOUSE_VI_WHEEL________ KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX
#define ______MOUSE_CURSOR_1________ XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX
#define ______MOUSE_CURSOR_2________ XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX
#ifdef FIVE_COLS_PER_HAND
#    define ______MOUSE_WHEEL_1_________ KC_TAB , WBCK   , KC_WH_U, WFWD   , KC_HOME
#    define ______MOUSE_WHEEL_2_________ KC_ESC , KC_WH_L, KC_WH_D, KC_WH_R, KC_END
#else
#    define ______MOUSE_WHEEL_1_________ XXXXXXX, WBCK   , KC_WH_U, WFWD   , KC_HOME
#    define ______MOUSE_WHEEL_2_________ XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R, KC_END
#endif

// RGB
#define ______RGB_CONTROL_1_________ RGB_MOD, RGB_VAI, RGB_SPI, RGB_SAI, RGB_HUI
#define ______RGB_CONTROL_2_________ RGB_RMOD,RGB_VAD, RGB_SPD, RGB_SAD, RGB_HUD
#define ______RGB_CONTROL_3_________ RGB_TOG, RGB_M_SW,RGB_M_R, RGB_M_B, RGB_M_G
// clang-format on
