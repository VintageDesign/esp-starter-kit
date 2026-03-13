#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <inttypes.h>

#include <gpio.h>
#include <servo.h>

static const char *TAG = "APP";
extern "C" void app_main() {
  // GPIO demo
  pinMode(GPIO_NUM_2, OUTPUT);
  ESP_LOGI(TAG, "GPIO demo: toggling LED on GPIO2");
  digitalWrite(GPIO_NUM_2, HIGH);
  vTaskDelay(1000 / portTICK_PERIOD_MS);
  digitalWrite(GPIO_NUM_2, LOW);
  vTaskDelay(1000 / portTICK_PERIOD_MS);

  Servo servo;
  servo.attach(23);
  while (true) {
    servo.write(0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    servo.write(100);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
