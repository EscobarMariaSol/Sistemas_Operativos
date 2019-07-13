#define _POSIX_C_SOURCE 200809L

#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>


void rm0(const char *file) {
	
	struct stat statbuf;
	
	stat(file, &statbuf);
	
	// Por pre-condición el archivo existe y es regular,
	// entonces sólo chequeo que no sea un directorio.
	if (S_ISDIR(statbuf.st_mode))
		printf("rmo0: Error, se está intentando eliminar un  directorio.\n");
		return;
		
	int res;
		
	if ((res = unlink(file)))
		printf("rm0: unlink error, %d.\n", res);

}

int main(int argc, char *argv[]) {
	
	if (argc != 2) {
		printf("rm0: Error, ingresar el nombre de un único archivo.\n");
		return 1;
	}
	
    rm0(argv[1]);
    return 0;
    
}
