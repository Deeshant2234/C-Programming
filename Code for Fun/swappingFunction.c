#include <stdio.h>

/*

Pointer (y): A pointer is a variable that stores the address of 
another variable.
For example, if y is a pointer, then y holds the address of some 
integer variable.

Dereference (*y): Dereferencing a pointer (*y) means accessing or 
modifying the value stored at the address that the pointer points to.

*/


void swap(int* x, int* y)
{
    int temp;
    temp = *y;      // Dereference y to get the value stored at the address y points to
    *y = *x;        // Dereference y to assign it the value stored at the address x points to
    *x = temp;      // Dereference x to assign it the value in temp
}
 

int main()
{
    int x=10;
    int y=20;
    swap(&x,&y);
    printf("x=%d, y=%d",x,y);
    return 0;
}