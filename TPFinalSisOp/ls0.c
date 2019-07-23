#define _POSIX_C_SOURCE 200809L

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>

/*Se pide solamente devolver los nombres de los archivos del directorio actual*/
void ls0(){
	char nombreDirectorio[1024];
	getcwd(nombreDirectorio, 1024);

	DIR *directorioAbierto = opendir((const char*)nombreDirectorio);

	struct dirent *directorioLeido = readdir(directorioAbierto);

	while(directorioLeido != NULL){
		if(directorioLeido->d_name[0] != '.'){
			printf("%s\n",directorioLeido->d_name);
		}
		directorioLeido = readdir(directorioAbierto);
	}
	closedir(directorioAbierto);
}

int main(){
	ls0();
	return 0;
}
