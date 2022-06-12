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
#include "styles/main_screen_style.h"

lv_style_t clock_style;

void styles_init(){
    lv_style_init(&clock_style);
    lv_style_set_text_font(&clock_style, &lv_font_montserrat_40);
}
