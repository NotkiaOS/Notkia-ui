#include <lvgl.h>
#include <time.h>
#include <stdlib.h>

lv_obj_t *snake_game_menu_screen_obj;
lv_obj_t *snake_game_screen;

lv_obj_t * canvas;
#define ROW 11
#define COL 14
int gameover;
int key=1;

int x, y, fruitx, fruity, flag;

int handx, handy;
int tailx, taily;
int tailmax = 4;//Snake length
int gameover=0;//Determine whether the game is over
	
int disp[11][14];
int direction;
int point_head[1];
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
            if(disp[i][j]>1){
                 lv_draw_rect_dsc_init(&rect_dsc);
                 rect_dsc.bg_color = lv_palette_main(LV_PALETTE_RED);
            }
            //if(disp[i][j]==3){
            //     lv_draw_rect_dsc_init(&rect_dsc);
            //     rect_dsc.bg_color = lv_palette_main(LV_PALETTE_BLUE);
            //}
            lv_canvas_draw_rect(canvas, 20*i, 20*j, 20, 20, &rect_dsc);
        }
    }
}

void logic(lv_timer_t * timer)
{
	for(int i=0;i<ROW;i++)
			for(int j=0;j<COL;j++)
				if (disp[i][j] == 1)
				{
					handx = i;
					handy = j;
					printf("Handx: %d, Handy: %d\n", handx, handy);
				}//Find head coordinates
		for(int i=0;i<ROW;i++)
			for(int j=0;j<COL;j++)
				if (disp[i][j] == tailmax)
				{
					tailx = i;
					taily = j;
			    printf("Tailx: %d, Taily: %d\n", tailx, taily);
				}//Find tail coordinates
	    //key=2;
	    printf("Key is: %d\n", key);
		switch (key)
		{
		case 0:
			if (disp[handx - 1][handy] == 0)//Judge walkability
			{
				disp[tailx][taily] = 0;
				for (int i = 0; i < ROW; i++)
					for (int j = 0; j < COL; j++)
						if (disp[i][j] != 0 && disp[i][j] != -1 && disp[i][j] != -2)
							disp[i][j]++;
				disp[handx - 1][handy] = 1;
			}
			else if (disp[handx - 1][handy] == -1)//Judge food
			{
				for (int i = 0;i < ROW; i++)
					for (int j = 0; j < COL; j++)
						if (disp[i][j] != 0 && disp[i][j] != -1 && disp[i][j] != -2&&disp[i][j]!=-5)
							disp[i][j]++;
				disp[handx - 1][handy] = 1;
				tailmax++;
			    //toeat(a);
			}
			else gameover = 1;
			break;
		case 1:
			if (disp[handx + 1][handy] == 0)
			{
				disp[tailx][taily] = 0;
				for (int i = 0; i < ROW; i++)
					for (int j = 0; j < COL; j++)
						if (disp[i][j] != 0 && disp[i][j] != -1 && disp[i][j] != -2 && disp[i][j] != -5)
							disp[i][j]++;
				disp[handx + 1][handy] = 1;
			}
			else if (disp[handx + 1][handy] == -1)
			{
				for (int i = 0; i < ROW; i++)
					for (int j = 0; j < COL; j++)
						if (disp[i][j] != 0 && disp[i][j] != -1 && disp[i][j] != -2 && disp[i][j] != -5)
							disp[i][j]++;
				disp[handx + 1][handy] = 1;
				tailmax++;
				//toeat(a);
			}
			else gameover = 1;
			break;
		case 2:
			if (disp[handx][handy-1] == 0)
			{
				disp[tailx][taily] = 0;
				for (int i = 0; i < ROW; i++)
					for (int j = 0; j < COL; j++)
						if (disp[i][j] != 0 && disp[i][j] != -1 && disp[i][j] != -2 && disp[i][j] != -5)
							disp[i][j]++;
				disp[handx][handy - 1] = 1;
			}
			else if (disp[handx][handy-1] == -1)
			{
				for (int i = 0; i < ROW; i++)
					for (int j = 0; j < COL; j++)
						if (disp[i][j] != 0 && disp[i][j] != -1 && disp[i][j] != -2 && disp[i][j] != -5)
							disp[i][j]++;
				disp[handx][handy - 1] = 1;
				tailmax++;
				//toeat(a);
			}
			else gameover = 1;
			break;
		case 3:
			if (disp[handx][handy + 1] == 0)
			{
				disp[tailx][taily] = 0;
				for (int i = 0; i < ROW; i++)
					for (int j = 0; j < COL; j++)
						if (disp[i][j] != 0 && disp[i][j] != -1 && disp[i][j] != -2 && disp[i][j] != -5)
							disp[i][j]++;
				disp[handx][handy + 1] = 1;
			}
			else if (disp[handx][handy + 1] == -1)
			{
				for (int i = 0; i < ROW; i++)
					for (int j = 0; j < COL; j++)
						if (disp[i][j] != 0 && disp[i][j] != -1 && disp[i][j] != -2 && disp[i][j] != -5)
							disp[i][j]++;
				disp[handx][handy + 1] = 1;
				tailmax++;
				//toeat(a);
			}
			else gameover = 1;
			break;
		}
		draw_snake_game_canvas();
}

void snake_game_task(lv_timer_t * timer)
{
     for(int i=0; i<11; i++){
        for(int j=0; j<14; j++){
            if(disp[i][j]!=0){
                disp[i+1][j]=disp[i][j];
                printf("Moved %d %d to %d %d\n", i,j,i+1, j);
                disp[i][j]=0;
                i=100;
            }
        }
     }
     draw_snake_game_canvas();
}

static void snake_game_event_handler(lv_event_t * e)
{
    int key_pressed=lv_indev_get_key(lv_indev_get_act());
    if(key_pressed==LV_KEY_UP){
        key=2;
    } else if(key_pressed==LV_KEY_DOWN){
        key=3;
    } else if(key_pressed==LV_KEY_LEFT){
        key=0;
    } else if(key_pressed==LV_KEY_RIGHT){
        key=1;
    }

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
    
    disp[5][5]=1;
    disp[4][5]=2;
    disp[3][5]=3;
    disp[2][5]=4;
    
    lv_timer_t * timer = lv_timer_create(logic, 500, 0);
    
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
