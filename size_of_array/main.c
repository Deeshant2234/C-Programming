/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main() {
   int arr[] = {1, 2, 3, 4, 5};
   size_t arr_size = sizeof(arr) / sizeof(arr[0]);
   printf("The size of the array is %zu bytes\n", arr_size); 
   //%zu is a format specifier used in C
   //for printing the value of an object of type size_t.
   return 0;
}
