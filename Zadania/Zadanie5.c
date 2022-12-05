#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    char a[4], b[3];
    scanf("%s", a);
    scanf("%s", b);
    printf("String: %s\nSize: %ld\n", a, sizeof(a));
    printf("%d\n", atoi(a[0]) * atoi(b[0]));
    for (int ib = 0; ib < sizeof(b); ib++) {
        int c[4] = {0, 0, 0, 0};
        for (int ia = 0; ia < sizeof(a); ia++) {
            for (int i = 0; i < sizeof(b); i++) {
                int liczba = b[ib] * a[ia];
            }
        }
    }
//    char* input1 = "1", input2;
//    int i = 0;
//    int aArray[1000], bArray[1000];
//
//    printf("Podaj pierwszą liczbę: ");
//    while (scanf("%c", input1) != "\n") {
////        aSize++;
//        aArray[i] = atoi(input1);
//        i++;
//    }

//    printf("Podaj drugą liczbę: ");
//    scanf("%c", &input2);

//    long unsigned int aSize, bSize;

//    aSize = strlen(&input1);


//    for (int i = 0; i < strlen(input1); i++) {
//
//    }


//    printf("size: %d", aSize);

    return 0;
}