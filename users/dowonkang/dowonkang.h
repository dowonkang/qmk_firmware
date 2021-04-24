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
    _MOUSE,
    _ADJUST
    // clang-format on
};

// Tap dance
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

// clang-format off
// Layers
#define LOW     MO(_LOWER)
#define RSE     MO(_RAISE)
#define NUM     MO(_NUMPAD)
#define FN      MO(_FUNCTION)
#define MOUS    MO(_MOUSE)
#define ADJ     MO(_ADJUST)

// Layer-tap
#define NUM_ESC LT(_NUMPAD, KC_ESCAPE)

// Mod-tap keys
#define CTL_SPC LCTL_T(KC_SPACE)
#define CTL_TAB LCTL_T(KC_TAB)
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

// Modifiers
#define SFTL    KC_LSFT
#define SFTR    KC_RSFT
#define ALTG    KC_RALT

#define GRV     KC_GRAVE

// Numpad
#define P0      KC_P0
#define PDOT    KC_PDOT
#define PENT    KC_PENT

// Movements
#define _UP_    KC_UP
#define _DN_    KC_DOWN
#define LEFT    KC_LEFT
#define RGHT    KC_RGHT
#define HOME    KC_HOME
#define END     KC_END
#define PGUP    KC_PGUP
#define PGDN    KC_PGDN

// Web navigations
#define WBCK    LALT(KC_LEFT)
#define WFWD    LALT(KC_RIGHT)
#define WREF    LCTL(KC_R)

// Media
#define VOLU    KC_VOLU
#define VOLD    KC_VOLD
#define MUTE    KC_MUTE

// Mouse
#define BTN1    KC_MS_BTN1
#define BTN2    KC_MS_BTN2
#define BTN3    KC_MS_BTN3
#define ACL0    KC_ACL0
#define ACL1    KC_ACL1
#define ACL2    KC_ACL2

// XXXXXXX
#define XXXXXXXXXXXXXXXXXXXXXXXXXXXX XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

// _______
#define ____________________________ _______, _______, _______, _______, _______

// Number row
     // XXXX, XXXX, XXXX, XXXX, XXXX
#define ______NUMBER_12345__________ KC_1   , KC_2   , KC_3   , KC_4   , KC_5
#define ______NUMBER_67890__________ KC_6   , KC_7   , KC_8   , KC_9   , KC_0

// QWERTY
#define ______QWERTY_LEFT_1_________ KC_Q   , KC_W   , KC_E   , KC_R   , KC_T
#define ______QWERTY_LEFT_2_________ KC_A   , KC_S   , KC_D   , KC_F   , KC_G
#define ______QWERTY_LEFT_3_________ KC_Z   , KC_X   , KC_C   , KC_V   , KC_B
#define ______QWERTY_RIGHT_1________ KC_Y   , KC_U   , KC_I   , KC_O   , KC_P
#define ______QWERTY_RIGHT_2________ KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN
#define ______QWERTY_RIGHT_3________ KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH

// Base
#define ______BASE_LEFT_1___________ ______QWERTY_LEFT_1_________
#define ______BASE_LEFT_2___________ KC_A   , MT_S   , MT_D   , MT_F   , KC_G
#define ______BASE_LEFT_3___________ MT_Z   , KC_X   , MT_C   , MT_V   , KC_B

#define ______BASE_RIGHT_1__________ ______QWERTY_RIGHT_1________
#define ______BASE_RIGHT_2__________ KC_H   , MT_J   , MT_K   , MT_L   , KC_SCLN
#define ______BASE_RIGHT_3__________ KC_N   , MT_M   , MT_COMM, KC_DOT , MT_SLSH

// Lower
#define ______LOWER_LEFT_1__________ ______NUMBER_12345__________
#define ______LOWER_LEFT_2__________ NUM_ESC, KC_LGUI, KC_LALT, KC_LCTL, KC_GRV
#define ______LOWER_LEFT_3__________ MT_CAPS, KC_APP , KC_RALT, KC_HYPR, KC_SPC

#define ______LOWER_RIGHT_1_________ ______NUMBER_67890__________
#define ______LOWER_RIGHT_2_________ KC_QUOT, MT_MINS, MT_LBRC, MT_RBRC, _______
#define ______LOWER_RIGHT_3_________ KC_BSLS, MT_EQL , _______, _______, _______

// Raise
#define ______RAISE_LEFT_1__________ ______LOWER_LEFT_1__________
#define ______RAISE_LEFT_2__________ ______LOWER_LEFT_2__________
#define ______RAISE_LEFT_3__________ ______LOWER_LEFT_3__________

#define ______RAISE_RIGHT_1_________ KC_PSCR, XXXXXXX, KC_INS , KC_DEL , KC_BSPC
#define ______RAISE_RIGHT_2_________ KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_ENT
#define ______RAISE_RIGHT_3_________ KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_RSFT

// Numpad
#define ______NUMPAD_LEFT_1_________ KC_TAB , WBCK   , KC_UP  , WFWD   , KC_HOME
#define ______NUMPAD_LEFT_2_________ KC_ESC , KC_LEFT, KC_DOWN, KC_RGHT, KC_END
#define ______NUMPAD_LEFT_3_________ MT_CAPS, KC_LGUI, KC_LALT, KC_LCTL, KC_SPC

#define ______NUMPAD_RIGHT_1________ KC_NLCK, KC_P7  , KC_P8  , KC_P9  , KC_PMNS
#define ______NUMPAD_RIGHT_2________ KC_PAST, KC_P4  , KC_P5  , KC_P6  , KC_PPLS
#define ______NUMPAD_RIGHT_3________ KC_PSLS, KC_P1  , KC_P2  , KC_P3  , KC_PENT

// Function
#define ______FN_LEFT_1_____________ RSET   , KC_MPRV, KC_MPLY, KC_MNXT, VOLU
#define ______FN_LEFT_2_____________ KC_ESC , KC_LGUI, KC_LALT, KC_LCTL, VOLD
#define ______FN_LEFT_3_____________ MT_CAPS, KC_APP , KC_RALT, KC_HYPR, MUTE

#define ______FN_RIGHT_1____________ KC_PSCR, KC_F1  , KC_F2  , KC_F3  , KC_F4
#define ______FN_RIGHT_2____________ KC_SLCK, KC_F5  , KC_F6  , KC_F7  , KC_F8
#define ______FN_RIGHT_3____________ KC_PAUS, KC_F9  , KC_F10 , KC_F11 , KC_F12

// Mouse
#define ______MOUSE_VI_CURSOR_______ KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX
#define ______MOUSE_VI_WHEEL________ KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX
// clang-format on
