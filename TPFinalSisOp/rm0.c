#define _POSIX_C_SOURCE 200809L

#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>


void rm0(const char *file) {
	
	struct stat statbuf;
	
	stat(file, &statbuf);
	
	if (S_ISDIR(statbuf.st_mode))
		printf("rmo0: Error. Se está intentando eliminar un  directorio.\n");
	
	if (S_ISREG(statbuf.st_mode)) {
		
		int res;
		
		if ((res = unlink(file)))
			printf("rm0: unlink error, %d.\n", res);
		
	}
}

int main(int argc, char *argv[]) {
	
	if (argc != 2)
		printf("Error: ingresar el nombre de un único archivo.\n");
	
    rm0(argv[1]);
    return 0;
    
}
