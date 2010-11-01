#ifndef MONITOR_H
#define MONITOR_H

#include "core.h"

// API calls
void monitor_init();
void monitor_put(char c);
void monitor_clear();
void monitor_write(char *c);
void monitor_writeln(char *c);

// privates
static void move_cursor();
static void scroll();
static u16int get_blank_character();
static void reset_cursor();

#endif
