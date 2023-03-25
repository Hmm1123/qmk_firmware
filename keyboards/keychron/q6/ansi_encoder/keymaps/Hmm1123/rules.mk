VIA_ENABLE = yes
ENCODER_MAP_ENABLE = yes
MOUSEKEY_ENABLE = no
UNICODE_ENABLE = yes

RGB_MATRIX_CUSTOM_USER = yes
DYNAMIC_TAPPING_TERM_ENABLE = yes
CONSOLE_ENABLE = yes

SRC += rgb_matrix/rgb_matrix_custom.c
SRC += user-config/user_eeconfig.c
SRC += user-config/user_data.c
SRC += via_custom_commands.c
SRC += tap_hold.c