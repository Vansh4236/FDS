#include <stdio.h>

#define MAX 100

void addPolynomials(int coeff1[], int exp1[], int size1, int coeff2[], int exp2[], int size2, int resultCoeff[], int resultExp[], int *resultSize) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (exp1[i] > exp2[j]) {
            resultCoeff[k] = coeff1[i];
            resultExp[k++] = exp1[i++];
        } else if (exp1[i] < exp2[j]) {
            resultCoeff[k] = coeff2[j];
            resultExp[k++] = exp2[j++];
        } else {
            resultCoeff[k] = coeff1[i] + coeff2[j];
            resultExp[k++] = exp1[i++];
            j++;
        }
    }

    while (i < size1) {
        resultCoeff[k] = coeff1[i];
        resultExp[k++] = exp1[i++];
    }

    while (j < size2) {
        resultCoeff[k] = coeff2[j];
        resultExp[k++] = exp2[j++];
    }

    *resultSize = k;
}

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
    int coeff1[MAX] = {5, 4, 3};
    int exp1[MAX] = {2, 1, 0};
    int size1 = 3;

    int coeff2[MAX] = {3, 4, 2};
    int exp2[MAX] = {3, 1, 0};
    int size2 = 3;

    int resultCoeff[MAX];
    int resultExp[MAX];
    int resultSize;

    addPolynomials(coeff1, exp1, size1, coeff2, exp2, size2, resultCoeff, resultExp, &resultSize);
    displayPolynomial(resultCoeff, resultExp, resultSize);

    return 0;
}
