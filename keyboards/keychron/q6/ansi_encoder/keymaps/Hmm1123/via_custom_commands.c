#include <rgb_matrix/rgb_matrix_custom.h>

enum via_custom_value {
    id_background_light_speed = 1,
    id_reactive_light_speed,
};

static void via_custom_save(void) {
#ifdef CUSTOM_USER_EECONFIG
    write_user_eeprom_data_to_eeprom();
#else
    dprintf("called via_custom_save but custom user eeconfig isn't activated. Nothing will get saved to eeconfig. Please #define CUSTOM_USER_EECONFIG in config.h");
#endif
}

static void via_custom_get_value(uint8_t *data) {
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch (*value_id) {
        case id_background_light_speed:
            *value_data = rgb_matrix_get_bg_speed_raw();
            break;
        case id_reactive_light_speed:
            *value_data = rgb_matrix_get_reactive_speed_raw();
            break;
    }
}

static void via_custom_set_value(uint8_t *data) {
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch (*value_id) {
        case id_background_light_speed:
            rgb_matrix_set_bg_speed_noeeprom(*value_data);
            break;
        case id_reactive_light_speed:
            rgb_matrix_set_reactive_speed_noeeprom(*value_data);
            break;
    }
}

void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id        = &(data[0]);
    uint8_t *channel_id        = &(data[1]);
    uint8_t *value_id_and_data = &(data[2]);

    if (*channel_id == id_custom_channel) {
        switch (*command_id) {
            case id_custom_save:
                via_custom_save();
                break;
            case id_custom_get_value:
                via_custom_get_value(value_id_and_data);
                break;
            case id_custom_set_value:
                via_custom_set_value(value_id_and_data);
                break;
            default:
                *command_id = id_unhandled;
                break;
        }
        return;
    }
    *command_id = id_unhandled;
}
