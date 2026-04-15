#include "matrix/matrix.h"
#include "config/config.h"
#include "pico/stdlib.h"

static bool matrix_state[MATRIX_ROWS][MATRIX_COLS];

void matrix_init(void) {

    //set rows to drive
    for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
        gpio_init(row_pins[r]);
        gpio_set_dir(row_pins[r], GPIO_OUT);
        gpio_put(row_pins[r], 1); //Idle High
    }

    for (uint8_t c = 0; c < MATRIX_COLS; c++) {
        gpio_init(col_pins[c]);
        gpio_set_dir(col_pins[c], GPIO_IN);
        gpio_pull_up(col_pins[c]);
    }
}

void matrix_scan() {

    for(uint8_t r = 0; r < MATRIX_ROWS; r++) {
        gpio_put(row_pins[r], 0); //Drive row low
        sleep_us(5);

        for(uint8_t c = 0; c < MATRIX_COLS; c++) {
            bool is_pressed = !gpio_get(col_pins[c]);
            matrix_state[r][c] = is_pressed;
        }
        gpio_put(row_pins[r], 1);
    }
}

bool get_matrix_state(uint8_t row, uint8_t col) {
    return matrix_state[row][col];
}