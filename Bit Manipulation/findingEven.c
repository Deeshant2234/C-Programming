#include <stdio.h>

// Function to check if a number is even using bitwise AND operator
int isEven(int num) {
    // If the least significant bit is 0, the number is even
    return (num & 1) == 0;
}

int main() {
    int num = 17; // Fixed number

    // Check if the number is even
    if (isEven(num)) {
        printf("%d is an even number.\n", num);
    } else {
        printf("%d is an odd number.\n", num);
    }

    return 0;
}
