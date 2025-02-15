#include<stdio.h>

/* This program finds the element that appears only once in an array where every other 
 * element appears twice.
 * It uses the XOR bitwise operation to achieve this.
 * The XOR operation has the following properties:
 * 1. x ^ x = 0
 * 2. x ^ 0 = x
 *
 * Given these properties, XORing all elements of the array will cancel out all elements
 * that appear twice, leaving the element that appears only once.
 */

int main()
{
    int arr[] = {1,2,1,2,3,4,5,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result=0;

    for(int i=0;i<n;i++)
    {
        result = result^arr[i];
    }
    printf("Element appearing once is %d",result);
    return 0;
}