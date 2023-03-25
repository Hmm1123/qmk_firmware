#include <rgb_matrix/rgb_matrix_custom.h>
#include "user_data.h"

#ifdef CUSTOM_USER_EECONFIG

void write_user_eeprom_data_to_eeprom(void) {
    const uint32_t old_data = eeconfig_read_user();
    // we have infinite eeprom READS, but limited WRITES
    // so check if we really need to write
    if (old_data != user_data.raw) {
        eeconfig_update_user(user_data.raw);
    }
}

void keyboard_post_init_user_eeconfig(void) {
    user_data.raw = eeconfig_read_user();
}

void eeconfig_init_user(void) {
#    ifdef RGB_MATRIX_BG_REACTIVE_EFFECT
    rgb_custom_config_eeconfig_init();
#    endif // RGB_MATRIX_BG_REACTIVE_EFFECT
    write_user_eeprom_data_to_eeprom();
}
#endif // CUSTOM_USER_EECONFIG