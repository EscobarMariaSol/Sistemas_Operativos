#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// Pre-condición, el archivo a copiar existe y es regular, el archivo destino no existe
void cp0(const char *src){
	int fd1;
	
	if ((fd1 = open(src, O_RDONLY)) < 0) {
		printf("cp0: Error, no se pudo abrir el archivo %s.\n", src);
		return;
	}else{
		char c;
		int fd2;
		if((fd2 = open("Copia.txt", O_WRONLY | O_APPEND | O_CREAT, 0644)) < 0){
			printf("cp0: Error, no se pudo crear el archivo %s.\n", "Copia.txt");
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
	if(argc!=2 ){
		printf("stat0: Error, ingrese un único archivo.\n");
		return 1;
	}
	cp0(argv[1]);
	return 0;
}
