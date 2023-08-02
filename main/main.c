/**
 ******************************************************************************
 *							USEFUL ELECTRONICS
 ******************************************************************************/
/**
 ******************************************************************************
 * @file    :  main.c
 * @author  :  WARD ALMASARANI
 * @version :  v.1.0
 * @date    :  Jan 30, 2023
 * @link    :  https://www.youtube.com/@usefulelectronics
 *			   Hold Ctrl button and click on the link to be directed to
			   Useful Electronics YouTube channel	
 ******************************************************************************/


/* INCLUDES ------------------------------------------------------------------*/
#include "main.h"
#include "uart_config.h"
#include "esp_interrupt.h"

#include "hardware/rotary_encoder.h"
#include "hardware/hlk-ld1125h.h"
#include "hardware/button.h"
#include "hardware/hlk-ld1125h.h"

#include "display/display.h"
#include "display/gc9a01.h"
#include "display/lvgl_demo_ui.h"
#include "display/ui_helpers.h"

#include "wireless/sntp.h"


#include "time.h"

#include "lwip/ip_addr.h"

#include "gpio/gpio_config.h"
/* PRIVATE STRUCTRES ---------------------------------------------------------*/

/* VARIABLES -----------------------------------------------------------------*/
static const char *main = "main";
char targetString[10] = {0};
/* DEFINITIONS ---------------------------------------------------------------*/

/* MACROS --------------------------------------------------------------------*/

/* PRIVATE FUNCTIONS DECLARATION ---------------------------------------------*/
static void time_config(void);
static void main_encoder_cb(uint8_t knobPosition, uint8_t knobButtonStatus);
static void main_tempretureStringPrepare(char* tempString, char* targetString);
static void lvgl_time_task(void*param);
static void wirless_init_task(void* param);
static void mqtt_msg_pars_task(void* param);
static void time_handle_task(void* param);
static void uart_reception_task(void *param);

/* FUNCTION PROTOTYPES -------------------------------------------------------*/
/**
 * @brief 	Initialize system peripherals and create FreeRTOS tasks
 *
 */
void app_main(void)
{
	gc9a01_displayInit();

	displayConfig();

	uart_config();

//	gpio_config_ext_interrupt(KNOB_BUTTON, GPIO_INTR_NEGEDGE, gpio_isr_handle);


//	encoder_init(main_encoder_cb);

//	 xTaskCreatePinnedToCore(wirless_init_task, "WiFi init", 10000, NULL, 4, NULL, 0);

//	xTaskCreatePinnedToCore(encoder_handler_task, "encoder_handler", 10000, NULL, 4, NULL, 1);

     xTaskCreatePinnedToCore(lvgl_time_task, "lvgl_time_task", 10000, NULL, 4, NULL, 1);

     //Wait for WiFi and MQTT broker connection to be established.
//     vTaskDelay(pdMS_TO_TICKS(15000));

//     sntp_config();

//     xTaskCreatePinnedToCore(mqtt_msg_pars_task, "MQTT parser", 10000, NULL, 4, NULL, 1);

     xTaskCreatePinnedToCore(time_handle_task, "Real time Handler", 10000, NULL, 4, NULL, 1);

     xTaskCreatePinnedToCore(uart_event_task, "uart event", 10000, NULL, 4, NULL, 0);

     xTaskCreatePinnedToCore(uart_transmission_task, "USART TX handling task", 10000, NULL, 4, NULL, 0);

     xTaskCreatePinnedToCore(uart_reception_task, "USART RX handling task", 10000, NULL, 4, NULL, 0);
}
/**
 * @brief 	LVGL library timer task. Necessary to run once every 10ms
 *
 */
void lvgl_time_task(void* param)
{
	TickType_t xLastWakeTime = xTaskGetTickCount();
	while(1)
	{

        // The task running lv_timer_handler should have lower priority than that running `lv_tick_inc`
        lv_timer_handler();
        //Used with smart watch
//        _ui_arc_increment();
        // raise the task priority of LVGL and/or reduce the handler period can improve the performance
//        vTaskDelay(pdMS_TO_TICKS(10));

        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(10) );

	}
}
/**
 * @brief 	Encoder position read callback.
 *
 * @param 	knobPosition	: Read encoder position value.
 */
