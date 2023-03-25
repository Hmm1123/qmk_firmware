#pragma once

#include <unicode/unicode.h>
#include "quantum.h"

#define KC_U_UE LT(0, KC_U)
#define KC_O_OE LT(0, KC_O)
#define KC_A_AE LT(0, KC_A)
#define KC_S_SZ LT(0, KC_S)

//extern bool* u_is_held ;
//extern bool* o_is_held ;
//extern bool* a_is_held ;
//extern bool* s_is_held ;

bool process_tab_or_hold_unicode(keyrecord_t* record, char* long_press_unicode_char_lower, char* long_press_unicode_char_upper);
//void process_tab_or_hold_unicode_quantum(keyrecord_t* record, uint16_t dynamic_keycode, uint16_t keycode,  uint16_t tp_keycode,  bool* is_held);
void process_record_quantum_custom(keyrecord_t* record, uint16_t keycode);
// static bool is_alphanumeric(uint16_t keycode);

// #include "tap_hold.c"