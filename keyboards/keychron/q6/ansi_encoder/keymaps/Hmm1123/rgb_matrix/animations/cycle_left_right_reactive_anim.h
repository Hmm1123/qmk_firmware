/*
 * This combines solid_reactive_nexus.h and cycle_right_left_anim.h
 */

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifdef RGB_MATRIX_BG_REACTIVE_EFFECT
#        if defined(ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT_REACTIVE_NEXUS) || defined(ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT_REACTIVE_MULTINEXUS)

#            ifdef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT_REACTIVE_MULTINEXUS
RGB_MATRIX_EFFECT(CYCLE_LEFT_RIGHT_REACTIVE_MULTINEXUS)
#            endif // ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT_REACTIVE_MULTINEXUS

#            ifdef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT_REACTIVE_NEXUS
RGB_MATRIX_EFFECT(CYCLE_LEFT_RIGHT_REACTIVE_NEXUS)
#            endif // ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT_REACTIVE_NEXUS

#            ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
// #                include "rgb_matrix/animations/runners/effect_runner_i_and_reactive.h"
#                include "rgb_matrix/animations/runners/rgb_matrix_runners.inc"
#                include "../rgb_matrix_custom.h"

// default values for bg color range
#                ifndef CYCLE_LEFT_RIGHT_REACTIVE_BG_COLOR_H_START
#                    define CYCLE_LEFT_RIGHT_REACTIVE_BG_COLOR_H_START 43
#                endif

#                ifndef CYCLE_LEFT_RIGHT_REACTIVE_BG_COLOR_H_END
#                    define CYCLE_LEFT_RIGHT_REACTIVE_BG_COLOR_H_END 222
#                endif

// default values for reactive press
#                ifndef CYCLE_LEFT_RIGHT_REACTIVE_PRESS_COLOR_H
#                    define CYCLE_LEFT_RIGHT_REACTIVE_PRESS_COLOR_H 0
#                endif

#                ifndef CYCLE_LEFT_RIGHT_REACTIVE_PRESS_MAX_DIST
#                    define CYCLE_LEFT_RIGHT_REACTIVE_PRESS_MAX_DIST 72
#                endif

// make the animation crosswise (remove color on keys in edges of the animation)
#                ifndef CYCLE_LEFT_RIGHT_REACTIVE_PRESS_MAX_DIST_ROW_COL
#                    define CYCLE_LEFT_RIGHT_REACTIVE_PRESS_MAX_DIST_ROW_COL 8
#                endif

// utils
#                define CYCLE_LEFT_RIGHT_REACTIVE_BG_COLOR_H_RANGE (CYCLE_LEFT_RIGHT_REACTIVE_BG_COLOR_H_END - CYCLE_LEFT_RIGHT_REACTIVE_BG_COLOR_H_START)
#                define scale_bg_color(inp) (qadd8(CYCLE_LEFT_RIGHT_REACTIVE_BG_COLOR_H_START, scale8(inp, CYCLE_LEFT_RIGHT_REACTIVE_BG_COLOR_H_RANGE)))

static HSV CYCLE_LEFT_RIGHT_REACTIVE_reactive_math(HSV hsv, uint16_t dx, uint16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick - dist;
    if (effect > 255) effect = 255;
    if (dist > CYCLE_LEFT_RIGHT_REACTIVE_PRESS_MAX_DIST) effect = 255;
        // shorten it a bit
#                define max_dist_row_col CYCLE_LEFT_RIGHT_REACTIVE_PRESS_MAX_DIST_ROW_COL
    if ((dx < -max_dist_row_col || dx > max_dist_row_col) && (dy < -max_dist_row_col || dy > max_dist_row_col)) effect = 255;
#                undef max_dist_row_col
#                ifdef RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE
    hsv.h = scale16by8(g_rgb_timer, add8(rgb_matrix_get_reactive_speed_scaled(), 1) >> 6);
#                endif
    hsv.v = qadd8(hsv.v, 255 - effect);
    hsv.h = rgb_matrix_config.hsv.h + dy / 4;
    return hsv;
}

static HSV CYCLE_LEFT_RIGHT_REACTIVE_bg_math(HSV hsv, uint8_t i, uint8_t time) {
    hsv.h = scale_bg_color(g_led_config.point[i].x - time);
    return hsv;
}

bool CYCLE_LEFT_RIGHT_REACTIVE_NEXUS(effect_params_t* params) {
    return effect_runner_i_reactive_splash(qsub8(g_last_hit_tracker.count, 1), params, &CYCLE_LEFT_RIGHT_REACTIVE_bg_math, &CYCLE_LEFT_RIGHT_REACTIVE_reactive_math);
}

bool CYCLE_LEFT_RIGHT_REACTIVE_MULTINEXUS(effect_params_t* params) {
    return effect_runner_i_reactive_splash(0, params, &CYCLE_LEFT_RIGHT_REACTIVE_bg_math, &CYCLE_LEFT_RIGHT_REACTIVE_reactive_math);
}

#                undef CYCLE_LEFT_RIGHT_REACTIVE_BG_COLOR_H_RANGE
#                undef scale_bg_color

#            endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS f
#        endif     // ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT_REACTIVE_MULTINEXUS
#    endif         // RGB_MATRIX_BG_REACTIVE_EFFECT
#endif             // RGB_MATRIX_KEYREACTIVE_ENABLED