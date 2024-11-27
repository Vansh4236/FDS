#include <stdio.h>

#define MAX 100

void addSparseMatrices(int a[MAX][3], int sizeA, int b[MAX][3], int sizeB, int result[MAX][3], int *sizeResult) {
    int i = 0, j = 0, k = 0;

    while (i < sizeA && j < sizeB) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k++][2] = a[i++][2];
        } else if (a[i][0] > b[j][0] || (a[i][0] == b[j][0] && a[i][1] > b[j][1])) {
            result[k][0] = b[j][0];
            result[k][1] = b[j][1];
            result[k++][2] = b[j++][2];
        } else {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k++][2] = a[i++][2] + b[j++][2];
        }
    }

    while (i < sizeA) {
        result[k][0] = a[i][0];
        result[k][1] = a[i][1];
        result[k++][2] = a[i++][2];
    }

    while (j < sizeB) {
        result[k][0] = b[j][0];
        result[k][1] = b[j][1];
        result[k++][2] = b[j++][2];
    }

    *sizeResult = k;
}

void displaySparseMatrix(int sparse[MAX][3], int size) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

int main() {
    int a[MAX][3] = {{0, 2, 3}, {0, 4, 4}, {1, 2, 5}, {1, 3, 7}, {3, 1, 2}, {3, 2, 6}};
    int sizeA = 6;

    int b[MAX][3] = {{0, 3, 3}, {1, 2, 2}, {2, 4, 5}, {3, 1, 4}};
    int sizeB = 4;

    int result[MAX][3];
    int sizeResult;

    addSparseMatrices(a, sizeA, b, sizeB, result, &sizeResult);
    displaySparseMatrix(result, sizeResult);

    return 0;
}
