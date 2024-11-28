#include <stdio.h>

// Function to find the minimum sum subarray
int minSumSubArray(int arr[], int n) {
    int min_so_far = arr[0]; // Initialize the minimum sum to the first element of the array
    int min_ending_here = arr[0];  // Sum of the subarray ending at the current position

    for (int i = 1; i < n; i++) {
        if (min_ending_here > 0) {
            min_ending_here = arr[i]; // Reset to the current element if the sum is positive
        } else {
            min_ending_here += arr[i]; // Otherwise, add the current element to the sum
        }

        if (min_so_far > min_ending_here) {
            min_so_far = min_ending_here;
        }
    }

    return min_so_far;
}

int main() {
    int arr[] = {3, -4, 2, -3, -1, 7, -5}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]);

    int min_sum = minSumSubArray(arr, n);
    printf("Minimum sum subarray is %d\n", min_sum);

    return 0;
}
