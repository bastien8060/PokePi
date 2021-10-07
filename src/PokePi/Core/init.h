#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/kd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../../lvgl/lvgl.h"
#include "../../lv_drivers/display/fbdev.h"
#include "../../lv_drivers/indev/evdev.h"
#include "../../lv_demos/lv_demo.h"
#include "../../icons/mouse_cursor_icon.c"
#include "../Graphics/Graphics.c"


#define DISP_BUF_SIZE (128 * 1024)

// PokePi GUI Init + Terminal Init
// Handles Preparation for terminal to handle Framebuffer Application correctly.
void PokePi_Core_init(void);
//creates a virtual terminal to prevent anything from interfering with application/framebuffer
void terminal_init(void);
//de-locks terminal before exit
void terminal_deinit(void);
//exit PokePi and de-init everything 
void PokePi_Core_exit(void);
/*Set in lv_conf.h as `LV_TICK_CUSTOM_SYS_TIME_EXPR`
Custom Tick for LVGL to keep track of time. Used mostly to handle drawing Animations.*/
uint32_t custom_tick_get(void);