#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>

// Pre-condición, el archivo a copiar existe y es regular, el archivo destino no existe
void cp1(const char *src){
	struct stat statbuf;
	stat(src, &statbuf);
	int fd1;
	
	if ((fd1 = open(src, O_RDONLY)) < 0) {
		printf("cp0: Error, no se pudo abrir el archivo %s.\n", src);
		return;
	}else{
		int fd2;
		if((fd2 = open("Copia.txt", O_WRONLY | O_APPEND | O_CREAT, 0644)) < 0){
			printf("cp0: Error, no se pudo crear el archivo %s.\n", "Copia.txt");
			return;
		}
		ftruncate(fd2, statbuf.st_size);
		char *source = mmap(NULL, statbuf.st_size, PROT_READ, MAP_SHARED, fd1, 0);
		char *dest = mmap(NULL, statbuf.st_size, PROT_WRITE, MAP_SHARED, fd2, 0);

		//memcpy((void *)dest, (const void *)source, statbuf.st_size);

		munmap(source, statbuf.st_size);
		munmap(dest, statbuf.st_size);

		close(fd1);
		close(fd2);
	}
}

int main(int argc, char *argv[]){
	if(argc!=2 ){
		printf("cp1: Error, ingrese un único archivo.\n");
		return 1;
	}
	cp1(argv[1]);
	return 0;
}
