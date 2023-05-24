/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <stdio.h>  //c
#include <stdlib.h> //c
using namespace std;

int main()
{   int *p;
    p=(int *)malloc(5*sizeof(int));
    //or
    //p=new int[5]; //c++
    p[1]=4;
    p[0]=9;
    
    int i=0;
    while(i<5){
        printf("p[%d]=%d\n",i,p[i]);
        i++;
    }
    free(p);
    // delete [] p; //c++
    return 0;
}
