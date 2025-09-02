/* Lab 1 : Prime Number Checker 
    To Compile : gcc -o prime prime.c
    To run: ./prime 
*/

#include <stdio.h>

int main() {
    int given_number, i, is_prime = 1;

    // Ask the user for a number
    printf("Enter a number: ");
    scanf("%d", &given_number);

    // Handle numbers less than 2
    if (given_number <= 1) {
        is_prime = 0;
    } else {
        // Check if the number has any divisors
        for (i = 2; i * i <= given_number; i++) {
            if (given_number % i == 0) {
                is_prime = 0;
                break;
            }
        }
    }

    // Print result
    if (is_prime)
        printf("The number is prime\n");
    else
        printf("The number is not prime\n");

    return 0;
}
