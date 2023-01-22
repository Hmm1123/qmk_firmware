//
// Created by konsti on 22.01.23.
//


#include "quantum.h"
#include "action.h"


//enum unicode_names {
//    UE,
//    OE,
//    AE,
//};
//
//const uint32_t unicode_map[] PROGMEM = {
//    [UE] = 0x1
//}
//
//enum custom_keycodes {
//    AE = SAFE_RANGE,
//    OE,
//    UE,
//};
//
//struct tab_hold{
//    uint16_t hold_upper;
//    uint16_t hold_lower;
//};
//
//uint16_t tab_hold_keycodes[][3] = {
//    {KC_U, "Ü", "ü"}
//};
//
//static uint16_t timers[];

static bool process_tap_or_hold(keyrecord_t *record, char *short_press_keycode_upper, char *short_press_keycode_lower, char *long_press_keycode_upper, char *long_press_keycode_lower){
    if (record->event.pressed) {
        if (record->tap.count > 0) { // key was tapped
            if (get_mods() & MOD_MASK_SHIFT ) {

                SEND_STRING(short_press_keycode_upper);
            } else {
                SEND_STRING(short_press_keycode_lower);
            }
        } else { // key was held
            if (get_mods() & MOD_MASK_SHIFT) {
                SEND_STRING(long_press_keycode_upper);
            } else {
                SEND_STRING(long_press_keycode_lower);
            }
        }
    }
    return false;
    //    if (timers[event_keycode]+TAPPING_TERM > record->time){
    //// This is a long press (aka hold)
    //
    //    }else{
    //        unregister_code(short_press_keycode);
    //    }
    //    return false;
}

/**
 * If we dont want to distinguish between upper and lower case keycodes
 * @param record
 * @param short_press_keycode
 * @param long_press_keycode
 * @return
 */
/*
static bool process_tab_or_hold(keyrecord_t *record, char *short_press_keycode, char *long_press_keycode){
return process_tap_or_hold(record, short_press_keycode, short_press_keycode, long_press_keycode, long_press_keycode);
}
*/

//static bool process_tap_or_hold(keyrecord_t *record, uint16_t event_keycode, uint16_t long_press_keycode){
//    return process_tap_or_hold(record, event_keycode, event_keycode, long_press_keycode);
//}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_U:
            return process_tap_or_hold(record, "U", "u", "Ü","ü");
        case KC_A:
            return process_tap_or_hold(record, "A", "a", "Ä","ä");
        case KC_O:
            return process_tap_or_hold(record, "O", "o", "Ö","ö");
        default:
            return true; // Process all other keycodes normally

            //        case AE:
            //            if (record->event.pressed) {
            //                timers[keycode] = recode->time;
            //            } else {
            //                return process_tap_or_hold(record, keycode, KC_E);
            //            }
            //        case OE:
            //            // Play a tone when enter is pressed
            //            if (record->event.pressed) {
            //                timers[keycode] = recode->time
            ////                PLAY_SONG(tone_qwerty);
            //            }else{
            //
            //                return process_tap_or_hold(record, keycode, KC_E);
            //            }
            //        case UE:
            //            if (record->event.pressed) {
            //                timers[UE] = recode->time;
            //            } else {
            //                return process_tap_or_hold(record, keycode, KC_E);
            //            }
    }
}