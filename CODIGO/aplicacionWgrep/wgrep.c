#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc==1){
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
        
    } else if(argc==2){
        char *terminoBuscado = argv[1];
        char *linea = NULL;
        size_t tamaño = 0;

        while(getline(&linea, &tamaño, stdin) != -1){

            if(strstr(linea, terminoBuscado)){
                printf("%s", linea);
            }

        }

        free(linea);
        return 0;
    }

     
     char *terminoBuscado = argv[1];

     for(int i=2; i<argc; i++){
        FILE *f = fopen(argv[i], "r");

        if(f==NULL){
            printf("wgrep: cannot open file\n");
            exit(1);
        }

        char *linea = NULL;
        size_t tamaño = 0;
        while (getline(&linea, &tamaño, f) != -1){
            if(strstr(linea, terminoBuscado)){
                printf("%s", linea);
            }
        }
        free(linea);
        fclose(f);
     }

    return 0;
}