#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"
#include <iostream>

// Simple C++ class to fade an LED
class FadingLED {
public:
    FadingLED(int pin, ledc_channel_t channel, int freq = 5000) 
        : pin(pin), channel(channel), brightness(0), fadeAmount(1) 
    {
        ledc_timer_config_t timerConfig = {
            .speed_mode = LEDC_LOW_SPEED_MODE,
            .duty_resolution = LEDC_TIMER_8_BIT,
            .timer_num = LEDC_TIMER_0,
            .freq_hz = freq,
            .clk_cfg = LEDC_AUTO_CLK
        };
        ledc_timer_config(&timerConfig);

        ledc_channel_config_t channelConfig = {
            .gpio_num = pin,
            .speed_mode = LEDC_LOW_SPEED_MODE,
            .channel = channel,
            .timer_sel = LEDC_TIMER_0,
            .duty = 0,
            .hpoint = 0
        };
        ledc_channel_config(&channelConfig);
    }

    void update() {
        ledc_set_duty(LEDC_LOW_SPEED_MODE, channel, brightness);
        ledc_update_duty(LEDC_LOW_SPEED_MODE, channel);

        brightness += fadeAmount;
        if (brightness <= 0 || brightness >= 255) fadeAmount = -fadeAmount;
    }

private:
    int pin;
    ledc_channel_t channel;
    int brightness;
    int fadeAmount;
};

extern "C" void app_main() {
    FadingLED led(26, LEDC_CHANNEL_0);

    while (true) {
        led.update();
        vTaskDelay(20 / portTICK_PERIOD_MS);
    }
}