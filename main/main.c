#include <stdio.h>
#include "ssd1306.h"
#include <esp_log.h>
#include "oled_menu.h"

#define DISPLAY_TAG "SSD1306_1306"

void app_main(void)
{
	SSD1306_t dev;
	i2c_master_init(&dev, CONFIG_SDA_GPIO, CONFIG_SCL_GPIO, CONFIG_RESET_GPIO);
	ESP_LOGI(DISPLAY_TAG, "Panel is 128x64");
	ssd1306_init(&dev, 128, 64);
	ssd1306_clear_screen(&dev, false);
	ssd1306_contrast(&dev, 0xff);
	ssd1306_display_text_x3(&dev, 0, "Hello", 5, false);
	vTaskDelay(3000 / portTICK_PERIOD_MS);
	drawMenu(&dev, 1);
}
