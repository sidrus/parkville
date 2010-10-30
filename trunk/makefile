# Makefile for JamesM's kernel tutorials.
# The C and C++ rules are already setup by default.
# The only one that needs changing is the assembler
# rule, as we use nasm instead of GNU as.

SOURCES=src/boot-stage-2.o src/kernel.o src/core.o src/monitor.o

CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector
LDFLAGS=-T link.ld -m elf_i386
ASFLAGS=-f elf

all: $(SOURCES) link 

clean:
	-rm src/*.o bin/kernel

link:
	ld $(LDFLAGS) -o bin/kernel $(SOURCES)

.s.o:
	nasm $(ASFLAGS) $<