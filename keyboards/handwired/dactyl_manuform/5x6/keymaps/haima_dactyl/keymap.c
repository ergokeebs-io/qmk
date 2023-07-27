#include QMK_KEYBOARD_H

enum custom_layers {
 _BASE,
 _DEV,
 _NAV,
 _CONF
};

enum custom_keycodes {
  FUNCTION_START = SAFE_RANGE,
  AMP,
  ASTERIX,
  AT,
  CIRC,
  DBL_QUOTE,
  DOG,
  DOLLAR,
  EQUAL_PLUS,
  HASH,
  LPARENS,
  LSQUARE_CURLY,
  MIN_SUP,
  PERCENT,
  PIPE,
  RPARENS,
  RSQUARE_CURLY,
  SLASH_QUEST,
};

enum unicode_names {
    CKC_SLASH,
    CKC_QUESTION,
};

const uint32_t PROGMEM unicode_map[] = {
    [CKC_SLASH]  = 0x1F4A9,  // /
    [CKC_QUESTION] = 0x20AC,  // ?
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT_5x6(
      QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5,                  KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_BSPC, 
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                   KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_MINS, 
      OSM(MOD_LSFT), KC_A, KC_S, KC_D, KC_F, KC_G,            KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, 
      KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,                  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS, 
                  KC_LBRC, KC_RBRC,                                       KC_PLUS, KC_EQL, 
      
                                  KC_SPC,  LCTL(KC_C),              KC_LALT, KC_SPC, 
                                  KC_LGUI, MO(_NAV),                MO(_DEV),   KC_ENT, 
                                  XXXXXXX, LCTL(KC_V),               KC_PSCR, XXXXXXX
    ),
	[_DEV] = LAYOUT_5x6(
      _______, PIPE,    AT,      HASH,    DOLLAR,   PERCENT,                CIRC,    AMP,       ASTERIX,   LPARENS,   RPARENS,   DOG, 
      _______, KC_B, XXXXXXX, XXXXXXX, XXXXXXX,  FUNCTION_START,            XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
      _______, KC_1, KC_2,    KC_3,    KC_4,     KC_5,                      KC_6,    KC_7,      KC_8,      KC_9,      KC_0,      DBL_QUOTE, 
      _______, XXXXXXX, RALT(KC_QUOT), RALT(KC_BSLS), XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,KC_GRV,    KC_TILD, SLASH_QUEST,   XXXXXXX, 
                        LSQUARE_CURLY, RSQUARE_CURLY,                               XXXXXXX,   EQUAL_PLUS, 
                                  _______, _______,                             _______, _______, 
                                  _______, TG(_CONF),                            _______ , _______, 
                                  XXXXXXX, _______,                             _______, XXXXXXX
    ),
	[_NAV] = LAYOUT_5x6(
      _______, PIPE, AT,   HASH, DOLLAR, PERCENT,                 CIRC,    AMP,     ASTERIX, LPARENS,   RPARENS,   KC_DEL, 
      _______, KC_1, KC_2, KC_3, KC_4,   KC_5,                    KC_6,    KC_7,    KC_8,    KC_9,      KC_0,      KC_VOLU, 
      _______, _______, _______, _______, _______, _______,       KC_PGUP, KC_LEFT, KC_DOWN, KC_UP,     KC_RIGHT,  KC_VOLD, 
      _______, _______, _______, _______, _______, _______,       KC_PGDN, _______, KC_GRV,  KC_TILD,   SLASH_QUEST,   XXXXXXX,
                        LSQUARE_CURLY, RSQUARE_CURLY,                                        _______,   EQUAL_PLUS, 
                                        _______, _______,                       _______, _______, 
                                        _______, _______,                       TG(_CONF), _______, 
                                        _______, _______,                       _______, _______
    ),
    [_CONF] = LAYOUT_5x6(
      _______, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, _______, 
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, KC_P7 ,  KC_P8 ,  KC_P9,   XXXXXXX,   XXXXXXX, 
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CG_TOGG,         XXXXXXX, KC_P4 ,  KC_P5 ,  KC_P6,   XXXXXXX,   XXXXXXX, 
      _______, _______, _______, _______, _______, XXXXXXX,         XXXXXXX, KC_P1 ,  KC_P2 ,  KC_P3,   XXXXXXX,   XXXXXXX,
                        XXXXXXX, XXXXXXX,                                        KC_P0, XXXXXXX, 
                                    _______, _______,               _______, _______, 
                                    _______, _______,               _______, _______,
                                    _______, _______,               _______, _______
    )
};

uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Store the current modifier state in the variable for later reference
  mod_state = get_mods();
  switch(keycode) {

  // Issues a Delete action if backspace is pressed with left shifg
  case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }
    case PERCENT:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT("5"));
      }
      break;
    case DOG:
      if (record->event.pressed) {
        SEND_STRING("--------");
        SEND_STRING(SS_LSFT("6"));
      }
      break;    
    case FUNCTION_START:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(" "));
        _delay_ms(50);
        SEND_STRING("() => {}");
        _delay_ms(50);
        SEND_STRING(SS_LCTRL(" "));
      }
      break;
    case PIPE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("1"));
      }
      break;    
    case SLASH_QUEST:
      if (record->event.pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
          clear_mods();
          // SEND_STRING(SS_LSFT("'"));
        } else {
          SEND_STRING(SS_LSFT("7"));
        }
      }
      break;
    case AT:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("2"));
      }
      break;
    case HASH:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("3"));
      }
      break;    
    case DOLLAR:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT("4"));
      }
      break;
    case AMP:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT("6"));
      }
      break;      
    case CIRC:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT("\1\1\x2F")); // don't know why, but it works
      }
      break;       
    case ASTERIX:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT("]"));
      }
      break;      
    case LPARENS:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT("8"));
      }
      break;    
    case RPARENS:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT("9"));
      }
      break;        
    case EQUAL_PLUS:
      if (record->event.pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
          SEND_STRING("+");
        } else {
          SEND_STRING(SS_LSFT("0"));
        }
      }
      break;    
    case LSQUARE_CURLY:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(" "));
        _delay_ms(50);
        if (mod_state & MOD_MASK_SHIFT) {
          SEND_STRING(SS_LSFT("["));
        } else {
          SEND_STRING("[");
        }
        _delay_ms(50);
        SEND_STRING(SS_LCTRL(" "));
      }
      break;      
    case RSQUARE_CURLY:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(" "));
        _delay_ms(50);
        if (mod_state & MOD_MASK_SHIFT) {
          SEND_STRING(SS_LSFT("]"));
        } else {
          SEND_STRING("]");
        }
        _delay_ms(50);
        SEND_STRING(SS_LCTRL(" "));
      }
      break;
    case DBL_QUOTE:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT("2"));
      }
      break;
  }
  return true;
}

