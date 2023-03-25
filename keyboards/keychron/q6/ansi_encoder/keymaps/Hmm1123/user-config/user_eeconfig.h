#pragma once
#include "eeconfig.h"
#include "rgb_matrix/rgb_matrix_types_custom.h"

#ifdef CUSTOM_USER_EECONFIG
void keyboard_post_init_user_eeconfig(void);

// eeprom / eeconfig
void write_user_eeprom_data_to_eeprom(void);
#endif // CUSTOM_USER_EECONFIG

//#include "user_eeconfig.c"
