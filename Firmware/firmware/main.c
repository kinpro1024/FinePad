#include "pico/stdlib.h"
#include "matrix/matrix.h"
#include "event/event.h"
#include "hid/hid.h"
#include "keymap/keymap.h"
#include "macro/macro.h"
#include "tusb.h"

int main() {

    stdio_init_all();
    matrix_init();
    event_init();
    hid_init();

    // movement state
    bool move_up = false;
    bool move_down = false;
    bool move_left = false;
    bool move_right = false;

    while (true) {

        matrix_scan();
        tud_task();
        macro_task();

        key_event_t e;

        while (event_get(&e)) {

            key_action_t action = keymap_get_action(e.row, e.col);

            // block ALL input during macro
            if (macro_is_running()) continue;

            // ================= PRESS =================
            if (e.type == EVENT_KEY_PRESS) {

                switch (action.type) {

                    case KEY_TYPE_MACRO:
                        macro_start(action.macro);
                        break;

                    case KEY_TYPE_NORMAL:
                        hid_send_key(action.keycode, true);
                        break;

                    case KEY_TYPE_MOUSE_MOVE:

                        if (action.dx == 0 && action.dy == -5) move_up = true;
                        if (action.dx == 0 && action.dy ==  5) move_down = true;
                        if (action.dx == -5 && action.dy == 0) move_left = true;
                        if (action.dx ==  5 && action.dy == 0) move_right = true;

                        break;

                    case KEY_TYPE_MOUSE_BUTTON:
                        hid_mouse_buttons(action.mouse_button);
                        break;

                    case KEY_TYPE_MOUSE_TOGGLE:
                        hid_mouse_toggle_left();   // ✅ NEW
                        break;
                }
            }

            // ================= RELEASE =================
            if (e.type == EVENT_KEY_RELEASE) {

                switch (action.type) {

                    case KEY_TYPE_NORMAL:
                        hid_send_key(action.keycode, false);
                        break;

                    case KEY_TYPE_MOUSE_MOVE:

                        if (action.dx == 0 && action.dy == -5) move_up = false;
                        if (action.dx == 0 && action.dy ==  5) move_down = false;
                        if (action.dx == -5 && action.dy == 0) move_left = false;
                        if (action.dx ==  5 && action.dy == 0) move_right = false;

                        break;

                    case KEY_TYPE_MOUSE_BUTTON:
                        hid_mouse_buttons(0); // release
                        break;

                    case KEY_TYPE_MOUSE_TOGGLE:
                        // ❌ DO NOTHING (important)
                        break;
                }
            }
        }

        // ================= CONTINUOUS MOUSE MOVE =================
        int8_t dx = 0;
        int8_t dy = 0;

        if (move_up)    dy -= 3;
        if (move_down)  dy += 3;
        if (move_left)  dx -= 3;
        if (move_right) dx += 3;

        if (dx != 0 || dy != 0) {
            hid_mouse_move(dx, dy);
        }

        sleep_ms(1);
    }
}