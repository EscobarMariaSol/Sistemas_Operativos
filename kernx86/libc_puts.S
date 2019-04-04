#include <sys/syscall.h>  // SYS_write, SYS_exit

//
// See: <https://en.wikibooks.org/wiki/X86_Assembly/Interfacing_with_Linux>.
//

.globl main
main:
        push $msg       
        call puts
        int $0x80
		
		push $7
        call fin
        int $0x80

.data

fin:
		pop %ebx
		pop %ecx
		pop %eax
		ret

msg:
        .ascii "Hello, world!\n"
