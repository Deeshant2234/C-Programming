/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main() {
   printf("The size of a pointer is %zu bytes\n", sizeof(void *));
   return 0;
}

//Note that the void * type is used here to represent a generic pointer, 
//as the size of a pointer may vary depending on the specific data type being pointed to.