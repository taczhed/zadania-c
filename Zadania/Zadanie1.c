#include <stdio.h>
#include <math.h>

int main()
{
    int i = 0, size = 1000;
    float sum = 0, avg, deviation = 0, array[size];

    while (i < size) {
        if (scanf("%f", &array[i]) == EOF) { size = i; }
        else { i++; }
    }


    for (int index = 0; index < size; index++) { sum += array[index]; }

    avg = sum / size;

    for (int index = 0; index < size; index++) {
        deviation += pow(array[index] - avg, 2);
    }

    deviation = sqrt(deviation / size);

    printf("Średnia arytmetyczna: %f\n", avg);
    printf("Odchylenie standardowe: %f\n", deviation);

    return 0;
}
