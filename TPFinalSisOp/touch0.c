#define _POSIX_C_SOURCE 200809L

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void touch0(const char *file) {
	int fd;
	
	if ((fd = open(file, O_CREAT|O_WRONLY|O_TRUNC, O_RDONLY)) < 0) {
		printf("cat0: Error, no se pudo abrir el archivo %s.\n", file);
		return;
	}
	
	close(fd);
}

int main(int argc, char *argv[]) {
	
	if (argc != 2){
		printf("touch0: Error, ingresar el nombre de un único archivo.\n");
		return 1;
	}
	
    touch0(argv[1]);
    return 0;
    
}
