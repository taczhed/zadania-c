#include <stdio.h>

int main ()
{
    int m, n, r;
    printf("~~~ Algorytm Euklidesa NWD(m, n) ~~~\nPodaj m: ");
    scanf("%d", &m);
    printf("Podaj n: ");
    scanf("%d", &n);

    while (m < n || n < 0 || m <= 0) {
        printf("Błędne dane! \nPodaj m: ");
        scanf("%d", &m);
        printf("Podaj n: ");
        scanf("%d", &n);
    }

    if (n == 0) { printf("%d", m); }

    while (n != 0) {
        r = m % n;
        m = n;
        n = r;
    }

    printf("NWD: %d \n", m);

    return 0;
}