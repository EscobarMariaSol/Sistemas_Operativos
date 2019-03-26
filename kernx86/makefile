CFLAGS := -m32 -g -std=c99 -Wall -Wextra -Wpedantic
CFLAGS += -O1 -fno-pic -fno-omit-frame-pointer -no-pie
ASFLAGS = $(CFLAGS)

ASMS := $(wildcard *.S)
SRCS := $(wildcard *.c)

PROG :=$(patsubst %.S, %, $(ASMS))
PROG += $(patsubst %.c, %, $(SRCS))


all: $(PROG)

clean:
	rm -f $(PROG) *.o core

.PHONY: clean all
