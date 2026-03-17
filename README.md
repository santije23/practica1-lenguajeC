# practica1-lenguajeC

## (a) Nombres completos de los integrantes, correos y n´umeros de documento.


### Santiago Jiménez Escobar - santiago.jimeneze@udea.edu.co - C.C 1036959331



## (b) Documentación de todas las funciones desarrolladas en el código.

# AplicacionWzipWunzip

- La funcion  **`main(int argc, char *argv[])`** se utiliza en ambas aplicaciones wzip y Wunzip con el fin de inicializar la aplicación y obtener el número de argumentos y el valor de los argumentos ingresados por consola cuando se ejecuta la aplicación.

- Para verificar si se ingresó un número de argumentos acorde a lo que se pide en la práctica, se utiliza el condicional **`if (argc < 2)`** en caso de que el contador de argumentos sea menor a 2, se imprime por pantalla la forma correcta en la cual se deben ingresar estos argumentos.

- El ciclo principal **`for (int i = 1; i < argc; i++)`** permite iterar para cada uno de los argumentos ingresados; en este caso, al utilizar la funcion **`fopen(argv[i], "r")`** estamos abriendo cada uno de los archivos en modo lectura que se pasaron en la línea de comandos. En caso de no poderse abrir el archivo **`if (!f)`** muestra el mensaje de error en pantalla y pasa al siguiente archivo.

- Posteriormente, se inicializan las variables **Prev**, **c** y **count** las cuales guardarán el carácter anterior, el siguiente y el número de veces que se repite, esto con ayuda de la función **`fgetc(f)`** que nos permite obtener el primer carácter del archivo abierto.

- Antes de realizar el primer conteo, se verifica con el condicional **`if (prev == EOF)`** si no hay ningún carácter en el archivo; en este caso, se cierra dicho archivo con la función **`fclose(f);`** y se continúa con el siguiente.

- Lo siguiente por hacer es leer cada uno de los caracteres que hay en el archivo; para ello utilizamos el ciclo **`while ((c = fgetc(f)) != EOF)`**. Mientras cargamos cada carácter, verificamos si el carácter leído es igual al anterior mediante el condicional if **`if (c == prev)`** y si es afirmativo, incrementamos el contador.

- En caso contrario, se escribe en la salida el número de repeticiones y el carácter en cuestión mediante la función **`fwrite(&count, sizeof(int), 1, stdout)`** y **`fwrite(&prev, sizeof(char), 1, stdout)`**. Por último, se cierra el archivo actual mediante la función **`fclose(f)`**.

## (c) Problemas presentados durante el desarrollo de la pr´actica y sus soluciones.
## (d) Pruebas realizadas a los programas que verificaron su funcionalidad.
## (e) Un enlace a un video de 10 minutos donde se sustente el desarrollo.
## (f) Manifiesto de transparencia: En que puntos se apoyaron de la IA generativa.