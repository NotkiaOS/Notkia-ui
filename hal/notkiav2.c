/**
 * @file simulator
 *
 */

/*********************
 *      INCLUDES
 *********************/
#define _DEFAULT_SOURCE /* needed for usleep() */
#include <stdlib.h>
#include <unistd.h>
#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/evdev.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
 /**
 * Initialize the Hardware Abstraction Layer (HAL) for the LVGL graphics
 * library
 */

#if defined(TARGET_NOTKIAV2_HAL)
    void hal_init(void)
    {
        fbdev_init();
        int height, width;
        fbdev_get_sizes(&width, &height);
        
        /*Create a display buffer*/
        lv_disp_draw_buf_t disp_buf1;
        lv_color_t buf1_1[width * 100];
        lv_disp_draw_buf_init(&disp_buf1, buf1_1, NULL, width * 100);

        /*Create a display*/
        static lv_disp_drv_t disp_drv;
        lv_disp_drv_init(&disp_drv); /*Basic initialization*/
        disp_drv.draw_buf = &disp_buf1;
        disp_drv.flush_cb = fbdev_flush;
        disp_drv.hor_res = width;
        disp_drv.ver_res = height;

        lv_disp_t * disp = lv_disp_drv_register(&disp_drv);

        lv_theme_t * th = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK, LV_FONT_DEFAULT);
        lv_disp_set_theme(disp, th);

        lv_group_t * g = lv_group_create();
        lv_group_set_default(g);
        
        evdev_init();
        
        static lv_indev_drv_t indev_drv_2;
        lv_indev_drv_init(&indev_drv_2); /*Basic initialization*/
        indev_drv_2.type = LV_INDEV_TYPE_KEYPAD;
        indev_drv_2.read_cb = evdev_read;
        lv_indev_t *kb_indev = lv_indev_drv_register(&indev_drv_2);
        lv_indev_set_group(kb_indev, g);
    }
#endif

/**********************
 *   STATIC FUNCTIONS
 **********************/
