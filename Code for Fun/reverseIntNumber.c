#include <stdio.h>

int rev_i(int i)
 {
    int rev_num, digit;
    rev_num = digit = 0; 
    while (i > 0) { 
        digit = i % 10;
        /* Multiply by 10 to shift left and add last digit */
        rev_num = rev_num * 10 + digit; rev_num * 10 + i % 10;  
        i = i / 10; 
    } 
    return rev_num; 
 }

int main()
{
    int p=5101;
    int rev= rev_i(p);
    printf("%d",rev);
    return 0;
}