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
