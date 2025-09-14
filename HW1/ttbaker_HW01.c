/* CS332 – HW1
   
Compile (if inside HW1 folder): gcc ttbaker_HW01.c
Run: ./hw1

Compile (if at repo root): gcc HW1/ttbaker_HW01.c -o HW1/hw1
Run: ./HW1/hw1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* 1) sumOfDigits: positive n -> sum of digits; else -1 */
int sumOfDigits(int n) {
    if (n <= 0) return -1;
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

/* 2) UABMaxMinDiff: max(arr) - min(arr) */
int UABMaxMinDiff(int arr[], int size) {
    if (size <= 0) return 0;
    int min = arr[0], max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    return max - min;
}

/* 3) replaceEvenWithZero: write into result[] */
void replaceEvenWithZero(int arr[], int size, int result[]) {
    for (int i = 0; i < size; i++) {
        result[i] = (arr[i] % 2 == 0) ? 0 : arr[i];
    }
}

/* 4) perfectSquare: returns 1 (True) if n is a perfect square, else 0 (False) */
int perfectSquare(int n) {
    if (n < 0) return 0;
    int i = 0;
    while ((long)i * (long)i <= n) {
        if (i * i == n) return 1;
        i++;
    }
    return 0;
}

/* 5) countVowels: count a/e/i/o/u */ 
int countVowels(const char *s) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = tolower((unsigned char)s[i]);
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            count++;
    }
    return count;
}

/* -------- main: calls each function with sample inputs -------- */
int main(void) {
    // sumOfDigits
    printf("sumOfDigits(123) = %d\n", sumOfDigits(123));  
    printf("sumOfDigits(405) = %d\n", sumOfDigits(405));   
    printf("sumOfDigits(0)   = %d\n", sumOfDigits(0));     
    printf("sumOfDigits(7)   = %d\n", sumOfDigits(7));     
    printf("sumOfDigits(-308)= %d\n", sumOfDigits(-308));  

    // UABMaxMinDiff
    int arr1[] = {3, 7, 2, 9};
    printf("UABMaxMinDiff([3,7,2,9]) = %d\n", UABMaxMinDiff(arr1, 4)); 

    int arr2[] = {5,5,5,5,5,5};
    printf("UABMaxMinDiff([5,5,5,5,5,5]) = %d\n", UABMaxMinDiff(arr2, 6)); 

    int arr3[] = {-2, 4, -1, 6, 5};
    printf("UABMaxMinDiff([-2,4,-1,6,5]) = %d\n", UABMaxMinDiff(arr3, 5)); 

    // replaceEvenWithZero
    int arr4[] = {1,2,3,4};
    int res4[4];
    replaceEvenWithZero(arr4, 4, res4);
    printf("replaceEvenWithZero([1,2,3,4]) = [%d,%d,%d,%d]\n", res4[0], res4[1], res4[2], res4[3]);

    int arr5[] = {2,4,6};
    int res5[3];
    replaceEvenWithZero(arr5, 3, res5);
    printf("replaceEvenWithZero([2,4,6]) = [%d,%d,%d]\n", res5[0], res5[1], res5[2]);

    int arr6[] = {1,3,5};
    int res6[3];
    replaceEvenWithZero(arr6, 3, res6);
    printf("replaceEvenWithZero([1,3,5]) = [%d,%d,%d]\n", res6[0], res6[1], res6[2]);

    // perfectSquare
    printf("perfectSquare(16) = %s\n", perfectSquare(16) ? "True" : "False");
    printf("perfectSquare(15) = %s\n", perfectSquare(15) ? "True" : "False");
    printf("perfectSquare(25) = %s\n", perfectSquare(25) ? "True" : "False");
    printf("perfectSquare(36) = %s\n", perfectSquare(36) ? "True" : "False");

    // countVowels
    printf("countVowels(\"Hello World\") = %d\n", countVowels("Hello World")); 
    printf("countVowels(\"UAB CS\") = %d\n", countVowels("UAB CS"));           
    printf("countVowels(\"Python\") = %d\n", countVowels("Python"));           
    printf("countVowels(\"aeiou\") = %d\n", countVowels("aeiou"));             

    return 0;
}
