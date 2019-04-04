.globl main
// Call libc's wrappers to write(2) and _exit(2):
//
//     void _exit(int status);
//     ssize_t write(int fd, const void *buf, size_t count);
//
main:
        // Call convention: arguments on the stack (reverse order).
        call strlen 
        push $msg
        push $1

        // No declaration needed; asm assumes symbols always exist.
        call posicion_retorno
 
		push $7
        call _exit

.data
posicion_retorno:
		jmp write
		ret
msg:
        .asciz "Hello, world!\n"

