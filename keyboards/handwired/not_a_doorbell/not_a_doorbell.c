#include "quantum.h"



/* RGB Positioning */
led_config_t g_led_config = { {
    {  11,   9,  9  ,8},
    {  7,   6,  5  ,4},
    {  3,  2, 1  ,0}
}, {
    { 0, 64 }, { 75, 64 }, { 149, 64},{ 224,  64},
    { 0, 32 }, { 75, 32 }, { 149, 32},{ 224,  32},
    { 0, 0 }, { 75, 0 }, { 149, 0},{ 224,  0}
}, {
    4, 4, 4,4,
    4, 4, 4,4,
    4, 4, 4,4
} };



bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    }
    return true;
}

void keyboard_post_init_user(void) {
    rgb_matrix_set_color_all(50,50,50);
}