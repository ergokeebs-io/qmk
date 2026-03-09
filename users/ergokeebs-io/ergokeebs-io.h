#pragma once

#include QMK_KEYBOARD_H

// ============================================================================
// LAYERS
// ============================================================================

enum ergokeebs_layers {
    _BASE = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _POINTER,
    _RECT,
};

// ============================================================================
// CUSTOM KEYCODES
// ============================================================================

enum ergokeebs_keycodes {
    // ES Layout hacks
    ES_AT = SAFE_RANGE,     // @
    ES_GRV,                 // ` (backtick)
    ES_QUES,                // ?
    ES_TILD,                // ~
    ES_PIPE,                // |

    // Rectangle window management
    RECT_TL,                // Top Left
    RECT_T,                 // Top Half
    RECT_TR,                // Top Right
    RECT_L,                 // Left Half
    RECT_C,                 // Center
    RECT_R,                 // Right Half
    RECT_BL,                // Bottom Left
    RECT_BR,                // Bottom Right
    RECT_13L,               // First Third
    RECT_13C,               // Center Third
    RECT_13R,               // Last Third
    RECT_23L,               // First Two Thirds
    RECT_23C,               // Center Two Thirds
    RECT_23R,               // Last Two Thirds

    // Password/macros
    MY_PWD,

    // Safe range for keyboard-specific keycodes
    ERGOKEEBS_SAFE_RANGE,
};

// ============================================================================
// TAP DANCE
// ============================================================================

#ifdef TAP_DANCE_ENABLE
enum ergokeebs_tap_dances {
    TD_TAB_ESC,
};

#define TD_TESC TD(TD_TAB_ESC)
#endif

// ============================================================================
// LAYER TAP SHORTCUTS
// ============================================================================

#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define PT_Z    LT(_POINTER, KC_Z)
#define PT_X    LT(_RECT, KC_X)

// ============================================================================
// MOD TAP SHORTCUTS
// ============================================================================

#define OSM_SFT OSM(MOD_LSFT)
