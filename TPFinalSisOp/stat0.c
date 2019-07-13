#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

// Pre-condición el archivo existe y es directorio ó archivo regular
void stat0(const char *file) {
	struct stat statbuf;
	stat(file, &statbuf);

	char *tipoArchivo;
	// Chequeo si es un directorio
	if (S_ISDIR(statbuf.st_mode)) {
		tipoArchivo = "Directory";
	}//Por pre-condición, si no es directorio es archivo regular
	else{
		tipoArchivo = "Archivo regular";
	}

	printf("Size: %ld\n", statbuf.st_size);
	printf("File %s\n", file);
	printf("Type: %s\n", tipoArchivo);
}

int main(int argc, char *argv[]){
	if(argc!=2 ){
		printf("stat0: Error, ingrese un único archivo.\n");
		return 1;
	}
	stat0(argv[1]);
	return 0;
}
