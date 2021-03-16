#include "dowonkang.h"

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    return layer_state_set_keymap(state);
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t u_esc_timer;
    static uint16_t u_space_timer;
    static uint16_t low_esc_timer;
    static uint16_t num_tab_timer;
    static uint16_t fn_bspc_timer;
    switch (keycode) {
        case U_ESC:
            if (record->event.pressed) {
                u_esc_timer = timer_read();
                layer_on(_NUMPAD);
            } else {
                uint8_t mods = get_mods();
                layer_off(_NUMPAD);
                if (timer_elapsed(u_esc_timer) < TAPPING_TERM) {
                    if (mods & MOD_LALT || mods & MOD_LGUI) {
                        tap_code(KC_GRAVE);
                    } else {
                        tap_code(KC_ESCAPE);
                    }
                }
            }
            return false;
        case U_SPACE:
            if (record->event.pressed) {
                u_space_timer = timer_read();
                layer_on(_CTRL);
            } else {
                layer_off(_CTRL);
                if (timer_elapsed(u_space_timer) < TAPPING_TERM + 50) {
                    tap_code(KC_SPACE);
                }
            }
            return false;
        case LOW_ESC:
            if (record->event.pressed) {
                low_esc_timer = timer_read();
                layer_on(_LOWER);
            } else {
                uint8_t mods = get_mods();
                layer_off(_LOWER);
                if (timer_elapsed(low_esc_timer) < TAPPING_TERM) {
                    if (mods & MOD_LALT || mods & MOD_LGUI) {
                        tap_code(KC_GRAVE);
                    } else {
                        tap_code(KC_ESCAPE);
                    }
                }
            }
            return false;
        case NUM_TAB:
            if (record->event.pressed) {
                num_tab_timer = timer_read();
                layer_on(_NUMPAD);
            } else {
                layer_off(_NUMPAD);
                if (timer_elapsed(num_tab_timer) < TAPPING_TERM) {
                    tap_code(KC_TAB);
                }
            }
            return false;
        case FN_BSPC:
            if (record->event.pressed) {
                fn_bspc_timer = timer_read();
                layer_on(_FUNCTION);
            } else {
                layer_off(_FUNCTION);
                if (timer_elapsed(fn_bspc_timer) < TAPPING_TERM) {
                    tap_code(KC_BSPACE);
                }
            }
            return false;
        default:
            break;
    }
    return process_record_keymap(keycode, record);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case H_A:
        case H_S:
        // case H_D:
        case H_F:
        case H_X:
        case H_J:
        // case H_K:
        case H_L:
        case H_SCLN:
        case H_DOT:
        case LOW_J:
        case LOW_K:
        case LOW_L:
            return TAPPING_TERM + 50;

        case RSE_ENT:
        case LOW_ESC:
        case NUM_TAB:
        case FN_BSPC:
            return TAPPING_TERM - 50;

        case CTL_SPC:
            return TAPPING_TERM - 25;

        default:
            return TAPPING_TERM;
    }
}
