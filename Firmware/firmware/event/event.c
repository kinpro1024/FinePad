#include "event/event.h"
#include "config/config.h"
#include "matrix/matrix.h"

static bool prev_state[MATRIX_ROWS][MATRIX_COLS];

void event_init(void) {
    for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
        for (uint8_t c = 0; c < MATRIX_COLS; c++) {
            prev_state[r][c] = false;
        }
    }
}

bool event_get(key_event_t *event) {
    for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
        for (uint8_t c = 0; c < MATRIX_COLS; c++) {

            bool current = get_matrix_state(r, c);
            bool previous = prev_state[r][c];

            if (current != previous) {
                
                prev_state [r][c] = current;

                event->row = r;
                event->col = c;
                event ->type = current ? EVENT_KEY_PRESS : EVENT_KEY_RELEASE;

                return true;
            }
        }
    }
    return false;
}