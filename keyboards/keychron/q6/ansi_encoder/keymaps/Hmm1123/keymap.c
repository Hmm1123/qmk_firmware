/* Copyright 2022 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "action.h"
#include "process_record.h"

// clang-format off

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_ansi_109(
    KC_ESC,   KC_BRID,  KC_BRIU,  KC_NO,    KC_NO,    RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,    KC_NO,    KC_NO,    RGB_MOD,  KC_F13,   KC_F14,   KC_F15,   KC_F16,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                   KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,    KC_P2,    KC_P3,
    KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RCMD,  KC_ROPT,  MO(MAC_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
[MAC_FN] = LAYOUT_ansi_109(
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RGB_TOG,    _______,  _______,  RGB_TOG,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,
    _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
    _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),
[WIN_BASE] = LAYOUT_ansi_109(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,    KC_PSCR,  KC_NO,    RGB_MOD,  _______,  _______,  _______,  _______,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                   KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,    KC_P2,    KC_P3,
    KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
[WIN_FN] = LAYOUT_ansi_109(
    _______,  KC_BRID,  KC_BRIU,  _______,  _______,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RGB_TOG,    _______,  _______,  RGB_TOG,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,
    _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
    _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),
};

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

static bool process_tap_or_hold(keyrecord_t *record, char short_press_keycode_upper, char short_press_keycode_lower, char long_press_keycode_upper, char long_press_keycode_lower){
if (record->event.pressed) {
            if (record->tap.count > 0) { // key was tapped
                if (is_mod_active(KC_LSFT) || is_mod_active(KC_RSFT)) {
                    SEND_STRING(short_press_keycode_upper);
                } else {
                    SEND_STRING(short_press_keycode_lower);
                }
            } else { // key was held
                if (is_mod_active(KC_LSFT) || is_mod_active(KC_RSFT)) {
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
static bool process_tab_or_hold(keyrecord_t *record, char short_press_keycode, char long_press_keycode){
return process_tap_or_hold(record, short_press_keycode, short_press_keycode, long_press_keycode, long_press_keycode)
}

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
        default:
            return true; // Process all other keycodes normally
    }
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][1][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif
