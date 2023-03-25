#include "rgb_matrix_custom.h"
#include "user-config/user_data.h"

// globals
#ifdef RGB_MATRIX_BG_REACTIVE_EFFECT
rgb_custom_config_t* rgb_custom_config_ptr = &(user_data.rgb_config);
#endif // RGB_MATRIX_BG_REACTIVE_EFFECT

// speed helpers
#ifdef RGB_MATRIX_BG_REACTIVE_EFFECT
void reset_rgb_custom_config(void) {
    rgb_custom_config_ptr->background_speed = RGB_MATRIX_BG_REACTIVE_DEFAULT_BG_SPEED;
    rgb_custom_config_ptr->reactive_speed   = RGB_MATRIX_BG_REACTIVE_DEFAULT_REACTIVE_SPEED;
}

void rgb_matrix_set_custom_speed_eeprom_helper(uint8_t speed, bool write_to_eeprom, bool bg) {
    if (bg)
        rgb_custom_config_ptr->background_speed = speed;
    else
        rgb_custom_config_ptr->reactive_speed = speed;

#ifdef CUSTOM_USER_EECONFIG
    if (write_to_eeprom) {
        write_user_eeprom_data_to_eeprom();
    }
#endif
    dprintf("rgb matrix set CUSTOM %s speed [%s]: %u\n", (bg ? "background" : "reactive"), (write_to_eeprom ? "EEPROM" : "NOEEPROM"), (bg ? rgb_custom_config_ptr->background_speed : rgb_custom_config_ptr->reactive_speed));
}

// set bg speed
void rgb_matrix_set_bg_speed_noeeprom(uint8_t speed) {
    rgb_matrix_set_custom_speed_eeprom_helper(speed, false, true);
}
void rgb_matrix_set_bg_speed(uint8_t speed) {
    rgb_matrix_set_custom_speed_eeprom_helper(speed, true, true);
}

// set reactive speed
void rgb_matrix_set_reactive_speed_noeeprom(uint8_t speed) {
    rgb_matrix_set_custom_speed_eeprom_helper(speed, false, false);
}
void rgb_matrix_set_reactive_speed(uint8_t speed) {
    rgb_matrix_set_custom_speed_eeprom_helper(speed, true, false);
}

// get bg speed
uint8_t rgb_matrix_get_bg_speed(bool raw) {
    if (raw) return rgb_custom_config_ptr->background_speed;
    return scale8(rgb_custom_config_ptr->background_speed, rgb_matrix_config.speed);
}
/**
 * @return The raw bg speed value
 */
uint8_t rgb_matrix_get_bg_speed_raw(void) {
    return rgb_matrix_get_bg_speed(true);
}
/**
 * @return The bg animation speed scaled by the overall speed
 */
uint8_t rgb_matrix_get_bg_speed_scaled(void) {
    return rgb_matrix_get_bg_speed(false);
}

// get reactive speed
uint8_t rgb_matrix_get_reactive_speed(bool raw) {
    if (raw)
        return rgb_custom_config_ptr->reactive_speed;
    else
        return scale8(rgb_custom_config_ptr->reactive_speed, rgb_matrix_config.speed);
}
uint8_t rgb_matrix_get_reactive_speed_raw(void) {
    return rgb_matrix_get_reactive_speed(true);
}

/**
 * @return The reactive animation speed scaled by the overall speed
 */
uint8_t rgb_matrix_get_reactive_speed_scaled(void) {
    return rgb_matrix_get_reactive_speed(false);
}

// increase speed helper
void rgb_matrix_increase_custom_speed_helper(bool write_to_eeprom, bool bg) {
    rgb_matrix_set_custom_speed_eeprom_helper(qadd8(bg ? rgb_custom_config_ptr->background_speed : rgb_custom_config_ptr->reactive_speed, RGB_MATRIX_BG_REACTIVE_DEFAULT_SPEED_STEP), write_to_eeprom, bg);
}

// increase bg speed
void rgb_matrix_increase_bg_speed(void) {
    rgb_matrix_increase_custom_speed_helper(true, true);
}
void rgb_matrix_increase_bg_speed_noeeprom(void) {
    rgb_matrix_increase_custom_speed_helper(false, true);
}

// increase reactive speed
void rgb_matrix_increase_reactive_speed(void) {
    rgb_matrix_increase_custom_speed_helper(true, false);
}
void rgb_matrix_increase_reactive_speed_noeeprom(void) {
    rgb_matrix_increase_custom_speed_helper(false, false);
}

void rgb_matrix_decrease_custom_speed_helper(bool write_to_eeprom, bool bg) {
    rgb_matrix_set_custom_speed_eeprom_helper(qsub8(bg ? rgb_custom_config_ptr->background_speed : rgb_custom_config_ptr->reactive_speed, RGB_MATRIX_BG_REACTIVE_DEFAULT_SPEED_STEP), write_to_eeprom, bg);
}

// decrease bg speed
void rgb_matrix_decrease_bg_speed(void) {
    rgb_matrix_decrease_custom_speed_helper(true, true);
}
void rgb_matrix_decrease_bg_speed_noeeprom(void) {
    rgb_matrix_decrease_custom_speed_helper(false, true);
}

// decrease reactive speed
void rgb_matrix_decrease_reactive_speed(void) {
    rgb_matrix_decrease_custom_speed_helper(true, false);
}
void rgb_matrix_decrease_reactive_speed_noeeprom(void) {
    rgb_matrix_decrease_custom_speed_helper(false, false);
}
#endif // RGB_MATRIX_BG_REACTIVE_EFFECT
