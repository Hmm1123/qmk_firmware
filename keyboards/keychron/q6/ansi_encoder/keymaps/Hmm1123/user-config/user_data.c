#include <rgb_matrix/rgb_matrix_custom.h>
#include "user_data.h"

// globals
user_data_t user_data;

void reset_user_config(void) {
    user_data.raw = 0;
#ifdef RGB_MATRIX_BG_REACTIVE_EFFECT
    reset_rgb_custom_config();
#endif // RGB_MATRIX_BG_REACTIVE_EFFECT
}