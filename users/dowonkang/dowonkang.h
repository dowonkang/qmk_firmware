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

enum userspace_keycodes {
    // clang-format off
    LOW_ESC = SAFE_RANGE,
    RSE_SPC,
    NEW_SAFE_RANGE
    // clang-format on
};

// clang-format off
// Layers
#define LOW     MO(_LOWER)
#define RSE     MO(_RAISE)
#define NUM     MO(_NUMPAD)
#define FN      MO(_FUNCTION)
#define MOUS    MO(_MOUSE)
#define ADJ     MO(_ADJUST)

// Layer-tap keys
#define FN_TAB  LT(_FUNCTION, KC_TAB)
#define FN_DEL  LT(_FUNCTION, KC_DELETE)
#define FN_BSPC LT(_FUNCTION, KC_BSPACE)
#define NUM_TAB LT(_NUMPAD, KC_TAB)
#define NUM_ESC LT(_NUMPAD, KC_ESCAPE)
#define MS_ESC  LT(_MOUSE, KC_ESCAPE)
#define MS_DEL  LT(_MOUSE, KC_DELETE)

// Mod-tap keys
#define CTL_SPC    LCTL_T(KC_SPACE)
#define CTL_BSP LCTL_T(KC_BSPACE)
#define SFT_ENT LSFT_T(KC_ENTER)

// Left-hand home row mods
#define HMOD_A  LGUI_T(KC_A)
#define HMOD_S  LALT_T(KC_S)
#define HMOD_D  LSFT_T(KC_D)
#define HMOD_F  LCTL_T(KC_F)
#define HMOD_X  ALGR_T(KC_X)

// Right-hand home row mods
#define HMOD_J  RCTL_T(KC_J)
#define HMOD_K  RSFT_T(KC_K)
#define HMOD_L  LALT_T(KC_L)
#define HMOD_SC RGUI_T(KC_SCLN)
#define HMOD_DT ALGR_T(KC_DOT)

// LOWER layer home row mods
#define LMOD_J  RCTL_T(KC_MINS)
#define LMOD_K  RSFT_T(KC_LBRC)
#define LMOD_L  LALT_T(KC_RBRC)

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
#define ______QWERTY_LEFT1__________ KC_Q   , KC_W   , KC_E   , KC_R   , KC_T
#define ______QWERTY_LEFT2__________ KC_A   , KC_S   , KC_D   , KC_F   , KC_G
#define ______QWERTY_LEFT3__________ KC_Z   , KC_X   , KC_C   , KC_V   , KC_B
#define ______QWERTY_RIGHT1_________ KC_Y   , KC_U   , KC_I   , KC_O   , KC_P
#define ______QWERTY_RIGHT2_________ KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN
#define ______QWERTY_RIGHT3_________ KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH

// Home-Mods
#define ______HOME_MOD_LEFT2________ HMOD_A , HMOD_S , HMOD_D , HMOD_F , KC_G
#define ______HOME_MOD_LEFT3________ KC_Z   , HMOD_X , KC_C   , KC_V   , KC_B
#define ______HOME_MOD_RIGHT2_______ KC_H   , HMOD_J , HMOD_K , HMOD_L , HMOD_SC
#define ______HOME_MOD_RIGHT3_______ KC_N   , KC_M   , KC_COMM, HMOD_DT, KC_SLSH

// Mods rows
#define ______MOD_LEFT_2______       KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL
#define ______MOD_LEFT_2____________ KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX
#define ______MOD_LEFT_2_GRAVE______ KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_GRV
#define ______MOD_LEFT_3____________ KC_APP , KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX
#define ______MOD_RIGHT_2___________ XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI
#define ______MOD_RIGHT_3___________ XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, KC_APP

// Symbol rows
#define ______SYMBOL_2______________ KC_QUOT, KC_MINS, KC_LBRC, KC_RBRC, _______
#define ______SYMBOL_2_MOD__________ KC_QUOT, LMOD_J , LMOD_K , LMOD_L , _______
#define ______SYMBOL_3______________ KC_BSLS, KC_EQL , _______, _______, _______

