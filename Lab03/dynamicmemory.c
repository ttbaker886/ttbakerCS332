/* 
CS332 Lab 3 - dynamic memory allocation and strings

Compile (if inside Lab03 folder): gcc dynamicmemory.c -o dynamicmemory
Run: ./dynamicmemory

Compile (if at repo root): gcc Lab03/dynamicmemory.c -o Lab03/dynamicmemory
Run: ./Lab03/dynamicmemory
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform insertion sort on strings
void insertionSort(char **arr, int n) {   
    int i, j;                             
    char *key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(void) {
    int n;

    // Ask user for number of strings
    printf("Enter the number of strings: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    if (n <= 0) {
        printf("Number of strings must be positive.\n");
        return 1; // exit program
    }

    char **arr = (char**) malloc(n * sizeof(char*));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    char tmp[1024]; // temporary buffer
    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%1023s", tmp);  // reads one word (no spaces)
        arr[i] = (char*) malloc((strlen(tmp) + 1) * sizeof(char));
        if (!arr[i]) {
            fprintf(stderr, "Allocation failed.\n");
            // free what was allocated so far
            for (int k = 0; k < i; k++) free(arr[k]);
            free(arr);
            return 1;
        }
        strcpy(arr[i], tmp);
    }

    // Call insertion sort
    insertionSort(arr, n);

    // Print sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {  
        printf("%s ", arr[i]);
        free(arr[i]);              
    }
    printf("\n");

    free(arr);
    return 0;
}
