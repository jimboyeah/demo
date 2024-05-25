/**
 * @file k0001-generic-errors.c
 * @author Jenago (jimbowhy@foxmail.com)
 * @brief  Kernel Programming Tutorials - k0001 - Linux generic errors
 * @version 0.1
 * @date 2024-05-17
 * @ref https://github.dev/torvalds/linux/blob/master/include/uapi/asm-generic/errno-base.h
 * @ref https://github.dev/torvalds/linux/blob/master/include/uapi/asm-generic/ioctl.h
 * @ref https://github.dev/torvalds/linux/blob/master/drivers/md/dm-vdo/errors.c
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <asm-generic/errno-base.h>

int main(int argc, char* argv[] )
{
    printf("Hello Kernel Programming!\n%s\n", argv[0]);
}
