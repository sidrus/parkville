#include "core.h"
#include "monitor.h"
#include "multiboot.h"

void printWelcome() {
    char* horizontalLine = "-------------------------------------------------------------------------------";
    char* systemName     = "                          BFOS - Here's the beef!";
    char* displayType = isMonochromeDisplay() ? "monochrome" : "color";

    monitor_clear();
    monitor_writeln(horizontalLine);
    monitor_writeln(systemName);
    monitor_writeln(horizontalLine);
    monitor_write("Display type: ");
    monitor_writeln(displayType);
};

void printMultibootInfo(multiboot_info_t* info) {
    monitor_write("Lower RAM (kb): ");
	monitor_writeln(uint_to_str(info->mem_lower));

	monitor_write("Upper RAM (kb): ");
	monitor_writeln(uint_to_str(info->mem_upper));

//	monitor_write("Memory Map Length: ");
//	monitor_writeln(uint_to_str(info->mmap_length));

//	monitor_write("Memory Map Address: ");
//	monitor_writeln(uint_to_str(info->mmap_addr));
};

// Main kernel entry point
int kmain(multiboot_info_t* mboot_ptr, u32int magic)
{
	monitor_init();
	printWelcome();
	printMultibootInfo(mboot_ptr);

	return 0xDEADBABA;
};
