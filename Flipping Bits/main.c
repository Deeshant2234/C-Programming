#include <stdio.h>
#include <math.h>
unsigned int flippingBits(unsigned long n) {
    if (n < (unsigned long)pow(2, 32) && n >= 0) {
        unsigned long x = ~n;
        return x;
    }
    return 0;
}


int main()
{
    long x=flippingBits(14);
    printf("%ld",x);

    return 0;
}

