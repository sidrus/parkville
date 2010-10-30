// main.c -- Defines the C-code kernel entry point, calls initialisation routines.
// Made for JamesM's tutorials

#include "monitor.h"

int kmain(struct multiboot *mboot_ptr)
{
	monitor_init();
	monitor_clear();

	int x;
	for(x=0; x<25; x++) {
		monitor_write("Hello, World! ");
		monitor_put('0' + x);
		monitor_write("\n\r");
	}

	return 0xDEADBABA;
}
