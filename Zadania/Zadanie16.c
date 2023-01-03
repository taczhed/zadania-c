#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX 100 // maksymalna liczba wierszy

int compareLines(const void *a, const void *b) {
    char *stringA = *(char**)a;
    char *stringB = *(char**)b;
    return strcmp(stringA, stringB);
}

int main() {
    char *Tekst[N_MAX];
    int n = 0; // obecna liczba wierszy
    char line[1024]; // obecnie wczytywany wiersz

    while (fgets(line, sizeof line, stdin)) {
        int lineLength = strlen(line);
        if (lineLength == 1) continue;
        Tekst[n] = malloc(lineLength); // przydzielenie pamięci
        strcpy(Tekst[n], line);
        n++;
    }

    qsort(Tekst, n, sizeof(char *), compareLines);

    printf("---------- Wynik: ---------\n");
    for (int i = 0; i < n; i++) { printf("%s", Tekst[i]); }
    return 0;
}