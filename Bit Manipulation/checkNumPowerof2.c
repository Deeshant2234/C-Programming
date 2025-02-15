#include <stdio.h>

int main()
{
    int num = 4 ; 

    if((num&(num-1))==0)
        printf("Number %d is a power of 2", num);
    else
        printf("Number %d is not a power of 2", num);   

    return 0;
}