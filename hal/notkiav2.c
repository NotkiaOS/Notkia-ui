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

#if defined(TARGET_NOTKIAV2_HAL)
    void hal_init(void)
    {
        //TODO: write stuff here
    }
#endif

/**********************
 *   STATIC FUNCTIONS
 **********************/
