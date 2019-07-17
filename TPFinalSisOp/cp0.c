#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

// Pre-condición, el archivo a copiar existe y es regular, el archivo destino no existe
void cp0(const char *src, const char *dst){
	int fd1;
	
	if ((fd1 = open(src, O_RDONLY)) < 0) {
		printf("cp0: Error abriendo el archivo %s.\n", src);
		return;
	}else{
		char c;
		int fd2;
		if((fd2 = open(dst, O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU)) < 0){
			printf("cp0: Error creando  el archivo %s.\n", dst);
			return;
		}

		while(read(fd1, &c, sizeof(c)) != 0){
			write(fd2, (const void *)&c, sizeof(c)); 
		}
		close(fd1);
		close(fd2);
	}
}

int main(int argc, char *argv[]){
	if(argc != 3 ){
		printf("stat0: Error, ingrese los nombres de los archivos origen y destino.\n");
		return 1;
	}
	cp0(argv[1], argv[2]);
	return 0;
}
