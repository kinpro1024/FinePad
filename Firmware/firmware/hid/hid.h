#pragma once
#include <stdint.h>
#include <stdbool.h>

void hid_init(void);
void hid_send_key(uint8_t keycode, bool pressed);
void hid_mouse_move(int8_t x, int8_t y);
void hid_mouse_buttons(uint8_t buttons);
void hid_ouse_button_left(bool pressed);
void hid_mouse_toggle_left(void);