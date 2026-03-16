#include <stdio.h>   // Entrada y salida estándar
#include <stdlib.h>  // exit()

/*
    Programa: wcat
    Función:
    Lee uno o varios archivos enviados por línea de comandos
    e imprime su contenido en pantalla.
*/

int main(int argc, char *argv[]) {

    /*
        argc = cantidad de argumentos
        argv = arreglo de argumentos

        Ejemplo:
        ./wcat archivo.txt

        argc = 2
        argv[0] = ./wcat
        argv[1] = archivo.txt
    */

    // Si no se envía ningún archivo
    if (argc < 2) {
        // Debe terminar normalmente
        return 0;
    }

    // Recorre todos los archivos enviados
    for (int i = 1; i < argc; i++) {

        // Abrir archivo en modo lectura
        FILE *fp = fopen(argv[i], "r");

        // Verificar si ocurrió error al abrir
        if (fp == NULL) {
            printf("wcat: cannot open file\n");
            exit(1); // salir con error
        }

        /*
            Buffer donde se guardará
            cada línea leída del archivo
        */
        char buffer[1024];

        /*
            fgets():
            Lee una línea del archivo
            hasta encontrar salto de línea
            o fin del archivo
        */
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {

            /*
                Imprime exactamente
                el contenido leído
                (NO agregar \n)
            */
            printf("%s", buffer);
        }

        // Cerrar archivo después de usarlo
        fclose(fp);
    }

    // Finalización correcta
    return 0;
}