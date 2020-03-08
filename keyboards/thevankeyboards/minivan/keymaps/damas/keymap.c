#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum damas_layers {
    // clang-format off
    _BASE,
    _LOWER,
    _RAISE,
    _FUNCTION,
    _ADJUST
    // clang-format on
};

enum damas_keycodes {
    // clang-format off
    ESC = SAFE_RANGE
    // clang-format on
};

// Let's dance
typedef struct {
    bool is_press_action;
    int  state;
} tap;

enum {
    // clang-format off
    SINGLE_TAP = 1,
    SINGLE_HOLD = 2,
    DOUBLE_TAP = 3,
    DOUBLE_HOLD = 4
    // clang-format on
};
enum {
    // clang-format off
    TD_FN = 0
    // clang-format on
};

int  cur_dance(qk_tap_dance_state_t *state);
void td_fn_finished(qk_tap_dance_state_t *state, void *user_data);
void td_fn_reset(qk_tap_dance_state_t *state, void *user_data);

// Shortcuts
#define LOWER MO(_LOWER)
#define RSE_SPC LT(_RAISE, KC_SPACE)
#define FN TD(TD_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_BASE] = LAYOUT_arrow(
        /* BASE
         * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬─────────┐
         * │ Esc   │   Q   │   W   │   E   │   R   │   T   │   Y   │   U   │   I   │   O   │   P   │    Bspc │
         * ├───────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬────────┤
         * │ Tab    │   A   │   S   │   D   │   F   │   G   │   H   │   J   │   K   │   L   │   ;   │  Enter │
         * ├────────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬───────┤
         * │ Shift   │   Z   │   X   │   C   │   V   │   B   │   N   │   M   │   ,   │   .   │   /   │ Shift │
         * ├────────┬┴───────┼───────┴┬──────┴───────┴───┬───┴───────┴───┬───┴───────┼───────┼───────┼───────┤
         * │ Ctrl   │  GUI   │  Alt   │      Lower       │     Space     │    Fn     │  Alt  │  GUI  │  Ctrl │
         * └────────┴────────┴────────┴──────────────────┴───────────────┴───────────┴───────┴───────┴───────┘
         */
        ESC,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT,          LOWER,            KC_SPC,           FN,      KC_RALT, KC_RGUI, KC_RCTL
    ),
    [_LOWER] = LAYOUT_arrow(
        /* LOWER
         * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬─────────┐
         * │   `   │   1   │   2   │   3   │   4   │   5   │   6   │   7   │   8   │   9   │   0   │  Delete │
         * ├───────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬────────┤
         * │        │       │ Back  │ Stop  │Refresh│Forward│   '   │   -   │   =   │       │       │        │
         * ├────────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬───────┤
         * │         │       │ Mute  │ Vol - │ Vol + │ Play  │   \   │   [   │   ]   │       │       │       │
         * ├────────┬┴───────┼───────┴┬──────┴───────┴───┬───┴───────┴───┬───┴───────┼───────┼───────┼───────┤
         * │        │        │        │                  │               │           │       │       │       │
         * └────────┴────────┴────────┴──────────────────┴───────────────┴───────────┴───────┴───────┴───────┘
         */
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        _______, _______, KC_WBAK, KC_WSTP, KC_WREF, KC_WFWD, KC_QUOT, KC_MINS, KC_EQL,  _______, _______, _______,
        _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_BSLS, KC_LBRC, KC_RBRC, _______, _______, _______,
        _______, _______, _______,          _______,          _______,          _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT_arrow(
        /* RAISE
         * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬─────────┐
         * │   `   │   1   │   2   │   3   │   4   │   5   │   6   │   7   │   8   │   9   │   0   │  Delete │
         * ├───────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬────────┤
         * │        │   6   │   7   │   8   │   9   │   0   │       │       │       │       │       │        │
         * ├────────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬───────┤
         * │         │       │       │       │       │       │       │       │       │ Home  │  Up   │   End │
         * ├────────┬┴───────┼───────┴┬──────┴───────┴───┬───┴───────┴───┬───┴───────┼───────┼───────┼───────┤
         * │        │        │        │                  │               │           │ Left  │ Down  │ Right │
         * └────────┴────────┴────────┴──────────────────┴───────────────┴───────────┴───────┴───────┴───────┘
         */
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP,   KC_END,
        _______, _______, _______,          _______,          _______,          _______, KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_FUNCTION] = LAYOUT_arrow(
        /* FUNCTION
         * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬─────────┐
         * │       │  F1   │  F2   │  F3   │  F4   │       │       │       │       │ NumLk │  Ins  │    Del  │
         * ├───────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬────────┤
         * │ CapsLk │  F5   │  F6   │  F7   │  F8   │       │       │       │       │ PrtSc │ ScrLk │  Pause │
         * ├────────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬───────┤
         * │         │  F9   │  F10  │  F11  │  F12  │       │       │       │       │ W.Bak │ PgUp  │ W.Fwd │
         * ├────────┬┴───────┼───────┴┬──────┴───────┴───┬───┴───────┴───┬───┴───────┼───────┼───────┼───────┤
         * │        │        │        │                  │               │           │ Home  │ PgDn  │   End │
         * └────────┴────────┴────────┴──────────────────┴───────────────┴───────────┴───────┴───────┴───────┘
         */
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK, KC_INS,  KC_DEL,
        KC_CAPS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS,
        _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WBAK, KC_PGUP, KC_WFWD,
        _______, _______, _______,          XXXXXXX,          XXXXXXX,          _______, KC_HOME, KC_PGDN, KC_END
    ),
    [_ADJUST] = LAYOUT_arrow(
        /* ADJUST
         * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬─────────┐
         * │       │       │       │       │       │       │       │       │       │       │       │  RESET  │
         * ├───────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬────────┤
         * │        │       │       │       │       │       │       │       │       │       │       │        │
         * ├────────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬───────┤
         * │         │       │       │       │       │       │       │       │       │       │       │       │
         * ├────────┬┴───────┼───────┴┬──────┴───────┴───┬───┴───────┴───┬───┴───────┼───────┼───────┼───────┤
         * │        │        │        │                  │               │           │       │       │       │
         * └────────┴────────┴────────┴──────────────────┴───────────────┴───────────┴───────┴───────┴───────┘
         */
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,          _______,          XXXXXXX,          _______, XXXXXXX, XXXXXXX, XXXXXXX
    )

    // Template for additional layers
    // [_LAYER] = LAYOUT_arrow(
        /* LAYER NAME
         * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────────┐
         * │       │       │       │       │       │       │       │       │       │       │       │           │
         * ├───────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────┴┬──────────┤
         * │        │       │       │       │       │       │       │       │       │       │       │          │
         * ├────────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬───────┤
         * │           │       │       │       │       │       │       │       │       │       │       │       │
         * ├────────┬──┴───────┼───────┴┬──────┴───────┴───┬───┴───────┴────┬──┴───────┼───────┼───────┼───────┤
         * │        │          │        │                  │                │          │       │       │       │
         * └────────┴──────────┴────────┴──────────────────┴────────────────┴──────────┴───────┴───────┴───────┘
         */
        // _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // _______, _______, _______,          _______,          _______,          _______, _______, _______, _______
    // ),
    // clang-format on
};

