#include <stdio.h>
#include <string.h>
#define MAX_LEN 1000

typedef struct { int digits[MAX_LEN]; int length; } number;

number readNumber() {
    printf("Podaj liczbę: ");
    char input[MAX_LEN];
    scanf("%s", input);
    int len = strlen(input);
    number result;
    result.length = len;
    for (int i = 0; i < len; i++) { result.digits[i] = input[len - i - 1] - '0'; }
    return result;
}

number multiply(number x, number y) {
    number result;
    result.length = x.length + y.length;
    for (int i = 0; i < result.length; i++) { result.digits[i] = 0; } // Wypełnianie zerami

    // Mnożenie na indeksach
    for (int i = 0; i < x.length; i++) {
        for (int j = 0; j < y.length; j++) {
            result.digits[i + j] += x.digits[i] * y.digits[j];
        }
    }

    // Usuwanie przepełnień
    for (int i = 0; i < result.length - 1; i++) {
        result.digits[i + 1] += result.digits[i] / 10;
        result.digits[i] %= 10;
    }

    // Usuwanie zbędnych zer z przodu
    while (result.length > 1 && result.digits[result.length - 1] == 0) { result.length--; }
    return result;
}

int main() {
    number x = readNumber();
    number y = readNumber();
    number result = multiply(x, y);

    printf("Iloczyn: ");
    for (int i = result.length - 1; i >= 0; i--) { printf("%d", result.digits[i]);}
    printf("\n");

    return 0;
}