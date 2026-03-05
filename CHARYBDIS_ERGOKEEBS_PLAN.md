# Charybdis 3x6 Ergokeebs Keymap Plan

## Objetivo

Migrar el layout personalizado de Corne (`keyboards/crkbd/keymaps/ergokeebs/`) al Charybdis 3x6 con trackball, manteniendo la misma experiencia de uso y añadiendo funcionalidades del trackball + gestión de ventanas con Rectangle.

---

## Diferencias Físicas: Corne vs Charybdis 3x6

| Característica | Corne | Charybdis 3x6 |
|----------------|-------|---------------|
| Layout | 3x6 | 3x6 |
| Thumbs izquierda | 3 | 3 |
| Thumbs derecha | 3 | 2 + trackball |
| Total thumbs | 6 | 5 |
| Trackball | No | Sí |

**Impacto:** Perdemos un thumb en la derecha. El `RALT` del thumb se mueve a la columna externa.

---

## Layers

### Layer 0 — BASE (QWERTY)

```
┌───────────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬───────┐
│TAB / 2xESC│  Q  │  W  │  E  │  R  │  T  │     │  Y  │  U  │  I  │  O  │  P  │ BSPC  │
├───────────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼───────┤
│  OSM SFT  │  A  │  S  │  D  │  F  │  G  │     │  H  │  J  │  K  │  L  │  ;  │   '   │
├───────────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼───────┤
│   LCTL    │PT_Z │PT_X │  C  │  V  │  B  │     │  N  │  M  │  ,  │  .  │  /  │ RALT  │
└───────────┴─────┴─────┴─────┴─────┴─────┘     └─────┴─────┴─────┴─────┴─────┴───────┘
                        ┌─────┬─────┬─────┐     ┌─────┬─────┐
                        │ GUI │MO(1)│ ENT │     │ SPC │MO(2)│ TRACKBALL
                        └─────┴─────┴─────┘     └─────┴─────┘
```

**Keycodes especiales:**
- `TAB / 2xESC` = Tap Dance: single tap → Tab, double tap → Esc
- `OSM SFT` = One-Shot Modifier Shift
- `PT_Z` = `LT(LAYER_POINTER, KC_Z)` — Hold → Pointer Layer, Tap → Z
- `PT_X` = `LT(LAYER_RECT, KC_X)` — Hold → Rectangle Layer, Tap → X

---

### Layer 1 — LOWER (Números + Navegación)

Activación: `MO(1)` (thumb izquierdo centro)

```
┌───────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬───────┐
│  ESC  │  1  │  2  │  3  │  4  │  5  │     │  6  │  7  │  8  │  9  │  0  │ BSPC  │
├───────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼───────┤
│ LSFT  │     │     │     │     │     │     │  ←  │  ↓  │  ↑  │  →  │     │       │
├───────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼───────┤
│ LCTL  │     │     │     │     │     │     │HOME │PGDN │PGUP │ END │     │       │
└───────┴─────┴─────┴─────┴─────┴─────┘     └─────┴─────┴─────┴─────┴─────┴───────┘
                    ┌─────┬─────┬─────┐     ┌─────┬─────┐
                    │ GUI │ ▼▼▼ │ ENT │     │ SPC │MO(3)│ TRACKBALL
                    └─────┴─────┴─────┘     └─────┴─────┘
```

---

### Layer 2 — RAISE (Símbolos)

Activación: `MO(2)` (thumb derecho)

**Diseño:** Brackets en home row, apertura en izquierda, cierre en derecha.

```
┌───────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬───────┐
│  ESC  │  !  │  @  │  #  │  $  │  %  │     │  ^  │  &  │  *  │  -  │  =  │ BSPC  │
├───────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼───────┤
│ LSFT  │  (  │  {  │  [  │  <  │     │     │     │  >  │  ]  │  }  │  )  │   `   │
├───────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼───────┤
│ LCTL  │  _  │  +  │  \  │  |  │     │     │     │  ?  │  /  │  ~  │     │       │
└───────┴─────┴─────┴─────┴─────┴─────┘     └─────┴─────┴─────┴─────┴─────┴───────┘
                    ┌─────┬─────┬─────┐     ┌─────┬─────┐
                    │ GUI │MO(3)│ ENT │     │ SPC │ ▼▼▼ │ TRACKBALL
                    └─────┴─────┴─────┘     └─────┴─────┘
```

**Home row (fila 2) — Brackets pareados:**
- Izquierda: `( { [ <` — los que abren (dedos meñique→índice)
- Derecha: `> ] } )` — los que cierran (dedos índice→meñique, simetría)

**Keycodes especiales para ES layout:**

| Tecla visual | Keycode real | Nota |
|--------------|--------------|------|
| `@` | `ES_AT` → `RALT(KC_2)` | Custom keycode |
| `` ` `` | `ES_GRV` → `RALT(KC_LBRC)` | Custom keycode |
| `?` | `ES_QUES` → `LSFT(KC_MINS)` o `SEND_STRING` | Custom keycode |
| `~` | `ES_TILD` → `RALT(KC_4)` | Custom keycode |

