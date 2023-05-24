/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{   int a=10;
    int *p;  //Declaring address variable or pointer P
    p=&a;   //Initialization Pointer by address of a
    
    printf("Address of a (C) %d\n",(&a)); // Address of a
    printf("Value of p (C) %d\n",p); // P is holding the address of a
    cout<<"Data in 'a' "<<a<<"   AND     "<<"Data stored in p (C++) "<<*p<<endl;  // (*p) is called dereferencing
    printf("Data Stored in p (C) %d\n",*p);
    
    return 0;
}

