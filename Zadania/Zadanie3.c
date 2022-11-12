#include <stdio.h>

int main()
{
    int n;
    printf("~~~ Sito Erastotenesa ~~~\nPodaj n: ");
    scanf("%d", &n);

    while (n <= 1) {
        printf("Wartość n musi być większa od 1! Podaj n ponownie: ");
        scanf("%d", &n);
    }

    int array[n - 1], conditions[n - 1];

    for (int i = 1; i < n; i++) {
        array[i] = i + 1;
        conditions[i] = 1;
    }

    for (int a = 1; a < n; a++) {
        for (int b = 1; b * a < n; b++) {
            if (array[b * a] % array[a] == 0 && array[b * a] > array[a]) {
                conditions[b * a] = 0;
            }
        }
    }

    printf("Liczby pierwsze to: ");

    for (int k = 0; k < n; k++) {
        if (conditions[k] == 1) { printf("%d, ", array[k]); }
    }

    printf("\n");

    return 0;
}