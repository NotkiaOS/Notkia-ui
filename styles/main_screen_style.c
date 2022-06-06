#include <lvgl.h>
#include "styles/main_screen_style.h"
#include "styles/main_screen_style.h"
#include "styles/main_screen_style.h"

void styles_init(){
    lv_style_init(&clock_style);
    lv_style_set_text_font(&clock_style, &lv_font_montserrat_38);
}
