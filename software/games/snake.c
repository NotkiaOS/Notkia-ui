#include <lvgl.h>
#include <time.h>
#include <stdlib.h>

lv_obj_t *snake_game_menu_screen_obj;
lv_obj_t *snake_game_screen;

lv_obj_t * canvas;

int disp[11][14];

void draw_snake_game_canvas()
{
     printf("Drawing\n");
     lv_draw_rect_dsc_t rect_dsc;
     lv_draw_line_dsc_t line;
     lv_draw_line_dsc_init(&line);
     // Not sure, do we need grid? Commented for now.
    /* for(int i=0; i<11; i++){
            lv_point_t line_points[] = { {20*i, 0}, {20*i, 280}};
            lv_canvas_draw_line(canvas, line_points, 2, &line);
    }
    
    for(int i=0; i<14; i++){
            lv_point_t line_points[] = { {0, 20*i}, {220, 20*i}};
            lv_canvas_draw_line(canvas, line_points, 2, &line);
    }*/
    for(int i=0; i<11; i++){
        for(int j=0; j<14; j++){
            if(disp[i][j]==0){
                 lv_draw_rect_dsc_init(&rect_dsc);
                 rect_dsc.bg_color = lv_palette_main(LV_PALETTE_GREY);
            }
            if(disp[i][j]==1){
                 lv_draw_rect_dsc_init(&rect_dsc);
                 rect_dsc.bg_color = lv_palette_main(LV_PALETTE_GREEN);
            }
            if(disp[i][j]==2){
                 lv_draw_rect_dsc_init(&rect_dsc);
                 rect_dsc.bg_color = lv_palette_main(LV_PALETTE_RED);
            }
            if(disp[i][j]==3){
                 lv_draw_rect_dsc_init(&rect_dsc);
                 rect_dsc.bg_color = lv_palette_main(LV_PALETTE_BLUE);
            }
            lv_canvas_draw_rect(canvas, 20*i, 20*j, 20, 20, &rect_dsc);
        }
    }
}

static void snake_game_event_handler(lv_event_t * e)
{
    key_pressed=lv_indev_get_key(lv_indev_get_act());

}

void start_snake_game()
{
    snake_game_screen = lv_obj_create(NULL);
    lv_scr_load(snake_game_screen);
    lv_obj_del(snake_game_menu_screen_obj);
    static lv_color_t cbuf[LV_CANVAS_BUF_SIZE_TRUE_COLOR(220, 280)];
    
    lv_group_t * g = lv_group_create();
    
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
    
    canvas = lv_canvas_create(lv_scr_act());
    lv_group_add_obj(g, canvas);   
    lv_obj_add_event_cb(canvas, snake_game_event_handler, LV_EVENT_KEY, NULL);
    lv_canvas_set_buffer(canvas, cbuf, 220, 280, LV_IMG_CF_TRUE_COLOR);
    lv_obj_center(canvas);
    lv_canvas_fill_bg(canvas, lv_palette_lighten(LV_PALETTE_GREY, 3), LV_OPA_COVER);
    printf("feeling array\n");
    for(int i=0; i<11; i++){
        for(int j=0; j<14; j++){
            disp[i][j]=0;
        }
    }
    printf("filled array\n");
    
    disp[5][5]=2;
    disp[4][5]=1;
    disp[3][5]=1;
    disp[2][5]=1;
    
    draw_snake_game_canvas();
    
}

static void snake_menu_new_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
        start_snake_game();
    }
}

void snake_game_menu_screen()
{
    snake_game_menu_screen_obj = lv_obj_create(NULL);
    lv_scr_load(snake_game_menu_screen_obj);

    lv_obj_t * list1 = lv_list_create(lv_scr_act());
    lv_obj_set_size(list1, 200, 200);
    lv_obj_center(list1);

    /*Add buttons to the list*/
    lv_obj_t * btn;

    btn = lv_list_add_btn(list1, LV_SYMBOL_FILE, "New Game");
    lv_obj_add_event_cb(btn, snake_menu_new_handler, LV_EVENT_CLICKED, NULL);
}
