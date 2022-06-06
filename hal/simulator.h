/**
 * @file lv_event.h
 *
 */

#ifndef LV_SIMULATOR_HAL_H
#define LV_SIMULATOR_HAL_H

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
#if defined(TARGET_SIMULATOR_HAL)
    void hal_init();
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_SIMULATOR_HAL_H*/