// Track NumLock state
static bool numlock_state = false;

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    // Set up RGB effects on _only_ the third LED (index 2)
    rgblight_set_effect_range(2, 1);
    // Set LED effects to breathing mode in a tealish blue color
    rgblight_sethsv_noeeprom(38, 191, 198);
    rgblight_mode_noeeprom(RGBLIGHT_EFFECT_BREATHING + 2);

    // Init the first two LEDs to a static color
    setrgb(0, 0, 0, (LED_TYPE *)&led[0]);
    setrgb(0, 0, 0, (LED_TYPE *)&led[1]);
    rgblight_set();
#endif  // RGBLIGHT_ENABLE
    numlock_state = host_keyboard_led_state().num_lock;
}

uint32_t layer_state_set_user(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
    uint8_t led0r = 0;
    uint8_t led0g = 0;
    uint8_t led0b = 0;
    if (layer_state_cmp(state, _ADJUST)) {
        led0r = 255;
        led0b = 255;
    }
    if (layer_state_cmp(state, _LOWER)) {
        led0b = 255;
    }
    if (layer_state_cmp(state, _RAISE)) {
        led0r = 255;
    }
    if (layer_state_cmp(state, _FUNCTION)) {
        led0g = 255;
    }
    setrgb(led0r, led0g, led0b, (LED_TYPE *)&led[0]);
#endif  // RGBLIGHT_ENABLE
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool led_update_user(led_t led_state) {
#ifdef RGBLIGHT_ENABLE
    uint8_t led1r = 0;
    uint8_t led1g = 0;
    uint8_t led1b = 0;

    if (led_state.caps_lock) {
        led1r = 255;
    } else {
        led1r = 0;
    }
    if (led_state.num_lock) {
        led1g = 255;
    } else {
        led1g = 0;
    }
    if (led_state.scroll_lock) {
        led1b = 255;
    } else {
        led1b = 0;
    }

    setrgb(led1r, led1g, led1b, (LED_TYPE *)&led[1]);
    rgblight_set();
#endif  // RGBLIGHT_ENABLE
    numlock_state = led_state.num_lock;
    return true;
}

#define MODS_ALT get_mods() & MOD_MASK_ALT
#define MODS_GUI get_mods() & MOD_MASK_GUI

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ESC: {
            static uint8_t kc;

            if (record->event.pressed) {
                if (MODS_ALT || MODS_GUI) {
                    kc = KC_GRAVE;
                } else {
                    kc = KC_ESCAPE;
                }

                register_code(kc);
            } else {
                unregister_code(kc);
            }
            break;
        }
    }
    return true;
}

// Let's DANCE!
int cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) {
            return SINGLE_TAP;
        } else {
            return SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        if (!state->pressed) {
            return DOUBLE_TAP;
        } else {
            return DOUBLE_HOLD;
        }
    }
    return 5;
}

static tap fn_state = {.is_press_action = true, .state = 0};

void td_fn_finished(qk_tap_dance_state_t *state, void *user_data) {
    fn_state.state = cur_dance(state);
    switch (fn_state.state) {
        case SINGLE_TAP:
            tap_code(KC_APPLICATION);
            break;
        case SINGLE_HOLD:
            layer_move(_RAISE);
            break;
        case DOUBLE_TAP:
            break;
        case DOUBLE_HOLD:
            layer_move(_FUNCTION);
            break;
    }
}

void td_fn_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (fn_state.state) {
        case SINGLE_TAP:
            break;
        case SINGLE_HOLD:
            layer_off(_RAISE);
            break;
        case DOUBLE_TAP:
            break;
        case DOUBLE_HOLD:
            layer_off(_FUNCTION);
            break;
    }
    fn_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // clang-format off
    [TD_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_fn_finished, td_fn_reset)
    // clang-format on
};
