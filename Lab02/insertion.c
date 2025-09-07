/* 
CS332 Lab 2 - Insertion Sort

Compile (if inside Lab02 folder): gcc insertion.c -o insertion
Run: ./insertion

Compile (if at repo root): gcc Lab02/insertion.c -o Lab02/insertion
Run: ./Lab02/insertion
*/

#include <stdio.h>
#include <stdlib.h>

// Function to perform insertion sort 
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n, i;

    // Ask user for number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of elements must be positive.\n");
        return 1; //exit program

    }

    int arr[n]; // Step 2: create array of size n

    // Step 3: Read array elements from user
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //Step 4: Call insertion sort
    insertionSort(arr, n);

    //Step 5: Print sorted array
    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);

    }
    printf("\n");

    return 0;


}