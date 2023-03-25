#include "tap_hold.h"

//bool* u_is_held = false;
//bool* o_is_held = false;
//bool* a_is_held = false;
//bool* s_is_held = false;

//static const uint16_t hold_keycodes[] = {KC_U_UE, KC_O_OE, KC_A_AE, KC_S_SZ};

/**
 * @param is_held is true when the key is held, but nothing has been sent yet (neither the normal keycode nor the unicode string)
 * @return
 */
bool process_tab_or_hold_unicode(keyrecord_t* record, char* long_press_unicode_char_lower, char* long_press_unicode_char_upper) {
    if (record->event.pressed) {
        // if is_held is false, the keycode got already send
//        dprintf("normal is_held: %s \n", ((*is_held) ? "true" : "false"));
//        if (*is_held) {
            if (record->tap.count == 0) {
                // Key is being held.
                if (get_mods() & (MOD_BIT(KC_LEFT_SHIFT) | MOD_BIT(KC_RIGHT_SHIFT))) {
                    send_unicode_string(long_press_unicode_char_upper);
                } else {
                    send_unicode_string(long_press_unicode_char_lower);
                }
                return false; // Skip default handling.
            }
            // we sent the unicode or the normal keycode will be sent, so we set is_held = false to prevent any further sends
//            *is_held = false;
//        } else {
//            return false;
//        }
    }
    return true; // Continue default handling
}

//void process_tab_or_hold_unicode_quantum(keyrecord_t* record, uint16_t dynamic_keycode, const uint16_t keycode, const uint16_t tp_keycode, bool* is_held) {
//    return ;
//    dprintf("quantum key: %d is_held: %s\n", dynamic_keycode, *is_held ? "true" : "false");
//
//    if (dynamic_keycode == keycode) {
//        *is_held = record->event.pressed;
//        dprintf("set is_held to %s\n", *is_held ? "true" : "false");
//    } else if (*is_held) {
//        dprintf("is_held while other key pressed\n");
//        const int hold_keycodes_length = (sizeof(hold_keycodes) / sizeof(hold_keycodes[0]));
//        bool      is_hold_key          = false;
//        for (uint16_t i = 0; (i < hold_keycodes_length); i++) {
//            if (dynamic_keycode == hold_keycodes[i]) {
//                is_hold_key = true;
//                break;
//            }
//        }
//        dprintf("is_hold_key: %s pressed: %s", is_hold_key ? "true" : "false", record->event.pressed ? "true" : "false");
//        if (record->event.pressed == !is_hold_key) {
//            *is_held = false;
//            tap_code16(tp_keycode);
//        }
//    }
//}

void process_record_quantum_custom(keyrecord_t* record, uint16_t keycode) {
//    process_tab_or_hold_unicode_quantum(record, keycode, KC_U_UE, KC_U, u_is_held);
//    process_tab_or_hold_unicode_quantum(record, keycode, KC_A_AE, KC_A, a_is_held);
//    process_tab_or_hold_unicode_quantum(record, keycode, KC_O_OE, KC_O, o_is_held);
//    process_tab_or_hold_unicode_quantum(record, keycode, KC_S_SZ, KC_S, s_is_held);
}

// static bool is_alphanumeric(const uint16_t keycode) {
//     return (keycode >= KC_A && keycode <= KC_Z) || (keycode >= KC_0 && keycode <= KC_9) || (keycode >= KC_GRAVE && keycode <= KC_MINUS);
// }