#include <stdio.h>

int rev_i(int i)
 {
    int rev_num = 0; 
    while (i > 0) { 
        rev_num = rev_num * 10 + i % 10; 
        i = i / 10; 
    } 
    return rev_num; 
 }

int main()
{
    int p=510;
    int rev= rev_i(p);
    printf("%d",rev);
    return 0;
}