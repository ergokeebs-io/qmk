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
        // ES LAYOUT HACKS
        // ====================================================================
        case ES_AT:
            if (record->event.pressed) {
                tap_code16(RALT(KC_2));
            }
            return false;

        case ES_GRV:
            if (record->event.pressed) {
                tap_code16(RALT(KC_LBRC));
            }
            return false;

        case ES_QUES:
            if (record->event.pressed) {
                // En ES layout: Shift + - = ?
                tap_code16(LSFT(KC_MINS));
            }
            return false;

        case ES_TILD:
            if (record->event.pressed) {
                tap_code16(RALT(KC_4));
            }
            return false;

        // ====================================================================
        // RECTANGLE WINDOW MANAGEMENT
        // All shortcuts are Ctrl+Alt+<key>
        // ====================================================================
        case RECT_TL:
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(KC_U)));
            }
            return false;

        case RECT_T:
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(KC_UP)));
            }
            return false;

        case RECT_TR:
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(KC_I)));
            }
            return false;

        case RECT_L:
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(KC_LEFT)));
            }
            return false;

        case RECT_C:
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(KC_DOWN)));
            }
            return false;

        case RECT_R:
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(KC_RGHT)));
            }
            return false;

        case RECT_BL:
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(KC_J)));
            }
            return false;

        case RECT_BR:
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(KC_K)));
            }
            return false;

        case RECT_13L:
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(KC_D)));
            }
            return false;

        case RECT_13C:
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(KC_F)));
            }
            return false;

        case RECT_13R:
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(KC_G)));
            }
            return false;

        case RECT_23L:
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(KC_E)));
            }
            return false;

        case RECT_23C:
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(KC_R)));
            }
            return false;

        case RECT_23R:
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(KC_T)));
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
