#ifndef POKEPI_UI_H
#define POKEPI_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../lvgl/lvgl.h"

extern lv_obj_t * Loader;
extern lv_obj_t * Image1;
extern lv_obj_t * Loading_Text;
extern lv_obj_t * Home;
extern lv_obj_t * Image5;
extern lv_obj_t * Object2;


LV_IMG_DECLARE(img_boot_png);   // assets\boot.png
LV_IMG_DECLARE(img_small_png);   // assets\small.png

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
