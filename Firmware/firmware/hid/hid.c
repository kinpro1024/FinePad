#include "config/config.h"
#include "hid/hid.h"
#include "tusb.h"
#include <stdbool.h>
#include <stdint.h>

// 6-key rollover buffer
static uint8_t key_report[6] = {0};
static uint8_t modifier = 0;
static bool mouse_left_held = false;

void hid_init(void) {
    // TinyUSB device init
    tusb_init();
}

void hid_send_key(uint8_t keycode, bool pressed) {

    if (!tud_hid_ready()) return;

    if (pressed) {
        key_report[0] = keycode;   // simple: 1 key only
    } else {
        for (int i = 0; i < 6; i++) {
            key_report[i] = 0;
        }
    }

    tud_hid_keyboard_report(1, modifier, key_report);
}

void hid_mouse_move(int8_t x, int8_t y) {

    if (!tud_hid_ready()) return;

    tud_hid_mouse_report(2, 0, x, y, 0, 0);
}

void hid_mouse_buttons(uint8_t buttons) {

    if (!tud_hid_ready()) return;

    tud_hid_mouse_report(2, buttons, 0, 0, 0, 0);
}

void hid_mouse_button_left(bool pressed) {
    if (tud_hid_ready()) {
        uint8_t buttons = pressed ? MOUSE_BUTTON_LEFT : 0;
        tud_hid_mouse_report(2, buttons, 0, 0, 0, 0);
    }
}

void hid_mouse_toggle_left(void) {
    mouse_left_held = !mouse_left_held;

    uint8_t buttons = mouse_left_held ? MOUSE_BUTTON_LEFT : 0;

    if (tud_hid_ready()) {
        tud_hid_mouse_report(2, buttons, 0, 0, 0, 0);
    }
}