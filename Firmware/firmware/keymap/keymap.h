#pragma once
#include <stdint.h>
#include "macro/macro.h"

typedef enum {
    KEY_TYPE_NORMAL,
    KEY_TYPE_MACRO,
    KEY_TYPE_MOUSE_MOVE,
    KEY_TYPE_MOUSE_BUTTON,
    KEY_TYPE_MOUSE_TOGGLE
} key_type_t;

typedef struct {
    key_type_t type;

    // keyboard
    uint8_t keycode;

    // macro
    const macro_step_t *macro;

    // mouse
    int8_t dx;
    int8_t dy;
    uint8_t mouse_button;

} key_action_t;

key_action_t keymap_get_action(uint8_t row, uint8_t col);