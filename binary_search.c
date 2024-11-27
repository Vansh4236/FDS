#include <stdio.h>

// Binary Search Function (Assumes array is sorted)
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Calculate mid index

        if (arr[mid] == target) {
            return mid;  // Return index if found
        }
        if (arr[mid] < target) {
            low = mid + 1;  // Ignore left half
        } else {
            high = mid - 1;  // Ignore right half
        }
    }
    return -1;  // Return -1 if the target is not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target, result;

    printf("Enter the number to search: ");
    scanf("%d", &target);

    result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
