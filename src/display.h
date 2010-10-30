/*
 * File:   display.h
 * Author: brandon
 *
 * Created on October 28, 2010, 10:40 PM
 */

#ifndef DISPLAY_H
#define	DISPLAY_H

#include "core.h"

// API calls
void monitor_init();
void monitor_put(char c);
void monitor_clear();
void monitor_write(char *c);

// privates
void move_cursor();
void scroll();
void reset_cursor();

u16int get_blank_character();

#endif	/* DISPLAY_H */

