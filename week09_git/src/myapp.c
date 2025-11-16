#include <stdio.h>
#include "myops.h"

void calculate(int a, char op, int b);

int main(void) {
    int a, b;
    char op;

    printf("~~~ Welcome to my calculator  ~~~\n");
    printf("Enter expression (ex: 1 + 2): ");
    scanf("%d %c %d", &a, &op, &b);

    calculate(a, op, b);

    return 0;
}

void calculate(int a, char op, int b) {
    int result;

    if (op == '+') {
        result = myadd(a, b);
    } else if (op == '-') {
        result = mysub(a, b);
    } else if (op == '*') {
        result = mymul(a, b);
    } else if (op == '/') {
        result = mydiv(a, b);
    } else {
        printf("Unknown operator: %c\n", op);
        return;
    }

    printf("Result: %d\n", result);
}
