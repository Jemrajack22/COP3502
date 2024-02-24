#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc

int binarySearch(int numbers[], int low, int high, int value) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (numbers[mid] == value)
        return mid;
    else if (numbers[mid] < value)
        return binarySearch(numbers, mid + 1, high, value);
    else
        return binarySearch(numbers, low, mid - 1, value);
}

int main(void) {
    int i, numInputs;
    int value, index;
    int* numArray = NULL;
    int countOfNums;
    FILE* inFile = fopen("input.txt", "r");

    fscanf(inFile, " %d\n", &numInputs);
    
    while (numInputs-- > 0) {
        fscanf(inFile, " %d\n", &countOfNums);
        numArray = (int *) malloc(countOfNums * sizeof(int));
        for (i = 0; i < countOfNums; i++) {
            fscanf(inFile," %d", &numArray[i]);
        }

        value = numArray[countOfNums / 2]; // Choose a value to search

        index = binarySearch(numArray, 0, countOfNums - 1, value);
        if (index >= 0) {
            printf("Item %d exists in the number array at index %d!\n", value, index);
        } else {
            printf("Item %d does not exist in the number array!\n", value);
        }

        free(numArray);
    }

    fclose(inFile);
    return 0;
}
