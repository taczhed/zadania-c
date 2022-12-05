#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    struct RZYM { int arabian; char *roman; } rz[]={{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"}, {40,"XL"},{50,"L"},{90,"XC"},{100,"C"}, {400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};

    char a[4000];
    printf("Kalkulator liczb Rzymskich <=> Arabskich\nPodaj liczbę: ");
    scanf("%s", a);

    if (isdigit(a[0])) {
        strcpy(a, a);
        int arabian = atoi(a);
        for (int i = 12; i >= 0; i--) {
            while (arabian >= rz[i].arabian) {
                printf("%s", rz[i].roman);
                arabian -= rz[i].arabian;
            }
        }
    } else {
        int sum = 0;
        for (int i = 0; i < strlen(a); i++) {
            for (int k = 0; k < 13; k++) {
                if (a[i] == rz[k].roman[0] && a[i+1] == rz[k].roman[1]) {
                    sum += rz[k].arabian;
                    i+=2;
                    break;
                }
            }
            for (int k = 0; k < 13; k++) {
                if (a[i] == rz[k].roman[0] && a[i+1] != rz[k].roman[1]) {
                    sum += rz[k].arabian;
                    break;
                }
            }
        }
        printf("%d", sum);
    }

    printf("\n");

    return 0;
}