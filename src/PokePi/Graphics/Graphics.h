#include "../../lvgl/lvgl.h"
#include "../../lv_demos/lv_demo.h"

extern void PokePi_GUI_init();
//Inits the first GUI screen upon startup of PokePi. 


static lv_obj_t * kb;
static lv_obj_t * ta;
static void kb_event_cb(lv_obj_t * keyboard, lv_event_t e);
static void kb_create(void);
static void ta_event_cb(lv_obj_t * ta_local, lv_event_t e);

static void exit_button_event_handler(lv_obj_t * obj, lv_event_t event);