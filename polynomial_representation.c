#include <stdio.h>

#define MAX 100

void displayPolynomial(int coeff[], int exp[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%dx^%d", coeff[i], exp[i]);
        if (i < size - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    int coeff[MAX] = {5, 4, 3};
    int exp[MAX] = {2, 1, 0};
    int size = 3;

    displayPolynomial(coeff, exp, size);

    return 0;
}
