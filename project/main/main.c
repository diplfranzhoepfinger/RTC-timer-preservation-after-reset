#include <stdio.h>
#include <time.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"



static const char * const TAG = "example";

void app_main(void)
{


	time_t now;
	char strftime_buf[64];
	struct tm timeinfo;

	time(&now);
	// Set timezone to China Standard Time
	setenv("TZ", "CST-8", 1);
	tzset();

	localtime_r(&now, &timeinfo);
	strftime(strftime_buf, sizeof(strftime_buf), "%c", &timeinfo);
	ESP_LOGI(TAG, "The current date/time in Shanghai is: %s", strftime_buf);




    for (int i = 10; i >= 0; i--) {
    	ESP_LOGI(TAG, "Restarting in %d seconds...", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    ESP_LOGI(TAG, "Restarting now.");
    fflush(stdout);
    assert(0);

}
