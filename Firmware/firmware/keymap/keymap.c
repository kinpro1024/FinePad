#include "keymap/keymap.h"
#include "config/config.h"
#include "macro/macro.h"
#include "tusb.h"

#define KEY_S 0x16
#define KEY_I 0x0C
#define KEY_N 0x11
#define KEY_T 0x17
#define KEY_E 0x08
#define KEY_R 0x15
#define KEY_C 0x06
#define KEY_ENTER 0x28

const macro_step_t macro_intersect[] = {
    {MACRO_KEY_DOWN, 0x16, 0}, {MACRO_KEY_UP, 0x16, 0}, // S
    {MACRO_DELAY, 0, 80},

    {MACRO_KEY_DOWN, 0x0C, 0}, {MACRO_KEY_UP, 0x0C, 0}, // I
    {MACRO_KEY_DOWN, 0x11, 0}, {MACRO_KEY_UP, 0x11, 0}, // N
    {MACRO_KEY_DOWN, 0x17, 0}, {MACRO_KEY_UP, 0x17, 0}, // T
    {MACRO_KEY_DOWN, 0x08, 0}, {MACRO_KEY_UP, 0x08, 0}, // E
    {MACRO_KEY_DOWN, 0x15, 0}, {MACRO_KEY_UP, 0x15, 0}, // R
    {MACRO_KEY_DOWN, 0x16, 0}, {MACRO_KEY_UP, 0x16, 0}, // S
    {MACRO_KEY_DOWN, 0x08, 0}, {MACRO_KEY_UP, 0x08, 0}, // E
    {MACRO_KEY_DOWN, 0x06, 0}, {MACRO_KEY_UP, 0x06, 0}, // C
    {MACRO_KEY_DOWN, 0x17, 0}, {MACRO_KEY_UP, 0x17, 0}, // T

    {MACRO_DELAY, 0, 80},

    {MACRO_KEY_DOWN, 0x28, 0}, {MACRO_KEY_UP, 0x28, 0},

    {0,0,0}
};

const macro_step_t macro_control_point_spline[] = {

    // Open search (S)
    {MACRO_KEY_DOWN, 0x16, 0}, {MACRO_KEY_UP, 0x16, 0},
    {MACRO_DELAY, 0, 80},

    // control point spline
    {MACRO_KEY_DOWN, 0x06, 0}, {MACRO_KEY_UP, 0x06, 0}, // c
    {MACRO_KEY_DOWN, 0x12, 0}, {MACRO_KEY_UP, 0x12, 0}, // o
    {MACRO_KEY_DOWN, 0x11, 0}, {MACRO_KEY_UP, 0x11, 0}, // n
    {MACRO_KEY_DOWN, 0x17, 0}, {MACRO_KEY_UP, 0x17, 0}, // t
    {MACRO_KEY_DOWN, 0x15, 0}, {MACRO_KEY_UP, 0x15, 0}, // r
    {MACRO_KEY_DOWN, 0x12, 0}, {MACRO_KEY_UP, 0x12, 0}, // o
    {MACRO_KEY_DOWN, 0x0F, 0}, {MACRO_KEY_UP, 0x0F, 0}, // l

    {MACRO_KEY_DOWN, 0x2C, 0}, {MACRO_KEY_UP, 0x2C, 0}, // space

    {MACRO_KEY_DOWN, 0x13, 0}, {MACRO_KEY_UP, 0x13, 0}, // p
    {MACRO_KEY_DOWN, 0x12, 0}, {MACRO_KEY_UP, 0x12, 0}, // o
    {MACRO_KEY_DOWN, 0x0C, 0}, {MACRO_KEY_UP, 0x0C, 0}, // i
    {MACRO_KEY_DOWN, 0x11, 0}, {MACRO_KEY_UP, 0x11, 0}, // n
    {MACRO_KEY_DOWN, 0x17, 0}, {MACRO_KEY_UP, 0x17, 0}, // t

    {MACRO_KEY_DOWN, 0x2C, 0}, {MACRO_KEY_UP, 0x2C, 0}, // space

    {MACRO_KEY_DOWN, 0x16, 0}, {MACRO_KEY_UP, 0x16, 0}, // s
    {MACRO_KEY_DOWN, 0x13, 0}, {MACRO_KEY_UP, 0x13, 0}, // p
    {MACRO_KEY_DOWN, 0x0F, 0}, {MACRO_KEY_UP, 0x0F, 0}, // l
    {MACRO_KEY_DOWN, 0x0C, 0}, {MACRO_KEY_UP, 0x0C, 0}, // i
    {MACRO_KEY_DOWN, 0x11, 0}, {MACRO_KEY_UP, 0x11, 0}, // n
    {MACRO_KEY_DOWN, 0x08, 0}, {MACRO_KEY_UP, 0x08, 0}, // e

    {MACRO_DELAY, 0, 80},

    // Enter
    {MACRO_KEY_DOWN, 0x28, 0}, {MACRO_KEY_UP, 0x28, 0},

    {0,0,0}
};

