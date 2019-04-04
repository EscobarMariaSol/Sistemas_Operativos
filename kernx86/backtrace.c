#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

void backtrace(void) {
	uint8_t numfrm = 1;
	uint32_t *FP = __builtin_frame_address(0);
	
	printf("#numfrm [FP] ADDR ( ARG1 ARG2 ARG3 )\n");
	
	while(*FP) {
		uint32_t *ADDR = (uint32_t *) *FP;
		void *ARG1 = (void*) *ADDR + 4;
		void *ARG2 = (void*) *ADDR + 8;
		void *ARG3 = (void*) *ADDR + 12;
		printf("#%u [%p] %p (%p %p %p)\n",
			numfrm++,
			(void *) *FP,
			(void *) ADDR,
			(void *) (ARG1),
			(void *) (ARG2),
			(void *) (ARG3)
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
