#pragma once
#include <stdint.h>
#include <stdbool.h>

void matrix_init(void);
void matrix_scan(void);
bool get_matrix_state(uint8_t row, uint8_t col);