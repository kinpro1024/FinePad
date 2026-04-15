#pragma once
#include <stdbool.h>
#include <stdint.h>

typedef enum {
    EVENT_KEY_PRESS,
    EVENT_KEY_RELEASE
} event_type_t;

typedef struct {
    event_type_t type;
    uint8_t row;
    uint8_t col;
} key_event_t;

void event_init(void);
bool event_get(key_event_t *event);