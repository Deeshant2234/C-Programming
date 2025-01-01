#include <stdio.h>
#include <math.h>

// METHOD 1: USING BIT OPERATION
int main()
{   
    int n = 6;
    int countSetBits=0;
    do{
        // printf("%d",n&1);
        if(n&1)
            countSetBits++;
        n = n>>1;
    }
    while(n>0);
    printf("No. of Set Bits are: %d",countSetBits);
    return 0;
}

// METHOD 2: USING BRUTE FORCE METHOD
// int main() {
//     int n = 6;
//     int countSetBits = 0;
//     int i = 0;
    
//     while (n > 0) {   
//         int bit = n % 2;        // Get rightmost bit
//         if (bit)                // Check if it is set
//             countSetBits++;
//         n = n / 2;              // Right shift equivalent
//         i++;
//     }
    
//     printf("Total set bits: %d\n", countSetBits);
//     return 0;
// }
