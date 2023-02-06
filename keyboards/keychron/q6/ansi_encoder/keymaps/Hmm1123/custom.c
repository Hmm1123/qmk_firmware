//
// Created by konsti on 22.01.23.
//

#include <unicode/unicode.h>
#include <process_key_override.h>
#include "quantum.h"
#include "action.h"

enum unicode_names { UE_UPPER, UE_LOW, OE_UPPER, OE_LOW, AE_UPPER, AE_LOW };

const uint32_t unicode_map[] PROGMEM = {
    [AE_LOW] = 0xE4, [AE_UPPER] = 0xC4,

    [OE_LOW] = 0xF6, [OE_UPPER] = 0xD6,

    [UE_LOW] = 0xFC, [UE_UPPER] = 0xDC,
};

static bool process_tab_or_hold_unicode(keyrecord_t* record, char* long_press_unicode_char_lower, char* long_press_unicode_char_upper) {
    if (record->tap.count == 0 && record->event.pressed) {
        // Key is being held.
        if (get_mods() & (MOD_BIT(KC_LEFT_SHIFT) | MOD_BIT(KC_RIGHT_SHIFT))) {
            send_unicode_string(long_press_unicode_char_upper);
        } else {
            send_unicode_string(long_press_unicode_char_lower);
        }
        return false; // Skip default handling.
    }
    return true; // Continue default handling.
}

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

#define KC_U_UE LT(0, KC_U)
#define KC_O_OE LT(0, KC_O)
#define KC_A_AE LT(0, KC_A)
#define KC_S_SZ LT(0, KC_S)

#define QK_UNICODE_MODE_NEXT_VIA_KEYCODE USER11

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
        default:
            return true;
    }
}

// RGB
#ifdef RGB_MATRIX_ENABLE
void keyboard_post_init_user(void) {
    rgblight_mode_noeeprom(RGB_MATRIX_CUSTOM_CYCLE_LEFT_RIGHT_REACTIVE_MULTINEXUS);
}
#endif