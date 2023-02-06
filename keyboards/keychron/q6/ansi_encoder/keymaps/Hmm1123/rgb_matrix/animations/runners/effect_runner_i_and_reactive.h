/*
 * This combines effect_runner_reactive_splash.h and effect_runner_i.h
 */

#pragma once

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifdef RGB_MATRIX_BG_REACTIVE_EFFECT

// typedef HSV (*i_reactive_splash_func)(HSV hsv, uint8_t i, uint8_t time, uint16_t dx, uint16_t dy, uint8_t dist, uint16_t tick);
typedef HSV (*bg_i_func)(HSV hsv, uint8_t i, uint8_t time);
typedef HSV (*reactive_splash_func)(HSV hsv, uint16_t dx, uint16_t dy, uint8_t dist, uint16_t tick);

bool effect_runner_i_reactive_splash(uint8_t start, effect_params_t *params, bg_i_func bg_func, reactive_splash_func reactive_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t time  = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed / 4, 1));
    uint8_t count = g_last_hit_tracker.count;
    // array holds the last timestamp when the LED was active because of the reactive part
    static uint32_t last_reactive_activated[RGB_MATRIX_LED_COUNT];
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = rgb_matrix_config.hsv;

        hsv.v = 0;
        for (uint8_t j = start; j < count; j++) {
            uint16_t dx   = g_led_config.point[i].x - g_last_hit_tracker.x[j];
            uint16_t dy   = g_led_config.point[i].y - g_last_hit_tracker.y[j];
            uint8_t  dist = sqrt16(dx * dx + dy * dy);
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(rgb_matrix_config.speed, 1));
            hsv           = reactive_func(hsv, dx, dy, dist, tick);
        }
        if (hsv.v > 0) {
            hsv.v                      = scale8(hsv.v, rgb_matrix_config.hsv.v);
            last_reactive_activated[i] = timer_read();
        } else {
            // render bg if v would be == 0 (no brightness) (by reactive part)
            const uint16_t td16 = timer_elapsed(last_reactive_activated[i]) / 4;
            uint8_t        td8  = td16;
            if (td16 > 255) td8 = 255;
            hsv.v = scale8(td8, rgb_matrix_config.hsv.v);
            hsv   = bg_func(hsv, i, time);
        }
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}
#    endif // RGB_MATRIX_BG_REACTIVE_EFFECT
#endif     // RGB_MATRIX_KEYREACTIVE_ENABLED
