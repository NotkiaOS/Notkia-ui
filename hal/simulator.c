/*
 * NotkiaUI
 * Copyright (C) 2022 Luka Panio <lukapanio@gmail.com>

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.

 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" issue*/
#include <SDL2/SDL.h>
#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"
#include "lv_drivers/sdl/sdl.h"

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
#if defined(TARGET_SIMULATOR_HAL)
    void hal_init()
    {
        /* Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
        sdl_init();
        
        /*Create a display buffer*/
        static lv_disp_draw_buf_t disp_buf1;
        static lv_color_t buf1_1[SDL_HOR_RES * 100];
        lv_disp_draw_buf_init(&disp_buf1, buf1_1, NULL, SDL_HOR_RES * 100);

        /*Create a display*/
        static lv_disp_drv_t disp_drv;
        lv_disp_drv_init(&disp_drv); /*Basic initialization*/
        disp_drv.draw_buf = &disp_buf1;
        disp_drv.flush_cb = sdl_display_flush;
        disp_drv.hor_res = SDL_HOR_RES;
        disp_drv.ver_res = SDL_VER_RES;

        lv_disp_t * disp = lv_disp_drv_register(&disp_drv);

        lv_theme_t * th = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK, LV_FONT_DEFAULT);
        lv_disp_set_theme(disp, th);

        lv_group_t * g = lv_group_create();
        lv_group_set_default(g);

        /* Add the mouse as input device
        * Use the 'mouse' driver which reads the PC's mouse*/
        static lv_indev_drv_t indev_drv_1;
        lv_indev_drv_init(&indev_drv_1); /*Basic initialization*/
        indev_drv_1.type = LV_INDEV_TYPE_POINTER;

        /*This function will be called periodically (by the library) to get the mouse position and state*/
        indev_drv_1.read_cb = sdl_mouse_read;
        lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv_1);

        static lv_indev_drv_t indev_drv_2;
        lv_indev_drv_init(&indev_drv_2); /*Basic initialization*/
        indev_drv_2.type = LV_INDEV_TYPE_KEYPAD;
        indev_drv_2.read_cb = sdl_keyboard_read;
        lv_indev_t *kb_indev = lv_indev_drv_register(&indev_drv_2);
        lv_indev_set_group(kb_indev, g);

        static lv_indev_drv_t indev_drv_3;
        lv_indev_drv_init(&indev_drv_3); /*Basic initialization*/
        indev_drv_3.type = LV_INDEV_TYPE_ENCODER;
        indev_drv_3.read_cb = sdl_mousewheel_read;
        lv_indev_t * enc_indev = lv_indev_drv_register(&indev_drv_3);
        lv_indev_set_group(enc_indev, g);
}
#endif

/**********************
 *   STATIC FUNCTIONS
 **********************/
