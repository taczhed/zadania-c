#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_STACK_SIZE 100

double stack[MAX_STACK_SIZE];
int stack_size = 0;

double log_a_to_base_b(double a, double b) {
    return log2(a) / log2(b);
}

void push(double value) {
    if (stack_size >= MAX_STACK_SIZE) printf("Błąd: Przepełnienie stosu!\n");
    else {
        stack[stack_size] = value;
        stack_size++;
    }
}

double pop() {
    if (stack_size <= 0) printf("Błąd: Za mało liczb na stosie!\n");
    else {
        stack_size--;
        return stack[stack_size];
    }
}

double perform_operation(char operation) {
    double operand1 = pop();
    double operand2 = pop();

    switch (operation) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand2 - operand1;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand2 / operand1;
        case '^':
            return pow(operand2, operand1);
        case 'l':
            return log_a_to_base_b(operand1, operand2);
        default:
            printf("Błąd: Nieznana operacja!\n");
    }
}

int main() {
    printf("~~~ Kalkulator notacji odwrotnej polskiej ~~~\n");

    char c[100] = "", *endptr;

    while (c[0] != 'q') {
        printf("Wpisz: ");
        scanf("%s", c);

        if  (c[0] == 'q') return 0;

        if (isdigit(c[0]) || (c[0] == '-' && isdigit(c[1]))) {
            push(strtod(c, &endptr));
        } else if (c[0] == '+' || c[0] == '-' || c[0] == '*' || c[0] == '/' || c[0] == '^' || c[0] == 'l') {
            if (stack_size < 2) printf("Błąd: Za mało liczb na stosie!\n");
            else push(perform_operation(c[0]));
        } else if  (c[0] == '=') {
            printf("Wynik: %f\n", pop());
        } else {
            printf("Błąd: Niedozwolony znak: %s\n", c);
        }

    }
}