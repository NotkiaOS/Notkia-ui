#include <lvgl.h>
#include <time.h>
#include "styles/main_screen_style.h"

lv_obj_t *main_screen;
lv_obj_t * clock_label;

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
}
