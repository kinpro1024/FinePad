#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef enum {
    MACRO_KEY_DOWN,
    MACRO_KEY_UP,
    MACRO_DELAY
} macro_type_t;

typedef struct {
    macro_type_t type;
    uint8_t keycode;
    uint16_t delay_ms;
} macro_step_t;

void macro_start(const macro_step_t *macro);
void macro_task(void);
bool macro_is_running(void);