#ifndef MAIN_GC9A01_H_
#define MAIN_GC9A01_H_



#include "esp_lcd_gc9a01.h"

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"

#include "esp_err.h"
#include "esp_log.h"

#define LCD_HOST  SPI2_HOST


#define EXAMPLE_LCD_PIXEL_CLOCK_HZ     (40 * 1000 * 1000)
#define EXAMPLE_LCD_BK_LIGHT_ON_LEVEL  0
#define EXAMPLE_LCD_BK_LIGHT_OFF_LEVEL !EXAMPLE_LCD_BK_LIGHT_ON_LEVEL
#define EXAMPLE_PIN_NUM_SCLK           3
#define EXAMPLE_PIN_NUM_MOSI           2
#define EXAMPLE_PIN_NUM_MISO          -1
#define EXAMPLE_PIN_NUM_LCD_DC         6
#define EXAMPLE_PIN_NUM_LCD_RST        1
#define EXAMPLE_PIN_NUM_LCD_CS         5
#define EXAMPLE_PIN_NUM_BK_LIGHT       10
#define EXAMPLE_PIN_NUM_TOUCH_CS       17

#define EXAMPLE_LCD_H_RES              128
#define EXAMPLE_LCD_V_RES              128

#define EXAMPLE_LCD_CMD_BITS           8
#define EXAMPLE_LCD_PARAM_BITS         8



extern esp_lcd_panel_handle_t panel_handle;

void gc9a01_displayInit(void);


#endif /* MAIN_GC9A01_H_ */
