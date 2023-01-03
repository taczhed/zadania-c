#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX 100

int compareLines(const void *a, const void *b) {
    char *stringA = *(char**)a;
    char *stringB = *(char**)b;
    return strcmp(&stringA[0], &stringB[0]);
}

int main(int argc, char *argv[]) {
    char *Ciagi[N_MAX];
    int n = 0, desc = 0;
    char line[1024];

    if (argc > 1 && strcmp(argv[1], "desc") == 0) { desc = 1; }

    while (fgets(line, sizeof line, stdin)) {
        int lineLength = strlen(line);
        if (lineLength == 1) continue;
        Ciagi[n] = malloc(lineLength); // przydzielenie pamięci
        strcpy(Ciagi[n], line);
        n++;
    }

    qsort(Ciagi, n, sizeof(char *), compareLines);

    printf("---------- Wynik: ---------\n");

    if (desc) {
        for (int i = n - 1; i >= 0; i--) { printf("%s", Ciagi[i]); }
    } else {
        for (int i = 0; i < n; i++) { printf("%s", Ciagi[i]); }
    }

    return 0;
}