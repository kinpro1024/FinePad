#include "as5600.h"
#include "hardware/i2c.h"
#include "pico/stdlib.h"

#define I2C_PORT i2c0
#define SDA_PIN 0
#define SCL_PIN 1

#define AS5600_ADDR 0x36
#define AS5600_RAW_ANGLE_REG 0x0C

uint16_t as5600_read_angle(void) {
    uint8_t reg = AS5600_RAW_ANGLE_REG;
    uint8_t buf[2];

}