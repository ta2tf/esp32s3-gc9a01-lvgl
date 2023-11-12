idf_component_register(
SRCS "main.c" 
SRCS "uart_config.c" 
SRCS "esp_interrupt.c" 

SRCS "hardware/rotary_encoder.c" 
SRCS "hardware/hlk-ld1125h.c"
SRCS "hardware/button.c"
SRCS "wireless/sntp.c"
SRCS "wireless/mqtt.c"
SRCS "wireless/wifi_connect.c"
 
SRCS "display/ui_helpers.c"
SRCS  "display/ui.c"
SRCS "display/display.c"
SRCS "display/gc9a01.c"
SRCS "display/ui_Screen1.c"
SRCS "display/ui_img_autos_png.c"

SRCS "gpio/gpio_config.c"
INCLUDE_DIRS "." "display")
