/**
 * Dactyl Manuform 5x6 Keymap
 * ergokeebs-io
 *
 * Spanish layout with shared ergokeebs-io code.
 * Extra row for numbers, larger thumb cluster.
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
    [_BASE] = LAYOUT_5x6(
    // ╭───────────┬───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────┬───────╮
        KC_ESC,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_BSPC,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        TD_TESC,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   ES_MINS,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        OSM_SFT,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,       KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        KC_LCTL,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,       KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,RALT_LY,
    // ╰───────────┴───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┴───────┴───────┴───────┴───────╯
                            ES_LBRC,ES_RBRC,                                    ES_PLUS,ES_EQL,
    //                     ╰───────┴───────╯                                   ╰───────┴───────╯
    //                             ╭───────┬───────╮                   ╭───────┬───────╮
                                    KC_SPC, KC_LALT,                    KC_ENT, KC_SPC,
    //                             ├───────┼───────┤                   ├───────┼───────┤
                                    KC_LGUI,LOWER,                      RAISE,  KC_RGUI,
    //                             ├───────┼───────┤                   ├───────┼───────┤
                                    KC_BTN1,KC_BTN2,                    KC_BTN1,KC_BTN2
    //                             ╰───────┴───────╯                   ╰───────┴───────╯
    ),

    // ========================================================================
    // LAYER 1: LOWER (Navigation + Function keys)
    // ========================================================================
    [_LOWER] = LAYOUT_5x6(
    // ╭───────────┬───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────┬───────╮
        KC_F12,     KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,      KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        _______,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_DEL,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        _______,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    KC_LEFT,KC_UP,  KC_DOWN,KC_RGHT,MY_TILD,XXXXXXX,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        _______,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    KC_HOME,KC_PGDN,KC_PGUP,KC_END, XXXXXXX,XXXXXXX,
    // ╰───────────┴───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┴───────┴───────┴───────┴───────╯
                            _______,_______,                                    _______,_______,
                                    _______,_______,                    _______,_______,
                                    _______,_______,                    _______,_______,
                                    _______,_______,                    _______,_______
    ),

    // ========================================================================
    // LAYER 2: RAISE (Symbols)
    // ========================================================================
    [_RAISE] = LAYOUT_5x6(
    // ╭───────────┬───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────┬───────╮
        _______,    ES_EXLM,ES_DQUO,ES_BULT,ES_DLR, ES_PERC,    ES_AMPR,ES_SLSH,ES_LPRN,ES_RPRN,ES_EQL, _______,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        _______,    XXXXXXX,ES_AT,  ES_HASH,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        _______,    ES_LPRN,ES_LCBR,ES_LBRC,MY_LABK,XXXXXXX,    XXXXXXX,MY_RABK,ES_RBRC,ES_RCBR,ES_RPRN,MY_BKTK,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        _______,    KC_UNDS,ES_PLUS,KC_BSLS,KC_PIPE,XXXXXXX,    ES_QUES,XXXXXXX,MY_ASTR,MY_PLUS,ES_EURO,XXXXXXX,
    // ╰───────────┴───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┴───────┴───────┴───────┴───────╯
                            _______,_______,                                    _______,_______,
                                    _______,_______,                    _______,_______,
                                    _______,_______,                    _______,_______,
                                    _______,_______,                    _______,_______
    ),

    // ========================================================================
    // LAYER 3: ADJUST (Config)
    // ========================================================================
    [_ADJUST] = LAYOUT_5x6(
    // ╭───────────┬───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────┬───────╮
        XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,QK_BOOT,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,SGUI(KC_4),SGUI(KC_5),LGUI(LALT(KC_I)),XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,EE_CLR, XXXXXXX,
    // ╰───────────┴───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┴───────┴───────┴───────┴───────╯
                            XXXXXXX,XXXXXXX,                                    XXXXXXX,XXXXXXX,
                                    XXXXXXX,XXXXXXX,                    XXXXXXX,XXXXXXX,
                                    _______,_______,                    _______,_______,
                                    XXXXXXX,XXXXXXX,                    XXXXXXX,XXXXXXX
    ),

    // ========================================================================
    // LAYER 4: POINTER (placeholder - no trackball)
    // ========================================================================
    [_POINTER] = LAYOUT_5x6(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX,                                        XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX
    ),

    // ========================================================================
    // LAYER 5: RECT (Window Management)
    // Symmetric: left hand = move left, right hand = move right
    // Ring=1/6, Middle=1/4, Index=1/3, Inner index=1/2
    // ========================================================================
    [_RECT] = LAYOUT_5x6(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, RECT_16L,RECT_14L,RECT_13L,RECT_L,     RECT_R,  RECT_13R,RECT_14R,RECT_16R,XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX,                                        XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX
    ),

    // ========================================================================
    // LAYER 6: RALT (AltGr symbols)
    // ========================================================================
    [_RALT] = LAYOUT_5x6(
    // ╭───────────┬───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────┬───────╮
        XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,    ES_PIPE,ES_AT,  ES_HASH,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,    XXXXXXX,XXXXXXX,ES_EURO,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    // ├───────────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
        XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
    // ╰───────────┴───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┴───────┴───────┴───────┴───────╯
                            XXXXXXX,XXXXXXX,                                    XXXXXXX,XXXXXXX,
                                    XXXXXXX,XXXXXXX,                    XXXXXXX,XXXXXXX,
                                    XXXXXXX,XXXXXXX,                    XXXXXXX,XXXXXXX,
                                    XXXXXXX,XXXXXXX,                    XXXXXXX,XXXXXXX
    ),
};
// clang-format on
