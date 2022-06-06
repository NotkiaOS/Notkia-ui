/**
 * @file lv_event.h
 *
 */

#ifndef LV_NOTKIAV2_HAL_H
#define LV_NOTKIAV2_HAL_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
#if defined(TARGET_NOTKIAV2_HAL)
    void hal_init();
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_NOTKIAV2_HAL_H*/