// VI-style navigation
#define ______VI_NAV_ROW_2__________ KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX
#define ______VI_NAV_ROW_3__________ KC_HOME, KC_PGDN, KC_PGUP, KC_END , XXXXXXX

// Mouse
#define ______MOUSE_VI_ROW_2________ KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX
#define ______MOUSE_VI_ROW_3________ KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX

// Media
#define ______MEDIA_____             KC_MPRV, KC_MPLY, KC_MNXT
#define ______MEDIA_________________ XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX

// Base
#define ______BASE_LEFT_1___________ KC_Q   , KC_W   , KC_E   , KC_R   , KC_T
#define ______BASE_LEFT_2___________ HMOD_A , HMOD_S , HMOD_D , HMOD_F , KC_G
#define ______BASE_LEFT_3___________ KC_Z   , HMOD_X , KC_C   , KC_V   , KC_B

#define ______BASE_RIGHT_1__________ KC_Y   , KC_U   , KC_I   , KC_O   , KC_P
#define ______BASE_RIGHT_2__________ KC_H   , HMOD_J , HMOD_K , HMOD_L , HMOD_SC
#define ______BASE_RIGHT_3__________ KC_N   , KC_M   , KC_COMM, HMOD_DT, KC_SLSH

// Lower
#define ______LOWER_LEFT_1__________ KC_1   , KC_2   , KC_3   , KC_4   , KC_5
#define ______LOWER_LEFT_2__________ KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_GRV
#define ______LOWER_LEFT_3__________ KC_DEL , KC_RALT, KC_APP , KC_TAB , KC_CAPS

#define ______LOWER_RIGHT_1_________ KC_6   , KC_7   , KC_8   , KC_9   , KC_0
#define ______LOWER_RIGHT_2_________ KC_QUOT, LMOD_J , LMOD_K , LMOD_L , KC_ENT
#define ______LOWER_RIGHT_3_________ KC_BSLS, KC_EQL , _______, _______, KC_BSPC

// Raise
#define ______RAISE_LEFT_1__________ ______LOWER_LEFT_1__________
#define ______RAISE_LEFT_2__________ ______LOWER_LEFT_2__________
#define ______RAISE_LEFT_3__________ ______LOWER_LEFT_3__________

#define ______RAISE_RIGHT_1_________ KC_6   , KC_7   , KC_8   , KC_9   , KC_0
#define ______RAISE_RIGHT_2_________ KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_ENT
#define ______RAISE_RIGHT_3_________ KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_BSPC

// Numpad
#define ______NUMPAD_LEFT_1_________ XXXXXXX, WBCK   , KC_UP  , WFWD   , KC_HOME
#define ______NUMPAD_LEFT_2_________ XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_END
#define ______NUMPAD_LEFT_3_________ KC_INS , XXXXXXX, KC_APP , KC_TAB , KC_CAPS

#define ______NUMPAD_RIGHT_1________ KC_NLCK, KC_P7  , KC_P8  , KC_P9  , KC_PMNS
#define ______NUMPAD_RIGHT_2________ KC_PAST, KC_P4  , KC_P5  , KC_P6  , KC_PPLS
#define ______NUMPAD_RIGHT_3________ KC_PSLS, KC_P1  , KC_P2  , KC_P3  , KC_PENT

// Function
#define ______FN_LEFT_1_____________ RSET, ______MEDIA_____, VOLU
#define ______FN_LEFT_2_____________ ______MOD_LEFT_2______, VOLD
#define ______FN_LEFT_3_____________ INS , ALTG, MENU, TAB , MUTE

#define ______FN_RIGHT_1____________ KC_PSCR, KC_F1  , KC_F2  , KC_F3  , KC_F4
#define ______FN_RIGHT_2____________ KC_SLCK, KC_F5  , KC_F6  , KC_F7  , KC_F8
#define ______FN_RIGHT_3____________ KC_PAUS, KC_F9  , KC_F10 , KC_F11 , KC_F12

// clang-format on
