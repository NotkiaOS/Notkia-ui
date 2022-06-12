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

#include <lvgl.h>
#include <time.h>
#include "styles/main_screen_style.h"

lv_obj_t *main_screen;
lv_obj_t * clock_label;

void key_handler(lv_obj_t * obj, lv_event_t event)    {
	printf("Key: %d pressed\n",  event.code);


}

void clock_update_task(lv_timer_t * timer)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    lv_label_set_text_fmt(clock_label, "%d:%d", tm.tm_hour, tm.tm_min);
}

void show_main_screen()
{
    main_screen = lv_obj_create(NULL);
    lv_scr_load(main_screen);
    lv_group_t * g = lv_group_create();
    lv_group_add_obj(g, lv_scr_act());   
    
    lv_indev_t* cur_drv = NULL;
    for (;;) {
        cur_drv = lv_indev_get_next(cur_drv);
        if (!cur_drv) {
            break;
        }

        if (cur_drv->driver->type == LV_INDEV_TYPE_KEYPAD) {
            break;
        }
    }
    lv_indev_set_group(cur_drv, g);
    
    // Clock
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    
    clock_label = lv_label_create(lv_scr_act());
    lv_obj_add_style(clock_label, &clock_style, 0);
    lv_label_set_text_fmt(clock_label, "%d:%d", tm.tm_hour, tm.tm_min);
    lv_obj_set_style_text_align(clock_label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(clock_label, LV_ALIGN_TOP_LEFT, 0, 0);
    
    lv_timer_t * timer = lv_timer_create(clock_update_task, 500, 0);
    lv_obj_add_event_cb(main_screen, key_handler, LV_EVENT_KEY, NULL);
}
