#include "init.h"
#include <stddef.h>

void terminal_deinit(void){
    /* open the framebuffer virtual console */
    int vconsole_fd = open("/dev/tty0", O_RDWR);
    if (!vconsole_fd) {
        fprintf(stderr,"Could not open virtual console.\n");
        exit(1);
    }
    
    /* disable blanking on the console by setting the KD_GRAPHICS mode */
    if (ioctl( vconsole_fd, KDSETMODE, KD_TEXT))
    {
        fprintf(stderr,"Could not set virtual console to KD_GRAPHICS mode.\n");
        exit(1);      
    }

    close(vconsole_fd);
}

void terminal_init(void){
    /* open the framebuffer virtual console */
    int vconsole_fd = open("/dev/tty0", O_RDWR);
    if (!vconsole_fd) {
        fprintf(stderr,"Could not open virtual console.\n");
        exit(1);
    }
    
    /* disable blanking on the console by setting the KD_GRAPHICS mode */
    if (ioctl( vconsole_fd, KDSETMODE, KD_GRAPHICS))
    {
        fprintf(stderr,"Could not set virtual console to KD_GRAPHICS mode.\n");
        exit(1);      
    }

    close(vconsole_fd);

    /* no chdir and no stdio close */
    daemon(1,1);
}


void PokePi_Core_exit(){
    terminal_deinit();
    exit(0);
}

void PokePi_Core_init(void)
{
    terminal_init(); //virtual terminal to make sure lvgl is lvgl is uninterrupted

    /*LittlevGL init*/
    lv_init();

    /*Linux frame buffer device init*/
    fbdev_init();

    /*A small buffer for LittlevGL to draw the screen's content*/
    static lv_color_t buf[DISP_BUF_SIZE];

    /*Initialize a descriptor for the buffer*/
    static lv_disp_draw_buf_t disp_buf;
    lv_disp_draw_buf_init(&disp_buf, buf, NULL, DISP_BUF_SIZE);

    /*Initialize and register a display driver*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf   = &disp_buf;
    disp_drv.flush_cb   = fbdev_flush;
    disp_drv.hor_res    = 800;
    disp_drv.ver_res    = 480;
    lv_disp_drv_register(&disp_drv);

	evdev_init();

	/* Set up touchpad input device interface */
	lv_indev_drv_t indev_drv;
	lv_indev_drv_init(&indev_drv);
	indev_drv.type = LV_INDEV_TYPE_POINTER;
	indev_drv.read_cb = evdev_read;
	lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv);

    /*Set a cursor for the mouse*/
    //LV_IMG_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
    lv_obj_t * cursor_obj = lv_img_create(lv_scr_act()); /*Create an image object for the cursor */
    lv_img_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
    lv_indev_set_cursor(mouse_indev, cursor_obj); 


    /*Create a Demo*/
    //lv_demo_music();
    PokePi_GUI_init();

    /*Handle LitlevGL tasks (tickless mode)*/
    while(1) {
        lv_task_handler();
        usleep(5000);
    }

    return 0;
}

/*Set in lv_conf.h as `LV_TICK_CUSTOM_SYS_TIME_EXPR`*/
uint32_t custom_tick_get(void)
{
    static uint64_t start_ms = 0;
    if(start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}