---

### Layer 3 — ADJUST (Config + Sistema)

Activación: `MO(1) + MO(2)` (ambos layers activos)

```
┌───────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬───────┐
│       │     │     │     │     │     │     │     │     │     │     │     │ BOOT  │
├───────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼───────┤
│       │     │     │     │     │     │     │     │     │     │     │     │       │
├───────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼───────┤
│       │     │     │     │     │     │     │     │     │     │     │EPRST│       │
└───────┴─────┴─────┴─────┴─────┴─────┘     └─────┴─────┴─────┴─────┴─────┴───────┘
                    ┌─────┬─────┬─────┐     ┌─────┬─────┐
                    │ GUI │ ▼▼▼ │ ENT │     │ SPC │ ▼▼▼ │ TRACKBALL
                    └─────┴─────┴─────┘     └─────┴─────┘
```

**Nota:** Este layer queda casi vacío sin RGB. Espacio disponible para futuras funciones (media keys, macros, etc.).

---

### Layer 4 — POINTER (Trackball)

Activación: Hold `Z` (`PT_Z`)

```
┌───────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬───────┐
│       │     │     │     │DPI+ │S_DPI│     │     │     │     │     │     │       │
├───────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼───────┤
│       │ GUI │ ALT │ CTL │ SFT │     │     │     │ SFT │ CTL │ ALT │ GUI │       │
├───────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼───────┤
│       │▼▼Z▼▼│DRGSC│SNIPE│     │     │     │     │     │     │     │     │       │
└───────┴─────┴─────┴─────┴─────┴─────┘     └─────┴─────┴─────┴─────┴─────┴───────┘
                    ┌─────┬─────┬─────┐     ┌─────┬─────┐
                    │BTN2 │BTN1 │BTN3 │     │BTN1 │BTN2 │ TRACKBALL
                    └─────┴─────┴─────┘     └─────┴─────┘
```

**Funciones trackball:**
- `DPI+` / `S_DPI` = Ajustar DPI normal / sniping
- `DRGSC` = Drag Scroll (trackball = scroll)
- `SNIPE` = Modo precisión (DPI bajo)
- `BTN1/2/3` = Click izquierdo / derecho / medio
- Home row mods para Ctrl+Click, Shift+Click, etc.

---

### Layer 5 — RECTANGLE (Gestión de ventanas)

Activación: Hold `X` (`PT_X`)

```
┌───────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬───────┐
│       │ ↖TL │ TOP │ ↗TR │     │     │     │     │2/3 L│2/3 C│2/3 R│     │       │
│       │⌃⌥U  │⌃⌥↑  │⌃⌥I  │     │     │     │     │⌃⌥E  │⌃⌥R  │⌃⌥T  │     │       │
├───────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼───────┤
│       │LEFT │ CTR │RIGHT│     │     │     │     │ ⅓ L │ ⅓ C │ ⅓ R │     │       │
│       │⌃⌥←  │⌃⌥↓  │⌃⌥→  │     │     │     │     │⌃⌥D  │⌃⌥F  │⌃⌥G  │     │       │
├───────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼───────┤
│       │ ↙BL │     │ ↘BR │     │     │     │     │     │     │     │     │       │
│       │⌃⌥J  │     │⌃⌥K  │     │     │     │     │     │     │     │     │       │
└───────┴─────┴─────┴─────┴─────┴─────┘     └─────┴─────┴─────┴─────┴─────┴───────┘
```

**Mano izquierda — Mapa de pantalla (QWE/ASD/ZV):**

| Tecla | Posición | Macro |
|-------|----------|-------|
| Q | Top Left ↖ | `LCTL(LALT(KC_U))` |
| W | Top Half | `LCTL(LALT(KC_UP))` |
| E | Top Right ↗ | `LCTL(LALT(KC_I))` |
| A | Left Half | `LCTL(LALT(KC_LEFT))` |
| S | Center | `LCTL(LALT(KC_DOWN))` |
| D | Right Half | `LCTL(LALT(KC_RGHT))` |
| Z | Bottom Left ↙ | `LCTL(LALT(KC_J))` |
| V | Bottom Right ↘ | `LCTL(LALT(KC_K))` |

**Mano derecha — Tercios (UIO/JKL):**

| Tecla | Acción | Macro |
|-------|--------|-------|
| U | First 2/3 | `LCTL(LALT(KC_E))` |
| I | Center 2/3 | `LCTL(LALT(KC_R))` |
| O | Last 2/3 | `LCTL(LALT(KC_T))` |
| J | First ⅓ | `LCTL(LALT(KC_D))` |
| K | Center ⅓ | `LCTL(LALT(KC_F))` |
| L | Last ⅓ | `LCTL(LALT(KC_G))` |

