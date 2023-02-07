/*
 * SPDX-FileCopyrightText: 2021-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

// This demo UI is adapted from LVGL official example: https://docs.lvgl.io/master/widgets/extra/meter.html#simple-meter

#include "lvgl_demo_ui.h"

static lv_obj_t *meter;
static lv_obj_t * btn;
static lv_disp_rot_t rotation = LV_DISP_ROT_NONE;
static lv_disp_t *lv_display;
static lv_meter_indicator_t *indic;
static lv_style_t bgStyle;


lv_obj_t * ui_Screen1;
lv_obj_t * ui_Arc2;
lv_obj_t * ui_Panel2;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Label3;

lv_obj_t *tv1;
lv_obj_t *tv2;
lv_obj_t *tv3;


void set_value(int32_t v, bool buttonStatus)
{
	 lv_color_t bgColor;
	 static bool toggleColor = 0;

	 lv_obj_t *disObject = lv_disp_get_scr_act(lv_display);

    lv_meter_set_indicator_end_value(meter, indic, v);

    if(!buttonStatus)
    {
    	toggleColor ^= 1;
    	if(toggleColor)
    	{
    		//White
    		bgColor = lv_color_hex(0xFFFFFF);
    	}
    	else
    	{
    		//black
    		bgColor = lv_color_hex(0x000000);
    	}
        lv_obj_add_style(disObject, &bgStyle, 0);
        lv_style_set_bg_color(&bgStyle, bgColor);



//        rotation++;
//        if (rotation > LV_DISP_ROT_270)
//        {
//            rotation = LV_DISP_ROT_NONE;
//        }
//        lv_disp_set_rotation(lv_display, rotation);
    }

}

void example_lvgl_demo_ui(lv_disp_t *disp)
{
	 lv_color_t bgColor;
	lv_display = disp;
	lv_obj_t *dis;
	lv_obj_t *scr = lv_disp_get_scr_act(disp);

	bgColor = lv_color_hex(0x101418);
	lv_style_init(&bgStyle);


	dis = lv_tileview_create(scr);
	lv_obj_align(dis, LV_ALIGN_TOP_RIGHT, 0, 0);

	ui_Screen1 = lv_tileview_add_tile(dis, 0, 0, LV_DIR_HOR);
	tv2 = lv_tileview_add_tile(dis, 0, 1, LV_DIR_HOR);
	tv3 = lv_tileview_add_tile(dis, 0, 2, LV_DIR_HOR);

	lv_obj_add_style(ui_Screen1, &bgStyle, 0);
	lv_style_set_bg_color(&bgStyle, bgColor);

//    meter = lv_meter_create(ui_Screen1);
//    lv_obj_center(meter);
//    lv_obj_set_size(meter, 200, 200);
//
//    /*Add a scale first*/
//    lv_meter_scale_t *scale = lv_meter_add_scale(meter);
//    lv_meter_set_scale_ticks(meter, scale, 41, 2, 10, lv_palette_main(LV_PALETTE_GREY));
//    lv_meter_set_scale_major_ticks(meter, scale, 8, 4, 15, lv_color_black(), 10);
//
//
//
//    /*Add a blue arc to the start*/
//    indic = lv_meter_add_arc(meter, scale, 3, lv_palette_main(LV_PALETTE_BLUE), 0);
//    lv_meter_set_indicator_start_value(meter, indic, 0);
//    lv_meter_set_indicator_end_value(meter, indic, 20);
//
//    /*Make the tick lines blue at the start of the scale*/
//    indic = lv_meter_add_scale_lines(meter, scale, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_BLUE), false, 0);
//    lv_meter_set_indicator_start_value(meter, indic, 0);
//    lv_meter_set_indicator_end_value(meter, indic, 20);
//
//    /*Add a red arc to the end*/
//    indic = lv_meter_add_arc(meter, scale, 3, lv_palette_main(LV_PALETTE_RED), 0);
//    lv_meter_set_indicator_start_value(meter, indic, 80);
//    lv_meter_set_indicator_end_value(meter, indic, 100);
//
//    /*Make the tick lines red at the end of the scale*/
//    indic = lv_meter_add_scale_lines(meter, scale, lv_palette_main(LV_PALETTE_RED), lv_palette_main(LV_PALETTE_RED), false, 0);
//    lv_meter_set_indicator_start_value(meter, indic, 80);
//    lv_meter_set_indicator_end_value(meter, indic, 100);
//
//    /*Add a needle line indicator*/
//    indic = lv_meter_add_needle_line(meter, scale, 4, lv_palette_main(LV_PALETTE_GREY), -10);
//
//    btn = lv_btn_create(ui_Screen1);
//    lv_obj_t * lbl = lv_label_create(btn);
//    lv_label_set_text_static(lbl, LV_SYMBOL_REFRESH" ROTATE");
//    lv_obj_align(btn, LV_ALIGN_BOTTOM_MID, 00, -10);



////    ui_Screen1 = lv_obj_create(tv1);
//    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//
    ui_Arc2 = lv_arc_create(ui_Screen1);
    lv_obj_set_width(ui_Arc2, 240);
    lv_obj_set_height(ui_Arc2, 240);
    lv_obj_set_align(ui_Arc2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Arc2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_arc_set_range(ui_Arc2, 0, 360);
    lv_arc_set_value(ui_Arc2, 360);
    lv_arc_set_bg_angles(ui_Arc2, 0, 360);
    lv_arc_set_mode(ui_Arc2, LV_ARC_MODE_REVERSE);
    lv_arc_set_rotation(ui_Arc2, 270);

    lv_obj_set_style_arc_color(ui_Arc2, lv_color_hex(0xD20000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Arc2, lv_color_hex(0xD20000), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc2, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Arc2, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Arc2, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Arc2, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Arc2, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
//
    ui_Panel2 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Panel2, 200);
    lv_obj_set_height(ui_Panel2, 200);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel2, 360, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0x0E0303), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel2, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel2, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
//
    ui_Panel1 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Panel1, 150);
    lv_obj_set_height(ui_Panel1, 150);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel1, 360, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel1, lv_color_hex(0x080808), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//
    ui_Label2 = lv_label_create(ui_Panel1);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "15:10");
    lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0xC50000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Label2, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_Label2, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label2, &ui_font_wise60, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label3 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label3, 0);
    lv_obj_set_y(ui_Label3, -53);
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
//    lv_label_set_text(ui_Label3, "W");
    lv_label_set_text_static(ui_Label3, LV_SYMBOL_WIFI);
    lv_obj_set_style_text_color(ui_Label3, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
}
