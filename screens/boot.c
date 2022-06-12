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
#include "screens.h"

lv_obj_t *boot_screen;

void show_boot_screen()
{
    boot_screen = lv_obj_create(NULL);
    lv_scr_load(boot_screen);
    
    // Label
    lv_obj_t * welcome_label = lv_label_create(lv_scr_act());
    lv_label_set_text(welcome_label, "Welcome to NotkiaOS");
    lv_obj_set_width(welcome_label, 200);  /*Set smaller width to make the lines wrap*/
    lv_obj_set_style_text_align(welcome_label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(welcome_label, LV_ALIGN_CENTER, 0, -80);
    
    // Spinner
    lv_obj_t * spinner = lv_spinner_create(lv_scr_act(), 1000, 60);
    lv_obj_set_size(spinner, 70, 70);
    lv_obj_center(spinner);
}
