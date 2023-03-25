#pragma once
#include "rgb_matrix_types_custom.h"
#include "lib/lib8tion/lib8tion.h"
#include "quantum.h"
#include "user-config/user_eeconfig.h"
#include "rgb_matrix.h"
#include "user-config/user_data.h"

// globals
#ifdef RGB_MATRIX_BG_REACTIVE_EFFECT
extern rgb_custom_config_t* rgb_custom_config_ptr;
#endif // RGB_MATRIX_BG_REACTIVE_EFFECT

// speed helpers
#ifdef RGB_MATRIX_BG_REACTIVE_EFFECT
void rgb_custom_config_eeconfig_init(void);

// default speed
#ifndef RGB_MATRIX_BG_REACTIVE_DEFAULT_BG_SPEED
#define RGB_MATRIX_BG_REACTIVE_DEFAULT_BG_SPEED 255
#endif

#ifndef RGB_MATRIX_BG_REACTIVE_DEFAULT_REACTIVE_SPEED
#define RGB_MATRIX_BG_REACTIVE_DEFAULT_REACTIVE_SPEED 255
#endif

// default speed step
#ifndef RGB_MATRIX_BG_REACTIVE_DEFAULT_SPEED_STEP
#define RGB_MATRIX_BG_REACTIVE_DEFAULT_SPEED_STEP 5
#endif

void rgb_matrix_set_bg_speed(uint8_t speed);
void rgb_matrix_set_bg_speed_noeeprom(uint8_t speed);

void rgb_matrix_set_reactive_speed(uint8_t speed);
void rgb_matrix_set_reactive_speed_noeeprom(uint8_t speed);

uint8_t rgb_matrix_get_bg_speed(bool raw);
uint8_t rgb_matrix_get_bg_speed_scaled(void);
uint8_t rgb_matrix_get_bg_speed_raw(void);

uint8_t rgb_matrix_get_reactive_speed(bool raw);
uint8_t rgb_matrix_get_reactive_speed_scaled(void);
uint8_t rgb_matrix_get_reactive_speed_raw(void);

void rgb_matrix_increase_bg_speed(void);
void rgb_matrix_increase_bg_speed_noeeprom(void);

void rgb_matrix_increase_reactive_speed(void);
void rgb_matrix_increase_reactive_speed_noeeprom(void);

void rgb_matrix_decrease_bg_speed(void);
void rgb_matrix_decrease_bg_speed_noeeprom(void);

void rgb_matrix_decrease_reactive_speed(void);
void rgb_matrix_decrease_reactive_speed_noeeprom(void);

#endif // RGB_MATRIX_BG_REACTIVE_EFFECT

//#include "rgb_matrix_custom.c"