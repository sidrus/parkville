# Object files
SOURCES = kernel.o display.o iostream.o boot-stage2.o

# Target
OUTPATH = kernel32.bin

# Compilation options
CFLAGS  = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector
LDFLAGS = -T link.ld -m elf_i386
ASFLAGS = -f elf

all: $(SOURCES)
	link

link:
	ld $(LDFLAGS) -o $(OUTPATH) $(SOURCES)

.asm.o:
	nasm $(ASFLAGS) $<

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY : clean
clean:
	-rm $(SOURCES) $(OUTPATH)