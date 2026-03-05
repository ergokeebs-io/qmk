SRC += ergokeebs-io.c

# Common features
CAPS_WORD_ENABLE = yes
TAP_DANCE_ENABLE = yes
SEND_STRING_ENABLE = yes

# Optimizations
LTO_ENABLE = yes

# Disabled features (can be overridden per-keyboard)
MOUSEKEY_ENABLE = no
OLED_ENABLE = no
