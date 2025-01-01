#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    // If x is negative or ends in 0 (but is not 0), it's not a palindrome
    if (x < 0 || (x % 10 == 0 && x != 0)) 
        return false;

    int sum = 0;
    while (x > sum) {
        sum = sum * 10 + x % 10; // Add the last digit of x to sum
        x /= 10; // Remove the last digit from x
    }

    // If x is equal to sum, the number is a palindrome
    // or if it's an odd length, sum / 10 will disregard the middle digit
    return (x == sum || x == sum / 10);
}

int main()
{   
    printf("%d",isPalindrome(1221));
    return 0;
}