#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

void backtrace(void) {
	uint8_t numfrm = 1;
	int *FP = __builtin_frame_address(0);
	
	while(*FP) {
		 unsigned int *ADDR = &(*FP) + 1;
		
		printf("#%u [%p] %p (%p %p %p)\n", 
			numfrm++, 
			(void *) *FP, 
			(void *) *ADDR, 
			(void *) *(ADDR + 1), 
			(void *) *(ADDR + 2), 
			(void *) *(ADDR + 3)
		);
		FP = (void*) * FP;
	}
}

void my_write(int fd, const void *msg, size_t count) {
    backtrace();
    fprintf(stderr, "=> write(%d, %p, %zu)\n", fd, msg, count);
    write(fd, msg, count);
}

void recurse(int level) {
    if (level > 0)
        recurse(level - 1);
    else
        my_write(2, "Hello, world!\n", 15);
}

void start_call_tree() {
    recurse(5);
}

int main(void) {
    start_call_tree();
}
