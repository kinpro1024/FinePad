#include "macro/macro.h"
#include "hid/hid.h"
#include "pico/time.h"

static const macro_step_t *current_macro = 0;
static uint8_t step_index = 0;
static absolute_time_t next_time;
static bool running = false;

void macro_start(const macro_step_t *macro) {
    current_macro = macro;
    step_index = 0;
    running = true;
    next_time = get_absolute_time();
}

bool macro_is_running(void) {
    return running;
}

void macro_task(void) {
    if (!running || current_macro == 0) return;

    if (absolute_time_diff_us(get_absolute_time(), next_time) > 0) return;

    macro_step_t step = current_macro[step_index];

    switch (step.type) {

        case MACRO_KEY_DOWN:
        hid_send_key(step.keycode, true);
        next_time = delayed_by_ms(get_absolute_time(), 8);
        break;

        case MACRO_KEY_UP:
        hid_send_key(step.keycode, false);

        // IMPORTANT: give time for USB to send empty report
        next_time = delayed_by_ms(get_absolute_time(), 15);
        break;

        case MACRO_DELAY:
            next_time = delayed_by_ms(get_absolute_time(), step.delay_ms);
            step_index++;
            return;
    }

    step_index++;

    // end condition
    if (current_macro[step_index].type == 0 &&
        current_macro[step_index].keycode == 0 &&
        current_macro[step_index].delay_ms == 0) {
        running = false;
    }
}