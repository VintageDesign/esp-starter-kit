#include "gpio.h"
#include <driver/gpio.h>
#include <esp_log.h>

static const char *TAG = "GPIO";

void pinMode(uint8_t pin, PinMode mode) {
  uint64_t gpio_mask = (1ULL << pin);
  gpio_pullup_t pull_up_en = GPIO_PULLUP_DISABLE;
  gpio_pulldown_t pull_down_en = GPIO_PULLDOWN_DISABLE;
  gpio_mode_t gpio_mode = GPIO_MODE_INPUT;

  switch (mode) {
  case INPUT:
    gpio_mode = GPIO_MODE_INPUT;
    pull_up_en = GPIO_PULLUP_DISABLE;
    pull_down_en = GPIO_PULLDOWN_DISABLE;
    break;
  case OUTPUT:
    gpio_mode = GPIO_MODE_OUTPUT;
    pull_up_en = GPIO_PULLUP_DISABLE;
    pull_down_en = GPIO_PULLDOWN_DISABLE;
    break;
  case INPUT_PULLUP:
    gpio_mode = GPIO_MODE_INPUT;
    pull_up_en = GPIO_PULLUP_ENABLE;
    pull_down_en = GPIO_PULLDOWN_DISABLE;
    break;
  case INPUT_PULLDOWN:
    gpio_mode = GPIO_MODE_INPUT;
    pull_up_en = GPIO_PULLUP_DISABLE;
    pull_down_en = GPIO_PULLDOWN_ENABLE;
    break;
  }

  gpio_config_t gpio_conf = {
      .pin_bit_mask = gpio_mask,
      .mode = gpio_mode,
      .pull_up_en = pull_up_en,
      .pull_down_en = pull_down_en,
      .intr_type = GPIO_INTR_DISABLE,
  };

  ESP_ERROR_CHECK(gpio_config(&gpio_conf));
}

void digitalWrite(uint8_t pin, PinState state) {
  gpio_set_level((gpio_num_t)pin, (uint32_t)state);
}

PinState digitalRead(uint8_t pin) {
  int level = gpio_get_level((gpio_num_t)pin);
  return (PinState)level;
}
