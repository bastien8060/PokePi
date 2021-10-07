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
#include "../../lv_demos/lv_demo.h"
// First GUI screen upon startup of PokePi. Sample Mockup for now. 
extern void PokePi_GUI_init(void);
// Text Area events callback. TextArea used for keyboard in this sample screen
static void ta_event_cb(lv_event_t * e);
// Exit Button Click events callback. It handles button clicks. It is made to exit PokePi after confirmation.
static void exit_button_event_cb(lv_event_t * e);
// Scan Button Click events callback. Dummy Callback for now.
static void scan_button_event_handler(lv_event_t * e);

//REDEFINITION/CLONES
//Copied to prevent recursive import between init and graphics.

//de-locks terminal before exit
void terminal_deinit(void);
//exit PokePi and de-init everything 
void PokePi_Core_exit(void);