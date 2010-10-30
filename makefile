# Makefile based on JamesM's kernel tutorials.

SRCDIR = src

SOURCES = $(SRCDIR)/boot-stage2.o \
          $(SRCDIR)/kernel.o \
          $(SRCDIR)/monitor.o

CFLAGS  = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector
LDFLAGS = -T link.ld -m elf_i386
ASFLAGS = -f elf

# Main build recipe
all: $(SOURCES) link

link:
	ld $(LDFLAGS) -o bin/kernel $(SOURCES)

# Recipe for assembly files
.s.o:
	nasm $(ASFLAGS) $<

# Clean the build
.PHONY: clean
clean:
	-rm src/*.o bin/kernel
