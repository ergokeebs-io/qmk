#pragma once

#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

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
    _RALT,
};

// ============================================================================
// CUSTOM KEYCODES
// ============================================================================

enum ergokeebs_keycodes {
    // ES Layout: real backtick (dead grave + space)
    MY_BKTK = SAFE_RANGE,
    // Unicode: < and > for non-ISO Spanish
    MY_LABK,
    MY_RABK,
    // Tilde for non-ISO Spanish (Alt+ñ)
    MY_TILD,
    // Plus and asterisk for non-ISO Spanish
    MY_PLUS,
    MY_ASTR,

    // Rectangle window management
    RECT_L,                 // Left Half (1/2)
    RECT_R,                 // Right Half (1/2)
    RECT_13L,               // First Third (1/3)
    RECT_13R,               // Last Third (1/3)
    RECT_14L,               // First Fourth (1/4)
    RECT_14R,               // Last Fourth (1/4)
    RECT_16L,               // First Sixth (1/6)
    RECT_16R,               // Last Sixth (1/6)

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
#define RALT_LY MO(_RALT)