const macro_step_t macro_center_rectangle[] = {

    // Open search
    {MACRO_KEY_DOWN, 0x16, 0}, {MACRO_KEY_UP, 0x16, 0},
    {MACRO_DELAY, 0, 80},

    // center
    {MACRO_KEY_DOWN, 0x06, 0}, {MACRO_KEY_UP, 0x06, 0}, // c
    {MACRO_KEY_DOWN, 0x08, 0}, {MACRO_KEY_UP, 0x08, 0}, // e
    {MACRO_KEY_DOWN, 0x11, 0}, {MACRO_KEY_UP, 0x11, 0}, // n
    {MACRO_KEY_DOWN, 0x17, 0}, {MACRO_KEY_UP, 0x17, 0}, // t
    {MACRO_KEY_DOWN, 0x08, 0}, {MACRO_KEY_UP, 0x08, 0}, // e
    {MACRO_KEY_DOWN, 0x15, 0}, {MACRO_KEY_UP, 0x15, 0}, // r

    {MACRO_KEY_DOWN, 0x2C, 0}, {MACRO_KEY_UP, 0x2C, 0}, // space

    // rectangle
    {MACRO_KEY_DOWN, 0x15, 0}, {MACRO_KEY_UP, 0x15, 0}, // r
    {MACRO_KEY_DOWN, 0x08, 0}, {MACRO_KEY_UP, 0x08, 0}, // e
    {MACRO_KEY_DOWN, 0x06, 0}, {MACRO_KEY_UP, 0x06, 0}, // c
    {MACRO_KEY_DOWN, 0x17, 0}, {MACRO_KEY_UP, 0x17, 0}, // t
    {MACRO_KEY_DOWN, 0x04, 0}, {MACRO_KEY_UP, 0x04, 0}, // a
    {MACRO_KEY_DOWN, 0x11, 0}, {MACRO_KEY_UP, 0x11, 0}, // n
    {MACRO_KEY_DOWN, 0x0A, 0}, {MACRO_KEY_UP, 0x0A, 0}, // g
    {MACRO_KEY_DOWN, 0x0F, 0}, {MACRO_KEY_UP, 0x0F, 0}, // l
    {MACRO_KEY_DOWN, 0x08, 0}, {MACRO_KEY_UP, 0x08, 0}, // e

    {MACRO_DELAY, 0, 80},

    // Enter
    {MACRO_KEY_DOWN, 0x28, 0}, {MACRO_KEY_UP, 0x28, 0},

    {0,0,0}
};

