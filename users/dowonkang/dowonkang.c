#include "dowonkang.h"

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) {
    return state;
}

layer_state_t highest_layer;

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    state         = layer_state_set_keymap(state);
    highest_layer = get_highest_layer(state);
    return state;
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

// uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // mod_state = get_mods();

    // static uint16_t low_esc_timer;
    // static uint16_t rse_spc_timer;
    // static uint16_t rse_ent_timer;

    switch (keycode) {
        case LAYER_LOCK:
            if (record->event.pressed) {
                layer_move(highest_layer);
            }
            return false;

        case LAYER_CLEAR:
            if (record->event.pressed) {
                layer_clear();
            }
            return false;

        // clang-format off
        // case LOW_ESC:
        //     if (record->event.pressed) {
        //         low_esc_timer = timer_read();
        //         layer_on(_LOWER);
        //     } else {
        //         layer_off(_LOWER);
        //         if (timer_elapsed(low_esc_timer) < TAPPING_TERM) {
        //             if (mod_state & MOD_LALT || mod_state & MOD_LGUI) {
        //                 tap_code(KC_GRAVE);
        //             } else {
        //                 tap_code(KC_ESCAPE);
        //             }
        //         }
        //     }
        //     return false;

        // case RSE_SPC:
        //     if (record->event.pressed) {
        //         rse_spc_timer = timer_read();
        //         layer_on(_RAISE);
        //     } else {
        //         layer_off(_RAISE);
        //         if (timer_elapsed(rse_spc_timer) < TAPPING_TERM) {
        //             tap_code(KC_SPACE);
        //         }
        //     }
        //     return false;

        // case RSE_ENT:
        //     if (record->event.pressed) {
        //         rse_ent_timer = timer_read();
        //         layer_on(_RAISE);
        //     } else {
        //         layer_off(_RAISE);
        //         if (timer_elapsed(rse_ent_timer) < TAPPING_TERM) {
        //             tap_code(KC_ENTER);
        //         }
        //     }
        //     return false;
        // clang-format on

        default:
            return process_record_keymap(keycode, record);
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_ESC:
        case MT_TAB:
        case MT_SPC:
        case MT_BSPC:
            return TAPPING_TERM - 50;

        default:
            return TAPPING_TERM;
    }
}

#ifdef TAP_DANCE_ENABLE
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            return SINGLE_TAP;
        } else {
            return SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        if (state->interrupted || !state->pressed) {
            return DOUBLE_TAP;
        } else {
            return DOUBLE_HOLD;
        }
    }
    return 8;
}

static tap ltl_tap_state = {.is_press_action = true, .state = 0};

void ltl_finished(qk_tap_dance_state_t *state, void *user_data) {
    ltl_tap_state.state = cur_dance(state);
    switch (ltl_tap_state.state) {
        case SINGLE_TAP:
            register_code(KC_ESCAPE);
            break;
        case SINGLE_HOLD:
            register_code(KC_LALT);
            break;
        case DOUBLE_TAP:
            register_code(KC_ESCAPE);
            break;
        case DOUBLE_HOLD:
            layer_on(_NUMPAD);
            break;
        default:
            break;
    }
}

void ltl_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ltl_tap_state.state) {
        case SINGLE_TAP:
            unregister_code(KC_ESCAPE);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_LALT);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_ESCAPE);
            break;
        case DOUBLE_HOLD:
            layer_off(_NUMPAD);
            break;
        default:
            break;
    }
    ltl_tap_state.state = 0;
}

static tap rtr_tap_state = {.is_press_action = true, .state = 0};

void rtr_finished(qk_tap_dance_state_t *state, void *user_data) {
    rtr_tap_state.state = cur_dance(state);
    switch (rtr_tap_state.state) {
        case SINGLE_TAP:
            register_code(KC_BSPACE);
            break;
        case SINGLE_HOLD:
            register_code(KC_LALT);
            break;
        case DOUBLE_TAP:
            register_code(KC_BSPACE);
            break;
        case DOUBLE_HOLD:
            layer_on(_FUNCTION);
            break;
        default:
            break;
    }
}

void rtr_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (rtr_tap_state.state) {
        case SINGLE_TAP:
            unregister_code(KC_BSPACE);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_LALT);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_BSPACE);
            break;
        case DOUBLE_HOLD:
            layer_off(_FUNCTION);
            break;
        default:
            break;
    }
    rtr_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // clang-format off
    [LEFT_THUMB_LEFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ltl_finished, ltl_reset),
    [RIGHT_THUMB_RIGHT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rtr_finished, rtr_reset)
    // clang-format on
};
#endif
