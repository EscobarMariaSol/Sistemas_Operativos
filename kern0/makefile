CFLAGS := -g -m32 -O1

CFLAGS := -g -std=c99 -Wall -Wextra -Wpedantic

CFLAGS += -m32 -O1 -fasm -ffreestanding

SRCS := $(wildcard *.c)

OBJS := $(patsubst %.c, %.o, $(SRCS))

QEMU := qemu-system-i386 -serial mon:stdio

KERN := kern0

BOOT := -kernel $(KERN)

kern0: boot.o $(OBJS)
	ld -m elf_i386 -Ttext 0x100000 --entry comienzo $^ -o $@
	# Verificar imagen Multiboot v1.
	grub-file --is-x86-multiboot $@
	objdump -d kern0 >kern0.asm $@

%.o: %.S
	$(CC) $(CFLAGS) -c $<

qemu: $(KERN)
	$(QEMU) $(BOOT)

qemu-gdb: $(KERN)
	$(QEMU) -kernel kern0 -S -gdb tcp:127.0.0.1:7508 $(BOOT)

gdb:
	gdb -q -s kern0 -n -ex 'target remote 127.0.0.1:7508'

clean:
	rm -f kern0 *.o core kern0.asm

.PHONY: clean qemu qemu-gdb gdb

