#include "core.h"
#include "iocore.h"

#ifndef MONITOR_H
#define MONITOR_H

// API calls
void monitor_init();
void monitor_put(char c);
void monitor_clear();
void monitor_write(char *c);

// privates
static void move_cursor();
static void scroll();
static u16int get_blank_character();
static void reset_cursor();

#endif
