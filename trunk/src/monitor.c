#include "monitor.h"

// Pointer to the start of the VGA frame buffer
u16int *video_memory = (u16int *)0xB8000;

u16int VGA_PORT = 0x3D4;

// Cursor position data
u8int cursorX = 0;
u8int cursorY = 0;

// Cursor color
u8int DEFAULT_COLOR = 0x07;
//u8int DEFAULT_COLOR = 0x2A;
u16int BLANK_CHARACTER;

// Common Character Constants
const u8int BACKSPACE = 0x08;
const u8int TAB       = 0x09;
const u8int LINEFEED  = 0x0A;
const u8int RETURN    = 0x0D;

// Public Functions
void monitor_init() {
	BLANK_CHARACTER = DEFAULT_COLOR | 0x21;
};

void monitor_put(char c) {
	u8int colorByte = DEFAULT_COLOR;
	u16int attribute = colorByte << 8;
	u16int *location;

	// handle a backspace
	if(c==BACKSPACE && cursorX) {
		cursorX--;
	}

	// handle tabs
	else if(c == TAB) {
		cursorX = (cursorX + 8) & ~(8 - 1);
	}

	// handle carriage return
	else if(c == RETURN) {
		cursorX = 0;
	}

	// handle new line
	else if(c == LINEFEED) {
		cursorX = 0;
		cursorY++;
	}

	else if(c >= ' ') {
		location = video_memory + (cursorY * 80 + cursorX);
		*location = c | attribute;
		cursorX++;
	}

	if(cursorX >= 80) {
		cursorX = 0;
		cursorY++;
	}

	scroll();
	move_cursor();
};

void monitor_clear() {
	u16int blank = get_blank_character();

	int i;
	for(i=0; i<80*25; i++) {
		video_memory[i] = blank;
	}

	reset_cursor();
};

void monitor_write(char *c) {
	int i = 0;
	while(c[i]) {
		monitor_put(c[i++]);
	}
};

void monitor_writeln(char *c) {
    monitor_write(c);
    monitor_put(LINEFEED);
    monitor_put(RETURN);
};

// Returns the cursor to the 0,0 position
void reset_cursor() {
	cursorX = 0;
	cursorY = 0;
	move_cursor();
};

// Private Functions
static void move_cursor() {
	u16int cursorLocation = cursorY * 80 + cursorX;

	// Send the high cursor byte
	writeByte(VGA_PORT, 14);
	writeByte(VGA_PORT, cursorLocation >> 8);

	// Send the low cursor byte
	writeByte(VGA_PORT, 15);
	writeByte(VGA_PORT, cursorLocation);
};

/*
 * Scroll the display screen up by 1 row.  This function shifts all the values
 * in the memory buffer up by 1 row, then draws a blank line on the bottom of
 * the screen.
 */
static void scroll() {
	u16int blank = get_blank_character();

	// Row 25 is the end, so we need to scroll up
	if(cursorY >= 25) {
		// move the current text chunk
		int i;
		for(i=0; i < 24 * 80; i++) {
			video_memory[i] = video_memory[i + 80];
		}

		// the last line should be blank, so write spaces to clear it.
		for( i=24 * 80; i < 25 * 80; i++) {
			video_memory[i] = BLANK_CHARACTER;
		}

		cursorY = 24;
	}
};

// Creates a word representing the blank character.
static u16int get_blank_character() {
	u8int colorByte = DEFAULT_COLOR;
	return (0x20 | (colorByte << 8));
};


