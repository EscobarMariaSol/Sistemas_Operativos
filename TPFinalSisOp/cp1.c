#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>

// Pre-condición, el archivo a copiar existe y es regular, el archivo destino no existe
void cp1(const char *src, const char *dst){
	struct stat statbuf;
	stat(src, &statbuf);
	int fd1;
	
	if ((fd1 = open(src, O_RDONLY)) < 0) {
		printf("cp1: Error al abrir el archivo %s.\n", src);
		return;
	}
	else{
		int fd2;
		if((fd2 = open(dst, O_CREAT|O_RDWR, S_IRWXU)) < 0){
			printf("cp1: Error creando el archivo %s.\n", dst);
			return;
		}
		
		if (lseek (fd2, statbuf.st_size, SEEK_SET) < 0) {
			printf ("cp1: Error, creando el nuevo archivo.\n");
			return;
		}
		write (fd2, "", 1);
		char *source = mmap(NULL, statbuf.st_size, PROT_READ, MAP_SHARED, fd1, 0);

		char *dest = mmap(NULL, statbuf.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd2, 0);
		
		memcpy(dest, source, statbuf.st_size);
		
		munmap(source, statbuf.st_size);
		munmap(dest, statbuf.st_size);

		close(fd1);
		close(fd2);
	}
}

int main(int argc, char *argv[]){
	if(argc != 3 ){
		printf("cp1: Error, ingrese los nombres de los archivos origen y destino.\n");
		return 1;
	}
	cp1(argv[1], argv[2]);
	return 0;
}
