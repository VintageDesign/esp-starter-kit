#ifndef GPIO_H
#define GPIO_H

#include <driver/gpio.h>
#include <stdint.h>

/**
 * @enum PinMode
 * @brief GPIO pin mode enumeration
 */
enum PinMode { INPUT, OUTPUT, INPUT_PULLUP, INPUT_PULLDOWN };

/**
 * @enum PinState
 * @brief GPIO pin state enumeration
 */
enum PinState { LOW = 0, HIGH = 1 };

/**
 * @brief Configure a GPIO pin mode
 * @param pin GPIO pin number
 * @param mode Pin mode (INPUT, OUTPUT, INPUT_PULLUP, INPUT_PULLDOWN)
 */
void pinMode(uint8_t pin, PinMode mode);

/**
 * @brief Set GPIO pin output state
 * @param pin GPIO pin number
 * @param state Pin state (LOW or HIGH)
 */
void digitalWrite(uint8_t pin, PinState state);

/**
 * @brief Read GPIO pin input state
 * @param pin GPIO pin number
 * @return PinState Pin state (LOW or HIGH)
 */
PinState digitalRead(uint8_t pin);

#endif // GPIO_H
