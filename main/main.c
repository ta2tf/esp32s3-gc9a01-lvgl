

/* INCLUDES ------------------------------------------------------------------*/
#include "main.h"

#include "display/display.h"
#include "display/gc9a01.h"
#include "display/ui_helpers.h"
#include "esp_log.h"


/* MACROS --------------------------------------------------------------------*/

/* DEFINITIONS ---------------------------------------------------------------*/

/* PRIVATE STRUCTRES ---------------------------------------------------------*/

/* VARIABLES -----------------------------------------------------------------*/

static const char* TAG = "main";




/* PRIVATE FUNCTIONS DECLARATION ---------------------------------------------*/

static void lvgl_time_task(void*param);


/* FUNCTION PROTOTYPES -------------------------------------------------------*/
/**
 * @brief 	Initialize system peripherals and create FreeRTOS tasks
 *
 */


void lvgl_time_task(void* param)
{


	while(1)
	{

        // The task running lv_timer_handler should have lower priority than that running `lv_tick_inc`
        lv_timer_handler();


        // raise the task priority of LVGL and/or reduce the handler period can improve the performance
        vTaskDelay(pdMS_TO_TICKS(100));



	}
}




void app_main(void)
{

	 vTaskDelay(pdMS_TO_TICKS(5000));


	ESP_LOGI(TAG, "START LVGL");



	gc9a01_displayInit();

	displayConfig();



     xTaskCreatePinnedToCore(lvgl_time_task, "lvgl_time_task", 10000, NULL, 4, NULL, 1);


}