---

## Features QMK

### Tap Dance

| ID | Single Tap | Double Tap |
|----|------------|------------|
| `TD_TAB_ESC` | `KC_TAB` | `KC_ESC` |

### One-Shot Modifiers

- `OSM(MOD_LSFT)` en posición Shift izquierdo

### Layer Tap

- `PT_Z` = `LT(LAYER_POINTER, KC_Z)`
- `PT_X` = `LT(LAYER_RECT, KC_X)`

### Caps Word

- `CAPS_WORD_ENABLE = yes`
- `DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD`

---

## Hacks para Layout Español (macOS)

El SO está configurado con layout español. Algunos caracteres requieren keycodes especiales.

### Problema: Keycodes US vs ES

| Carácter | US Layout | ES Layout (hack) |
|----------|-----------|------------------|
| `@` | `KC_AT` / `Shift+2` | `RALT(KC_2)` |
| `` ` `` (backtick) | `KC_GRV` | `RALT(KC_LBRC)` |
| `?` | `Shift + /` | `LSFT(KC_MINS)` ó `SEND_STRING("?")` |
| `~` | `Shift + `` ` `` | `RALT(KC_4)` ó `RALT(KC_RBRC)` |

### Implementación en keymap.c

```c
// Custom keycodes para ES layout
enum custom_keycodes {
    ES_AT = SAFE_RANGE,    // @
    ES_GRV,                // ` (backtick)
    ES_QUES,               // ?
    ES_TILD,               // ~
};

// En process_record_user:
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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
                // Opción 1: Probar keycode directo
                tap_code16(LSFT(KC_MINS));
                // Opción 2: Si no funciona, usar SEND_STRING
                // SEND_STRING("?");
            }
            return false;
        case ES_TILD:
            if (record->event.pressed) {
                tap_code16(RALT(KC_4));
            }
            return false;
    }
    return true;
}
```

### Alternativa: Unicode (requiere configuración macOS)

```c
// En config.h
#define UNICODE_SELECTED_MODES UC_MAC

// En keymap.c
UC(0x0040)  // @ via Unicode
UC(0x0060)  // ` via Unicode
UC(0x003F)  // ? via Unicode
UC(0x007E)  // ~ via Unicode
```

**Nota:** Unicode requiere que macOS tenga habilitado el input method "Unicode Hex Input":
1. System Preferences → Keyboard → Input Sources
2. Añadir "Unicode Hex Input"
3. Puede no funcionar en todas las apps

**Recomendación:** Usar custom keycodes con `RALT()` o `SEND_STRING()` — más fiable que Unicode.

### Shift + Backspace = Delete

Heredado del Dactyl Manuform:

```c
case KC_BSPC:
    if (record->event.pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
            del_mods(MOD_MASK_SHIFT);
            register_code(KC_DEL);
            set_mods(mod_state);
            return false;
        }
    } else {
        unregister_code(KC_DEL);
    }
    return true;
```

---

## Archivos a Crear

```
keyboards/bastardkb/charybdis/3x6/keymaps/ergokeebs/
├── config.h       # Configuración (tapping term, RGB, etc.)
├── keymap.c       # Layout + tap dance + macros
├── rules.mk       # Features habilitadas
└── readme.md      # Documentación del keymap
```

---

## Configuración config.h

```c
#pragma once

#define MASTER_RIGHT                          // Mano derecha es master (tiene trackball)
#define SPLIT_USB_DETECT
#define TAPPING_TERM 200
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// Trackball
#define CHARYBDIS_MINIMUM_DEFAULT_DPI 800     // DPI base alto para movimientos rápidos
#define CHARYBDIS_MINIMUM_SNIPING_DPI 200     // DPI bajo para precisión
#define CHARYBDIS_DRAGSCROLL_REVERSE_Y        // Invertir scroll vertical (opcional)
```

---

## rules.mk

```makefile
MOUSEKEY_ENABLE = no
OLED_ENABLE = no
LTO_ENABLE = yes
CAPS_WORD_ENABLE = yes
TAP_DANCE_ENABLE = yes
SEND_STRING_ENABLE = yes        # Para macros ES layout (si se usa SEND_STRING)
POINTING_DEVICE_ENABLE = yes    # Ya habilitado por defecto en Charybdis
```

---

## Próximos Pasos

1. [ ] Crear carpeta `keyboards/bastardkb/charybdis/3x6/keymaps/ergokeebs/`
2. [ ] Crear `config.h`
3. [ ] Crear `rules.mk`
4. [ ] Crear `keymap.c` con todos los layers
5. [ ] Compilar y testear: `qmk compile -kb bastardkb/charybdis/3x6 -km ergokeebs`
6. [ ] Flash y probar en el teclado
7. [ ] Ajustar DPI del trackball según preferencia
8. [ ] Ajustar tapping term si hay problemas con tap dance o layer tap
