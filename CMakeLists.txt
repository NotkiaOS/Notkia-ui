cmake_minimum_required(VERSION 3.10)
project(lvgl C)
set(CMAKE_C_STANDARD 11)#C11

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE INCLUDES "./*.h" )

add_subdirectory(lvgl)
add_subdirectory(lv_drivers)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

find_package(SDL2 REQUIRED SDL2)
include_directories(${SDL2_INCLUDE_DIRS})
add_executable(main main.c hal/simulator.c hal/notkiav2.c screens/boot.c screens/main.c styles/main_screen_style.c ${SOURCES} ${INCLUDES})
add_compile_definitions(LV_CONF_INCLUDE_SIMPLE)
target_link_libraries(main PRIVATE lvgl lvgl::examples lvgl::demos lvgl::drivers ${SDL2_LIBRARIES})
add_compile_definitions(TARGET_SIMULATOR_HAL)
add_custom_target (run COMMAND ${EXECUTABLE_OUTPUT_PATH}/main)
