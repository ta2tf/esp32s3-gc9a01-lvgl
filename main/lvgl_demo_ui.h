/**
 ******************************************************************************
 *							USEFUL ELECTRONICS
 ******************************************************************************/
/**
 ******************************************************************************
 * @file    :  lvgl_demo_ui.h
 * @author  :  WARD ALMASARANI
 * @version :  v.1.0
 * @date    :  Feb 1, 2023
 * @link    :  https://www.youtube.com/@usefulelectronics
 *			   Hold Ctrl button and click on the link to be directed to
			   Useful Electronics YouTube channel	
 ******************************************************************************/

#ifndef MAIN_LVGL_DEMO_UI_H_
#define MAIN_LVGL_DEMO_UI_H_


/* INCLUDES ------------------------------------------------------------------*/
#include "lvgl.h"
/* MACROS --------------------------------------------------------------------*/

/* ENUMORATIONS --------------------------------------------------------------*/

/* STRUCTURES & TYPEDEFS -----------------------------------------------------*/

/* VARIABLES -----------------------------------------------------------------*/
extern lv_obj_t * ui_Screen1;
extern lv_obj_t * ui_Arc2;
extern lv_obj_t * ui_Panel2;
extern lv_obj_t * ui_Panel1;
extern lv_obj_t * ui_Label2;
extern lv_obj_t * ui_Label3;





LV_FONT_DECLARE(ui_font_wise60);



/* FUNCTIONS DECLARATION -----------------------------------------------------*/
void set_value(int32_t v, bool buttonStatus);

void ui_init(void);



#endif /* MAIN_LVGL_DEMO_UI_H_ */

/*************************************** USEFUL ELECTRONICS*****END OF FILE****/
