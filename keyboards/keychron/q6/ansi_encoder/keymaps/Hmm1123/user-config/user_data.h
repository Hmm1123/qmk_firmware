#pragma once
#ifndef QMK_FIRMWARE_USER_DATA_H
#define QMK_FIRMWARE_USER_DATA_H

#include "rgb_matrix/rgb_matrix_types_custom.h"

typedef union {
    uint32_t raw : 32;
    struct {
        rgb_custom_config_t rgb_config;
    };
} user_data_t;

// globals
extern user_data_t user_data;

void reset_user_config(void);

#endif // QMK_FIRMWARE_USER_DATA_H
