#include "PokePi/Core/init.c"
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define DISP_BUF_SIZE (128 * 1024)

int g_argc;
char **g_argv;
extern char *FBDEV_PATH = "";

int main(int argc, char **argv)
{
    if (argc > 1){
        FBDEV_PATH = argv[1];
    }else{
        FBDEV_PATH = "/dev/fb0";
    }
    
    char template[] = "Using Framebuffer: [%s]";
    char message[sizeof(template)-2+sizeof(FBDEV_PATH)];
    sprintf(message,template,FBDEV_PATH);

    LV_LOG_WARN(message);

    PokePi_Core_init();
    return 0;
}