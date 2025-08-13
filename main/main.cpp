#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <inttypes.h>

#include <math.h>
#include <servo.h>
#include <stepper.h>

static const char *TAG = "APP";
extern "C" void app_main() {
  Stepper stepper(22, 5, 23, MICROSTEP_1, 240);
  stepper.enable_motor();
  while (true) {
    stepper.set_dir(false);
    stepper.write_rad(M_PI);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    stepper.set_dir(true);
    stepper.write_rad(M_PI);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
