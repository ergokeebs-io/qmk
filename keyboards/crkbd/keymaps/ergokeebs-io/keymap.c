/**
 * Crkbd (Corne) Keymap
 * ergokeebs-io
 *
 * Spanish layout with shared ergokeebs-io code.
 */

#include QMK_KEYBOARD_H
#include "ergokeebs-io.h"

// ============================================================================
// TAP DANCE (must be in keymap.c for introspection)
// ============================================================================

#ifdef TAP_DANCE_ENABLE
void td_tab_esc_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_TAB);
    } else if (state->count == 2) {
        tap_code(KC_ESC);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_TAB_ESC] = ACTION_TAP_DANCE_FN(td_tab_esc_finished),
};
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // ========================================================================
    // LAYER 0: BASE (QWERTY)
    // ========================================================================
    [_BASE] = LAYOUT_split_3x6_3(
    // ╭───────────┬───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────┬───────╮
        TD_TESC,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        OSM_SFT,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,       KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        KC_LCTL,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,       KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,RALT_LY,
    // ╰───────────┴───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┼───────┴───────┴───────┴───────╯
                                    KC_ENT, KC_LGUI, LOWER,      RAISE,  KC_SPC, KC_RALT
    //                             ╰───────┴───────┴───────╯   ╰───────┴───────╯
    ),

    // ========================================================================
    // LAYER 1: LOWER (Numbers + Navigation)
    // ========================================================================
    [_LOWER] = LAYOUT_split_3x6_3(
    // ╭───────────┬───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────┬───────╮
        KC_ESC,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_BSPC,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        KC_LSFT,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    KC_LEFT,KC_UP,  KC_DOWN,KC_RGHT,MY_TILD,XXXXXXX,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        KC_LCTL,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    KC_HOME,KC_PGDN,KC_PGUP,KC_END, XXXXXXX,XXXXXXX,
    // ╰───────────┴───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┼───────┴───────┴───────┴───────╯
                                    KC_ENT, KC_LGUI, _______,    _______, KC_SPC, KC_RALT
    //                             ╰───────┴───────┴───────╯   ╰───────┴───────╯
    ),

    // ========================================================================
    // LAYER 2: RAISE (Symbols)
    // ========================================================================
    [_RAISE] = LAYOUT_split_3x6_3(
    // ╭───────────┬───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────┬───────╮
        KC_ESC,     ES_EXLM,ES_DQUO,ES_BULT,ES_DLR, ES_PERC,    ES_AMPR,ES_SLSH,ES_LPRN,ES_RPRN,ES_EQL, KC_BSPC,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        KC_LSFT,    ES_LPRN,ES_LCBR,ES_LBRC,MY_LABK,XXXXXXX,    XXXXXXX,MY_RABK,ES_RBRC,ES_RCBR,ES_RPRN,MY_BKTK,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        KC_LCTL,    KC_UNDS,ES_PLUS,KC_BSLS,KC_PIPE,XXXXXXX,    ES_QUES,XXXXXXX,MY_ASTR,MY_PLUS,XXXXXXX,XXXXXXX,
    // ╰───────────┴───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┼───────┴───────┴───────┴───────╯
                                    KC_ENT, KC_LGUI, _______,    _______, KC_SPC, KC_RALT
    //                             ╰───────┴───────┴───────╯   ╰───────┴───────╯
    ),

    // ========================================================================
    // LAYER 3: ADJUST (Config)
    // ========================================================================
    [_ADJUST] = LAYOUT_split_3x6_3(
    // ╭───────────┬───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────┬───────╮
        XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,SGUI(KC_4),SGUI(KC_5),LGUI(LALT(KC_I)),XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,QK_BOOT,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        RGB_TOG,    RGB_HUI,RGB_SAI,RGB_VAI,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        RGB_MOD,    RGB_HUD,RGB_SAD,RGB_VAD,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,EE_CLR, XXXXXXX,
    // ╰───────────┴───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┼───────┴───────┴───────┴───────╯
                                    KC_ENT, KC_LGUI, _______,    _______, KC_SPC, KC_RALT
    //                             ╰───────┴───────┴───────╯   ╰───────┴───────╯
    ),

    // ========================================================================
    // LAYER 4: POINTER (unused, placeholder for shared code)
    // ========================================================================
    [_POINTER] = LAYOUT_split_3x6_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
    ),

    // ========================================================================
    // LAYER 5: RECT (unused, placeholder for shared code)
    // ========================================================================
    [_RECT] = LAYOUT_split_3x6_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
    ),

    // ========================================================================
    // LAYER 6: RALT (AltGr symbols)
    // ========================================================================
    [_RALT] = LAYOUT_split_3x6_3(
    // ╭───────────┬───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────┬───────╮
        XXXXXXX,    ES_PIPE,ES_AT,  ES_HASH,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,    XXXXXXX,XXXXXXX,ES_EURO,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
    // ╰───────────┴───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┼───────┴───────┴───────┴───────╯
                                    XXXXXXX,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,_______
    //                             ╰───────┴───────┴───────╯   ╰───────┴───────╯
    ),
};
// clang-format on

// ============================================================================
// OLED
// ============================================================================

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
        case _RALT:
            oled_write_ln_P(PSTR("AltGr"), false);
            break;
        default:
            oled_write_ln_P(PSTR("???"), false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
    return false;
}
#endif
