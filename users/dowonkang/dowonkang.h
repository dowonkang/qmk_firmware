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
    _ADJUST
    // clang-format on
};

enum userspace_keycodes {
    // clang-format off
    U_ESC = SAFE_RANGE,
    NEW_SAFE_RANGE
    // clang-format on
};

// Layer Keys
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN_TAB LT(_FUNCTION, KC_TAB)

// Ctrl Combos
#define CTL_G LCTL(KC_G)
#define CTL_Z LCTL(KC_Z)
#define CTL_X LCTL(KC_X)
#define CTL_C LCTL(KC_C)
#define CTL_V LCTL(KC_V)
#define CTL_B LCTL(KC_B)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SC RGUI_T(KC_SCLN)

// Right-hand home row mods in LOWER layer
#define LOW_J RCTL_T(KC_MINS)
#define LOW_K RSFT_T(KC_LBRC)
#define LOW_L LALT_T(KC_RBRC)