const macro_step_t macro_center_point_arc[] = {

    // Open search
    {MACRO_KEY_DOWN, 0x16, 0}, {MACRO_KEY_UP, 0x16, 0}, // S
    {MACRO_DELAY, 0, 80},

    // center
    {MACRO_KEY_DOWN, 0x06, 0}, {MACRO_KEY_UP, 0x06, 0}, // c
    {MACRO_KEY_DOWN, 0x08, 0}, {MACRO_KEY_UP, 0x08, 0}, // e
    {MACRO_KEY_DOWN, 0x11, 0}, {MACRO_KEY_UP, 0x11, 0}, // n
    {MACRO_KEY_DOWN, 0x17, 0}, {MACRO_KEY_UP, 0x17, 0}, // t
    {MACRO_KEY_DOWN, 0x08, 0}, {MACRO_KEY_UP, 0x08, 0}, // e
    {MACRO_KEY_DOWN, 0x15, 0}, {MACRO_KEY_UP, 0x15, 0}, // r

    {MACRO_KEY_DOWN, 0x2C, 0}, {MACRO_KEY_UP, 0x2C, 0}, // space

    // point
    {MACRO_KEY_DOWN, 0x13, 0}, {MACRO_KEY_UP, 0x13, 0}, // p
    {MACRO_KEY_DOWN, 0x12, 0}, {MACRO_KEY_UP, 0x12, 0}, // o
    {MACRO_KEY_DOWN, 0x0C, 0}, {MACRO_KEY_UP, 0x0C, 0}, // i
    {MACRO_KEY_DOWN, 0x11, 0}, {MACRO_KEY_UP, 0x11, 0}, // n
    {MACRO_KEY_DOWN, 0x17, 0}, {MACRO_KEY_UP, 0x17, 0}, // t

    {MACRO_KEY_DOWN, 0x2C, 0}, {MACRO_KEY_UP, 0x2C, 0}, // space

    // arc
    {MACRO_KEY_DOWN, 0x04, 0}, {MACRO_KEY_UP, 0x04, 0}, // a
    {MACRO_KEY_DOWN, 0x15, 0}, {MACRO_KEY_UP, 0x15, 0}, // r
    {MACRO_KEY_DOWN, 0x06, 0}, {MACRO_KEY_UP, 0x06, 0}, // c

    {MACRO_DELAY, 0, 80},

    // Enter
    {MACRO_KEY_DOWN, 0x28, 0}, {MACRO_KEY_UP, 0x28, 0},

    {0,0,0}
};

#include "keymap.h"

// example keymap (modify YOUR layout here)
static const key_action_t keymap[MATRIX_ROWS][MATRIX_COLS] = {

    // ROW 0
    {
        {KEY_TYPE_MACRO, 0, macro_intersect, 0, 0, 0},
        {KEY_TYPE_MACRO, 0, macro_control_point_spline, 0, 0, 0},
        {KEY_TYPE_MACRO, 0, macro_center_rectangle, 0, 0, 0},
        {KEY_TYPE_MACRO, 0, macro_center_point_arc, 0, 0, 0},
        {KEY_TYPE_NORMAL, HID_KEY_ESCAPE, 0, 0, 0, 0}
    },

    // ROW 1 → mouse movement
    {
        {KEY_TYPE_MOUSE_MOVE, 0, 0,  0, -5, 0}, // up
        {KEY_TYPE_MOUSE_MOVE, 0, 0,  0,  5, 0}, // down
        {KEY_TYPE_MOUSE_MOVE, 0, 0, -5,  0, 0}, // left
        {KEY_TYPE_MOUSE_MOVE, 0, 0,  5,  0, 0}, // right
        {KEY_TYPE_MOUSE_BUTTON, 0, 0, 0, 0, 1}  // left click
    },

    // ROW 2
    {
        {KEY_TYPE_NORMAL, HID_KEY_A, 0, 0, 0, 0},
        {KEY_TYPE_NORMAL, HID_KEY_B, 0, 0, 0, 0},
        {KEY_TYPE_NORMAL, HID_KEY_C, 0, 0, 0, 0},
        {KEY_TYPE_NORMAL, HID_KEY_D, 0, 0, 0, 0},
        {KEY_TYPE_NORMAL, HID_KEY_E, 0, 0, 0, 0}
    },

    // ROW 3
    {
        {KEY_TYPE_NORMAL, HID_KEY_F, 0, 0, 0, 0},
        {KEY_TYPE_NORMAL, HID_KEY_G, 0, 0, 0, 0},
        {KEY_TYPE_NORMAL, HID_KEY_H, 0, 0, 0, 0},
        {KEY_TYPE_NORMAL, HID_KEY_I, 0, 0, 0, 0},
        {KEY_TYPE_MOUSE_TOGGLE, 0, 0, 0, 0, 0}
    }
};

key_action_t keymap_get_action(uint8_t row, uint8_t col) {
    return keymap[row][col];
}