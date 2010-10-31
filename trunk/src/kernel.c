#include "core.h"
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
