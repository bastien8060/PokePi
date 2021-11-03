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

int main(int argc, char **argv)
{
    PokePi_Core_init();
    return 0;
}