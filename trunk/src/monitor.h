#ifndef MONITOR_H
#define MONITOR_H

#include "core.h"

// API calls
void monitor_init();
void monitor_put(char c);
void monitor_clear();
void monitor_write(char *c);
void monitor_writeln(char *c);

static _Bool isMonochromeDisplay(void)
{
    _Bool type;
    char c=(*(volatile u16int*)0x410)&0x30;

    //c can be 0x00 or 0x20 for colour, 0x30 for mono.
    return (c==0x30);
};

// privates
static void move_cursor();
static void scroll();
static u16int get_blank_character();
static void reset_cursor();

#endif
