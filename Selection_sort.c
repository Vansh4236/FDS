#include <stdio.h>

// Selection Sort Function
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, size);
    printf("Sorted array: \n");
    printArray(arr, size);

    return 0;
}
