/**
 * @file main
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
#include "lv_drivers/sdl/sdl.h"
#include "screens/boot.h"
#include "screens/main.h"
#include "styles/main_screen_style.h"

#if !defined(TARGET_SIMULATOR_HAL) && !defined(TARGET_NOTKIAV2_HAL)
    #error "No target hal selected, please define TARGET_SIMULATOR_HAL or TARGET_NOTKIAV2_HAL"
#elif defined(TARGET_SIMULATOR_HAL) && defined(TARGET_NOTKIAV2_HAL)
    #error "Define only one target"
#elif defined(TARGET_SIMULATOR_HAL)
    #include "hal/simulator.h"
#else
    #include "hal/notkiav2.h"
#endif
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
int main(int argc, char **argv)
{
  (void)argc; /*Unused*/
  (void)argv; /*Unused*/

  /*Initialize LVGL*/
  lv_init();

  /*Initialize the HAL (display, input devices, tick) for LVGL*/
  hal_init();
  
  styles_init();
  
  show_main_screen();

  while(1) {
      /* Periodically call the lv_task handler.
       * It could be done in a timer interrupt or an OS task too.*/
      lv_timer_handler();
      usleep(5 * 1000);
  }

  return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
