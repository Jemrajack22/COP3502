#include <stdio.h>

// Function to perform Bubble Sort and count swaps
int bubbleSort(int arr[], int n, int swaps[]) {
    int total_swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                // Increment swap count for swapped elements
                swaps[arr[j]]++;
                swaps[arr[j + 1]]++;
                total_swaps += 2;
            }
        }
    }
    return total_swaps / 2;
}

// Function to perform Selection Sort and count swaps
int selectionSort(int arr[], int n, int swaps[]) {
    int total_swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap elements
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            // Increment swap count for the swapped element
            swaps[arr[min_idx]]++;
            total_swaps++;
        }
    }
    return total_swaps;
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int swaps1[100] = {0}; // Assuming the values in arrays are less than 100
    int swaps2[100] = {0}; // Assuming the values in arrays are less than 100

    printf("array1 bubble sort:\n");
    int total_swaps_bubble1 = bubbleSort(array1, size1, swaps1);
    for (int i = 0; i < size1; i++) {
        printf("%d: %d\n", array1[i], swaps1[array1[i]]);
    }
    printf("%d\n", total_swaps_bubble1);

    printf("\narray2 bubble sort:\n");
    int total_swaps_bubble2 = bubbleSort(array2, size2, swaps2);
    for (int i = 0; i < size2; i++) {
        printf("%d: %d\n", array2[i], swaps2[array2[i]]);
    }
    printf("%d\n", total_swaps_bubble2);

    printf("\narray1 selection sort:\n");
    int total_swaps_selection1 = selectionSort(array1, size1, swaps1);
    for (int i = 0; i < size1; i++) {
        printf("%d: %d\n", array1[i], swaps1[array1[i]]);
    }
    printf("%d\n", total_swaps_selection1);

    printf("\narray2 selection sort:\n");
    int total_swaps_selection2 = selectionSort(array2, size2, swaps2);
    for (int i = 0; i < size2; i++) {
        printf("%d: %d\n", array2[i], swaps2[array2[i]]);
    }
    printf("%d\n", total_swaps_selection2);

    return 0;
}
