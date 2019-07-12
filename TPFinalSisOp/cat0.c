#define _POSIX_C_SOURCE 200809L

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

// Pre-condición el archivo existe y se tiene permiso de lectura
void cat0(const char *file) {
	
	struct stat statbuf;
	stat(file, &statbuf);
	
	// Chequeo si es un archivo regular.
	if (!S_ISREG(statbuf.st_mode))
		printf("cat0: Error, archivo no regular.\n");
	
	int fd;
	
	if ((fd = open(file, O_RDONLY)) < 0)
		printf("cat0: Error, no se pudo abrir el archivo.\n");
		
	char c;
	
	while(read(fd, &c, sizeof(c)!=0))
		printf("%c",c);
	
	close(fd);
	
}

int main(int argc, char *argv[]) {
	
	if (argc != 2)
		printf("cat0: Error, ingresar el nombre de un único archivo.\n");
	
    cat0(argv[1]);
    return 0;
    
}
