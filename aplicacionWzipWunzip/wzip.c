#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "wzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");
        if (!f) {
            printf("wzip: cannot open file\n");
            exit(1);
        }

        int c, prev;
        int count;

        prev = fgetc(f);
        if (prev == EOF) {
            fclose(f);
            continue;
        }
        count = 1;

        while ((c = fgetc(f)) != EOF) {
            if (c == prev) {
                count++;
            } else {
                fwrite(&count, sizeof(int), 1, stdout);
                fwrite(&prev, sizeof(char), 1, stdout);
                prev = c;
                count = 1;
            }
        }

        fwrite(&count, sizeof(int), 1, stdout);
        fwrite(&prev, sizeof(char), 1, stdout);

        fclose(f);
    }

    return 0;
}