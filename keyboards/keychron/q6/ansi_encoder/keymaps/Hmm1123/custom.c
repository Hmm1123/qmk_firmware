#include <rgb_matrix/rgb_matrix_custom.h>
#include "action_tapping.h"
#include "quantum.h"
#include "tap_hold.h"
#include "action.h"
#include "user-config/user_eeconfig.h"
#include "via.h"
#include "custom_keycodes.h"

// #include "via_custom_commands.c"
// #include "rgb_matrix/rgb_matrix_custom.c"
// #include "user_eeconfig.c"

// enum unicode_names { UE_UPPER, UE_LOW, OE_UPPER, OE_LOW, AE_UPPER, AE_LOW };
//
// const uint32_t unicode_map[] PROGMEM = {
//     [AE_LOW] = 0xE4, [AE_UPPER] = 0xC4,
//
//     [OE_LOW] = 0xF6, [OE_UPPER] = 0xD6,
//
//     [UE_LOW] = 0xFC, [UE_UPPER] = 0xDC,
// };

/*
static bool process_tap_or_hold(keyrecord_t* record, uint16_t long_press_keycode) {
    if (record->tap.count == 0 && record->event.pressed) {
        // Key is being held.
        tap_code16(long_press_keycode);
        return false; // Skip default handling.
    }
    return true; // Continue default handling.
}
*/

// Key Overrides - see https://github.com/qmk/qmk_firmware/blob/master/docs/feature_key_overrides.md

// const key_override_t  next_unicode_mode_override = ;
//
// const key_override_t ** key_overrides = (const key_override_t *[]){
//     &next_unicode_mode_override,
//     NULL
// };

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case KC_O_OE:
            return process_tab_or_hold_unicode(record, "ö", "Ö");
        case KC_U_UE:
            return process_tab_or_hold_unicode(record, "ü", "Ü");
        case KC_A_AE:
            return process_tab_or_hold_unicode(record, "ä", "Ä");
        case KC_S_SZ:
            return process_tab_or_hold_unicode(record, "ß", "ß");
        case QK_UNICODE_MODE_NEXT_VIA_KEYCODE:
            if (record->event.pressed) {
                cycle_unicode_input_mode(1);
            }
            return false;
        case MY_DT_UP:
            if (record->event.pressed) {
                g_tapping_term += DYNAMIC_TAPPING_TERM_INCREMENT;
            }
            return false;
        case MY_DT_DOWN:
            if (record->event.pressed) {
                g_tapping_term -= DYNAMIC_TAPPING_TERM_INCREMENT;
            }
            return false;
        case MY_DT_PRINT: {
            if (record->event.pressed) {
                const char* tapping_term_str = get_u16_str(g_tapping_term, ' ');
                // Skip padding spaces
                while (*tapping_term_str == ' ') {
                    tapping_term_str++;
                }
                send_string(tapping_term_str);
            }
            return false;
        }
        default:
            return true;
    }
}

//void matrix_init_user(void) {
//    via_init();
//}

// RGB
#if defined( RGB_MATRIX_ENABLE) || defined(CUSTOM_USER_EECONFIG)
void keyboard_post_init_user(void) {
    rgblight_mode_noeeprom(RGB_MATRIX_CUSTOM_CYCLE_LEFT_RIGHT_REACTIVE_MULTINEXUS);
    reset_user_config();
#ifdef CUSTOM_USER_EECONFIG
    keyboard_post_init_user_eeconfig();
#endif
    debug_enable = true;
}
#endif