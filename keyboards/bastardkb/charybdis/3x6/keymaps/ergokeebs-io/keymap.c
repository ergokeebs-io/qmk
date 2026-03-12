/**
 * Charybdis 3x6 Keymap
 * ergokeebs-io
 *
 * Layout based on personal Corne config with trackball support.
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
    [_BASE] = LAYOUT(
    // ╭───────────┬───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────┬───────╮
        TD_TESC,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        OSM_SFT,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,       KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        KC_LCTL,    PT_Z,   PT_X,   KC_C,   KC_V,   KC_B,       KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,RALT_LY,
    // ╰───────────┴───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┼───────┴───────┴───────┴───────╯
                                    KC_ENT, KC_LGUI, LOWER,      RAISE,  KC_SPC
    //                             ╰───────┴───────┴───────╯   ╰───────┴───────╯
    ),

    // ========================================================================
    // LAYER 1: LOWER (Numbers + Navigation)
    // ========================================================================
    [_LOWER] = LAYOUT(
    // ╭───────────┬───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────┬───────╮
        KC_ESC,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_BSPC,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        KC_LSFT,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    KC_LEFT,KC_UP,  KC_DOWN,KC_RGHT,MY_TILD,XXXXXXX,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        KC_LCTL,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    KC_HOME,KC_PGDN,KC_PGUP,KC_END, XXXXXXX,XXXXXXX,
    // ╰───────────┴───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┼───────┴───────┴───────┴───────╯
                                    KC_ENT, KC_LGUI, _______,    _______, KC_SPC
    //                             ╰───────┴───────┴───────╯   ╰───────┴───────╯
    ),

    // ========================================================================
    // LAYER 2: RAISE (Symbols)
    // Brackets on home row: openers left, closers right
    // ========================================================================
    [_RAISE] = LAYOUT(
    // ╭───────────┬───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────┬───────╮
        KC_ESC,     ES_EXLM,ES_DQUO,ES_BULT,ES_DLR, ES_PERC,    ES_AMPR,ES_SLSH,ES_LPRN,ES_RPRN,ES_EQL, KC_BSPC,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        KC_LSFT,    ES_LPRN,ES_LCBR,ES_LBRC,MY_LABK,XXXXXXX,    XXXXXXX,MY_RABK,ES_RBRC,ES_RCBR,ES_RPRN,MY_BKTK,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        KC_LCTL,    KC_UNDS,ES_PLUS,KC_BSLS,KC_PIPE,XXXXXXX,    ES_QUES,XXXXXXX,MY_ASTR,MY_PLUS,XXXXXXX,XXXXXXX,
    // ╰───────────┴───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┼───────┴───────┴───────┴───────╯
                                    KC_ENT, KC_LGUI, _______,    _______, KC_SPC
    //                             ╰───────┴───────┴───────╯   ╰───────┴───────╯
    ),

    // ========================================================================
    // LAYER 3: ADJUST (Config)
    // Activated by holding LOWER + RAISE
    // ========================================================================
    [_ADJUST] = LAYOUT(
    // ╭───────────┬───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────┬───────╮
        XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,SGUI(KC_4),SGUI(KC_5),LGUI(LALT(KC_I)),XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,QK_BOOT,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,EE_CLR, XXXXXXX,
    // ╰───────────┴───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┼───────┴───────┴───────┴───────╯
                                    KC_ENT, KC_LGUI, _______,    _______, KC_SPC
    //                             ╰───────┴───────┴───────╯   ╰───────┴───────╯
    ),

    // ========================================================================
    // LAYER 4: POINTER (Trackball)
    // Activated by holding Z
    // ========================================================================
    [_POINTER] = LAYOUT(
    // ╭───────────┬───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────┬───────╮
        XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,DPI_MOD,S_D_MOD,    S_D_MOD,DPI_MOD,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,    KC_LGUI,KC_LALT,KC_LCTL,KC_LSFT,XXXXXXX,    XXXXXXX,KC_RSFT,KC_RCTL,KC_RALT,KC_RGUI,XXXXXXX,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,    _______,DRGSCRL,SNIPING,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    // ╰───────────┴───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┼───────┴───────┴───────┴───────╯
                                    KC_BTN2,KC_BTN1,KC_BTN3,    KC_BTN1,KC_BTN2
    //                             ╰───────┴───────┴───────╯   ╰───────┴───────╯
    ),

    // ========================================================================
    // LAYER 5: RECTANGLE (Window Management)
    // Activated by holding X
    // Left hand: screen position map (QWE/ASD/ZV)
    // Right hand: thirds (UIO/JKL)
    // ========================================================================
    [_RECT] = LAYOUT(
    // ╭───────────┬───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────┬───────╮
        XXXXXXX,    RECT_TL,RECT_T, RECT_TR,XXXXXXX,XXXXXXX,    XXXXXXX,RECT_23L,RECT_23C,RECT_23R,XXXXXXX,XXXXXXX,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,    RECT_L, RECT_C, RECT_R, XXXXXXX,XXXXXXX,    XXXXXXX,RECT_13L,RECT_13C,RECT_13R,XXXXXXX,XXXXXXX,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,    XXXXXXX,_______,RECT_BR,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    // ╰───────────┴───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┼───────┴───────┴───────┴───────╯
                                    XXXXXXX,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX
    //                             ╰───────┴───────┴───────╯   ╰───────┴───────╯
    ),

    // ========================================================================
    // LAYER 6: RALT (AltGr symbols)
    // Activated by holding RALT key
    // @ and # on number row positions 2 and 3
    // ========================================================================
    [_RALT] = LAYOUT(
    // ╭───────────┬───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────┬───────╮
        XXXXXXX,    ES_PIPE,ES_AT,  ES_HASH,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,    XXXXXXX,XXXXXXX,ES_EURO,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
    // ╰───────────┴───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┼───────┴───────┴───────┴───────╯
                                    XXXXXXX,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX
    //                             ╰───────┴───────┴───────╯   ╰───────┴───────╯
    ),
};
// clang-format on

// ============================================================================
// CHARYBDIS-SPECIFIC: Auto sniping on pointer layer
// ============================================================================

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_kb(layer_state_t state) {
    state = layer_state_set_user(state);
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, _POINTER));
    return state;
}
#    endif
#endif
