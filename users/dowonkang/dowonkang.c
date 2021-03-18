#include "dowonkang.h"

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) {
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    return layer_state_set_keymap(state);
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();

    static uint16_t low_esc_timer;
    static uint16_t rse_spc_timer;

    switch (keycode) {
        case LOW_ESC:
            if (record->event.pressed) {
                low_esc_timer = timer_read();
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
                if (timer_elapsed(low_esc_timer) < TAPPING_TERM) {
                    if (mod_state & MOD_LALT || mod_state & MOD_LGUI) {
                        tap_code(KC_GRAVE);
                    } else {
                        tap_code(KC_ESCAPE);
                    }
                }
            }
            return false;

        case RSE_SPC:
            if (record->event.pressed) {
                rse_spc_timer = timer_read();
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
                if (timer_elapsed(rse_spc_timer) < TAPPING_TERM) {
                    tap_code(KC_SPACE);
                }
            }
            return false;

        default:
            return process_record_keymap(keycode, record);
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HMOD_A:
        case HMOD_S:
        // case HMOD_D:
        case HMOD_F:
        case HMOD_X:
        case HMOD_J:
        // case HMOD_K:
        case HMOD_L:
        case HMOD_SC:
        case HMOD_DT:
        case LMOD_J:
        // case LMOD_K:
        case LMOD_L:
        // case CTL_SPC:
        // case CTL_BSP:
        case SFT_ENT:
            return TAPPING_TERM + 50;

        case LOW_ESC:
        case RSE_SPC:
            return TAPPING_TERM - 25;

        default:
            return TAPPING_TERM;
    }
}
