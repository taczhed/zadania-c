#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, delta, x1, x2;

    printf("~~~ Program znajdujący pierwiastki równania kwadratowego ~~~\n");
    printf("Podaj a: ");
    scanf("%f", &a);

    while (a == 0) {
        printf("Parametr a nie może wynosić 0!\nPodaj a: ");
        scanf("%f", &a);
    }

    printf("Podaj b: ");
    scanf("%f", &b);

    printf("Podaj c: ");
    scanf("%f", &c);

    delta = pow(b, 2) - (4 * a * c);

    if (delta > 0) {
        x1 = ((-1 * b) + sqrt(delta)) / (2 * a);
        x2 = ((-1 * b) - sqrt(delta)) / (2 * a);
        printf("x1 = %f\nx2 = %f\n", x1, x2);
    }

    else if (delta == 0) {
        x1 = (-1 * b) / (2 * a);
        printf("x = %f\n", x1);
    }

    else {
        printf("Brak pierwiastków!\n");
    }

    return 0;
}