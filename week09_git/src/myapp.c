#include <stdio.h>

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
    printf("Calculating.....\n");
}
