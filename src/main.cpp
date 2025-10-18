#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"
#include "esp_err.h"

extern "C" void app_main(void)
{
    const int ledPin = 26;
    const int ledChannel = LEDC_CHANNEL_0;
    int brightness = 0;
    int fadeAmount = 5;

    // Configure the LEDC timer
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .duty_resolution = LEDC_TIMER_8_BIT,
        .timer_num = LEDC_TIMER_0,
        .freq_hz = 5000,
        .clk_cfg = LEDC_AUTO_CLK
    };
    ledc_timer_config(&ledc_timer);

    // Configure the LEDC channel
    ledc_channel_config_t ledc_channel = {
        .gpio_num = ledPin,
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .channel = (ledc_channel_t)ledChannel,
        .timer_sel = LEDC_TIMER_0,
        .duty = 0,
        .hpoint = 0
    };
    ledc_channel_config(&ledc_channel);

    while (true)
    {
        ledc_set_duty(LEDC_HIGH_SPEED_MODE, (ledc_channel_t)ledChannel, brightness);
        ledc_update_duty(LEDC_HIGH_SPEED_MODE, (ledc_channel_t)ledChannel);

        brightness += fadeAmount;
        if (brightness <= 0 || brightness >= 255)
        {
            fadeAmount = -fadeAmount;
        }

        vTaskDelay(pdMS_TO_TICKS(50));  // same as Arduino delay(50)
    }
}
