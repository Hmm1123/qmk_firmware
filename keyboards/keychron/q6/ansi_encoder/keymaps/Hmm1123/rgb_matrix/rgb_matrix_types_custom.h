#pragma once

#ifdef RGB_MATRIX_BG_REACTIVE_EFFECT
typedef union {
    uint16_t raw : 16;
    struct {
        uint8_t reactive_speed : 8;
        uint8_t background_speed : 8;
    };
} rgb_custom_config_t;
#endif // RGB_MATRIX_BG_REACTIVE_EFFECT