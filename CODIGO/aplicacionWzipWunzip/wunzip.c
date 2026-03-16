#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "rb");
        if (!f) {
            printf("wunzip: cannot open file\n");
            exit(1);
        }

        int count;
        char c;

        while (fread(&count, sizeof(int), 1, f) == 1) {
            fread(&c, sizeof(char), 1, f);
            for (int j = 0; j < count; j++) {
                putchar(c);
            }
        }

        fclose(f);
    }

    return 0;
}