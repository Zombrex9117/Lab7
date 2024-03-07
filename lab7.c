// DENNIS SHEA LAB7 SECTION 28, COP3502C, TOROSDOGLI
#include <stdio.h>

void bubbleSort(int arr[], int size, int swaps[]) {
    int i, j, temp, totalSwaps = 0;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // Increment swaps for the swapped elements
                swaps[arr[j]]++;
                swaps[arr[j + 1]]++;

                // Increment total swaps
                totalSwaps++;
            }
        }
    }

    // Print swaps for each index
    for (i = 0; i < size; i++) {
        printf("%d: %d\n", arr[i], swaps[arr[i]]);
    }

    printf("Total number of swaps: %d\n", totalSwaps);
}

void selectionSort(int arr[], int size, int swaps[]) {
    int i, j, minIndex, temp, totalSwaps = 0;

    for (i = 0; i < size - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap elements
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        if (arr[i] != arr[minIndex]){
            // increment swaps for the current index and the min index
            swaps[arr[i]]++;
            swaps[arr[minIndex]]++;
            // Increment total swaps
            totalSwaps++;
        }
    }

    // Print swaps for each element 
    for (i = 0; i < size; i++) {
        printf("%d: %d\n", arr[i], swaps[arr[i]]);
    }

    printf("Total number of swaps: %d\n", totalSwaps);
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int size = 9;

    int swaps1[97] = {0}; 
    int swaps2[97] = {0};
    int swaps3[97] = {0}; 
    int swaps4[97] = {0};

    int tempArray1[9] = {0};
    for (int i = 0; i < size; i++) {
        tempArray1[i] = array1[i];
    }

    printf("array1 bubble sort:\n");
    bubbleSort(array1, size, swaps1);

    // reset the values of array1 for selection sort
    for (int i = 0; i < size; i++) {
        array1[i] = tempArray1[i];
    }

    printf("\narray2 bubble sort:\n");
    int tempArray2[9] = {0};

    for (int i = 0; i < size; i++) {
        tempArray2[i] = array2[i];
    }

    bubbleSort(array2, size, swaps2);

    // reset the values of array2 for selection sort
    for (int i = 0; i < size; i++) {
        array2[i] = tempArray2[i];
    }

    printf("\narray1 selection sort:\n");
    selectionSort(array1, size, swaps3);

    printf("\narray2 selection sort:\n");
    selectionSort(array2, size, swaps4);

    return 0;
}