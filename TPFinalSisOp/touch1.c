#define _POSIX_C_SOURCE 200809L

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <utime.h>

void touch1(const char *file) {
	
	struct stat statbuf;
	stat(file, &statbuf);
	
	// Si no es un directorio, abro o creo el archivo
	if (!S_ISDIR(statbuf.st_mode)) {
		int fd;
	
		if ((fd = open(file, O_CREAT|O_RDWR)) < 0) {
			printf("touch1: Error abriendo el archivo %s.\n", file);
			return;
		}
		close(fd);
	}
	
	int res;
	if((res = utime(file, NULL)) < 0)
		printf("touch1: utime error.\n");
}

int main(int argc, char *argv[]) {
	
	if (argc != 2){
		printf("touch1: Error, ingresar el nombre de un único archivo.\n");
		return 1;
	}
	
    touch1(argv[1]);
    return 0;
    
}