static void main_encoder_cb(uint8_t knobPosition, uint8_t knobButtonStatus)
{
	set_value((int32_t) knobPosition, knobButtonStatus);
}

static void uart_reception_task(void *param)
{
   uartHandler_t uartHandler = {0};

   uint8_t movementType = 0;

   int16_t detectedDistance = 0;
   for(;;)
   {
      //Waiting for UART packet to get received.
      if(xQueueReceive(uartRxStore_queue, (void * )&uartHandler, portMAX_DELAY))
      {
    	  detectedDistance = hlk_ld1125h_parse_packet(hUart.uart_rxBuffer,(uint8_t*) &movementType);

    	  if(-1 != detectedDistance)
    	  {
    		  ESP_LOGI(main, "dis = %d, move type %d", detectedDistance, movementType);
    	  }
      }
   }
}
/**
 * @brief Initialize WiFi and connect to The configured WiFi network. and then connect to the MQTT broker
 *
 */
static void wirless_init_task(void* param)
{
	wifi_connect();

	mqtt_app_start();

	vTaskDelete(NULL);
}

static void mqtt_msg_pars_task(void* param)
{
	mqtt_buffer_t mqttBuffer = {0};

	const char publishRequest = 1;

	while(1)
	{
		if(xQueueReceive(mqttSubscribe_queue, (void *)&mqttBuffer, portMAX_DELAY))
		{
			switch (mqttBuffer.eventType)
			{
				case MQTT_BROKER_CONNECT:
					_ui_text_wifiIndicate(true);

					mqtt_publish(MQTT_REQUEST_TOPIC, &publishRequest, 1);
					break;
				case MQTT_BROKER_DISCONNECT:
					_ui_text_wifiIndicate(false);
					break;
				case MQTT_TOPIC_DATA_RX:


					main_tempretureStringPrepare(mqttBuffer.data, targetString);

					_ui_temp_set(targetString);

					break;
				default:
					break;
			}
		}
	}
}

static void time_handle_task(void* param)
{
	struct tm  Time = {0};

	char tempString[3] = {0};

	TickType_t xLastWakeTime = xTaskGetTickCount();

	const uint32_t tempUpdatePeriod = 60 * 60; //1 hour

	static uint32_t tempUpdateCounter = 0;

	const char publishRequest = 1;
	while(1)
	{
		vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(1000) );

		sntp_time_get(&Time);

		sprintf(tempString,"%02d",Time.tm_hour);

		realTime.sel.hour = (tempString[1] << 8);
		realTime.sel.hour |= (tempString[0]);

		sprintf(tempString,"%02d",Time.tm_min);

		realTime.sel.minute = (tempString[1] << 8);
		realTime.sel.minute |= (tempString[0]);

		++tempUpdateCounter;

		if(tempUpdatePeriod <= tempUpdateCounter)
		{
			mqtt_publish(MQTT_REQUEST_TOPIC, &publishRequest, 1);

			tempUpdateCounter = 0;
		}

	}
}
/**
 * @brief 	Create a proper temperature value showing string
 *
 * @param 	tempString	:	string received over MQTT
 *
 * @param 	targetString:	string to copy the formed string to
 */
static void main_tempretureStringPrepare(char* tempString, char* targetString)
{
	const char tempUnit[4] 		= " °C";
	const char tempStingLength 	= 3;
	for(uint8_t i = 0; i < tempStingLength; ++i)
	{
		if(!isalnum((int)tempString[i]))
		{
			strcpy(&tempString[i], tempUnit);
			break;
		}
	}

	strcpy(targetString,tempString);

	targetString[6] = 0;

}

/*************************************** USEFUL ELECTRONICS*****END OF FILE****/
