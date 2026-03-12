#include "ergokeebs-io.h"

// ============================================================================
// PROCESS RECORD USER
// ============================================================================

// Store modifier state for Shift+Backspace = Delete
static uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();

    switch (keycode) {

        // ====================================================================
        // SHIFT + BACKSPACE = DELETE
        // ====================================================================
        case KC_BSPC: {
            static bool delkey_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    delkey_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            return true;
        }

        // ====================================================================
        // LALT + Q = PIPE (|)
        // ====================================================================
        case KC_Q:
            if (record->event.pressed && (mod_state & MOD_BIT(KC_LALT))) {
                clear_mods();
                tap_code16(ES_PIPE);
                set_mods(mod_state);
                return false;
            }
            return true;

        // ====================================================================
        // ES LAYOUT: Real backtick (dead grave + space)
        // ====================================================================
        case MY_BKTK:
            if (record->event.pressed) {
                tap_code(KC_LBRC);  // dead grave
                tap_code(KC_SPC);   // space to produce real backtick
            }
            return false;

        // ====================================================================
        // < and > for macOS Spanish non-ISO
        // ====================================================================
        case MY_LABK:
            if (record->event.pressed) {
                tap_code(KC_GRV);  // < on ES non-ISO
            }
            return false;

        case MY_RABK:
            if (record->event.pressed) {
                tap_code16(S(KC_GRV));  // > on ES non-ISO
            }
            return false;

        // ====================================================================
        // Tilde (~) for macOS Spanish non-ISO (Alt+ñ)
        // ====================================================================
        case MY_TILD:
            if (record->event.pressed) {
                tap_code16(LALT(KC_SCLN));  // Alt+ñ
            }
            return false;

        // ====================================================================
        // Plus (+) and Asterisk (*) for macOS Spanish non-ISO
        // ====================================================================
        case MY_PLUS:
            if (record->event.pressed) {
                tap_code(KC_RBRC);  // + on ES non-ISO
            }
            return false;

        case MY_ASTR:
            if (record->event.pressed) {
                tap_code16(S(KC_RBRC));  // * on ES non-ISO (Shift + +)
            }
            return false;

        // ====================================================================
        // RECTANGLE WINDOW MANAGEMENT
        // Symmetric layout: left hand = left, right hand = right
        // Ring=1/6, Middle=1/4, Index=1/3, Inner=1/2
        // ====================================================================
        case RECT_L:  // Left Half (G key)
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(KC_LEFT)));
            }
            return false;

        case RECT_R:  // Right Half (H key)
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(KC_RGHT)));
            }
            return false;

        case RECT_13L:  // First Third (F key)
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(KC_D)));
            }
            return false;

        case RECT_13R:  // Last Third (J key)
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(KC_G)));
            }
            return false;

        case RECT_14L:  // First Fourth (D key)
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(LSFT(KC_LEFT))));
            }
            return false;

        case RECT_14R:  // Last Fourth (K key)
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(LSFT(KC_RGHT))));
            }
            return false;

        case RECT_16L:  // First Sixth (S key)
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(LSFT(KC_1))));
            }
            return false;

        case RECT_16R:  // Last Sixth (L key)
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(LSFT(KC_6))));
            }
            return false;

        // ====================================================================
        // PASSWORD MACRO
        // ====================================================================
        case MY_PWD:
            if (record->event.pressed) {
                SEND_STRING("CHANGE_ME");
            }
            return false;
    }

    return true;
}

// ============================================================================
// LAYER STATE
// ============================================================================

layer_state_t layer_state_set_user(layer_state_t state) {
    // Activate ADJUST layer when both LOWER and RAISE are held
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
