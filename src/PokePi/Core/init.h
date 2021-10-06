#include "../../lvgl/lvgl.h"
#include "../../lv_drivers/display/fbdev.h"
#include "../../lv_drivers/indev/evdev.h"
#include "../../lv_demos/lv_demo.h"
#include "../../icons/mouse_cursor_icon.c"
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/kd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define DISP_BUF_SIZE (128 * 1024)

void terminal_init(void);
/*Set in lv_conf.h as `LV_TICK_CUSTOM_SYS_TIME_EXPR`*/
uint32_t custom_tick_get(void);