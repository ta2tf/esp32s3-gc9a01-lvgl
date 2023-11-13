// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: tqt128

#include "ui.h"

void ui_Screen1_screen_init(void)
{
ui_Screen1 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x050505), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image1 = lv_img_create(ui_Screen1);
lv_img_set_src(ui_Image1, &ui_img_wifi3_png);
lv_obj_set_width( ui_Image1, 128);
lv_obj_set_height( ui_Image1, 128);
lv_obj_set_align( ui_Image1, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image1, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Spinner2 = lv_spinner_create(ui_Screen1,1000,90);
lv_obj_set_width( ui_Spinner2, 173);
lv_obj_set_height( ui_Spinner2, 183);
lv_obj_set_x( ui_Spinner2, 0 );
lv_obj_set_y( ui_Spinner2, 48 );
lv_obj_set_align( ui_Spinner2, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Spinner2, LV_OBJ_FLAG_CLICKABLE );    /// Flags
lv_obj_set_style_arc_color(ui_Spinner2, lv_color_hex(0x4040FF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_Spinner2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_Spinner2, 32, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_arc_color(ui_Spinner2, lv_color_hex(0x08E3F9), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_Spinner2, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_Spinner2, 10, LV_PART_INDICATOR| LV_STATE_DEFAULT);

}
