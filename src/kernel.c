#include "core.h"
#include "monitor.h"

static void printWelcome() {
    char* horizontalLine = "-------------------------------------------------------------------------------";
    char* systemName     = "                          BFOS - Here's the beef!";

    monitor_clear();
    monitor_writeln(horizontalLine);
    monitor_writeln(systemName);
    monitor_writeln(horizontalLine);
}

int kmain(struct multiboot *mboot_ptr)
{
	monitor_init();

	printWelcome();

	return 0xDEADBABA;
}
