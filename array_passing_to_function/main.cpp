/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<iostream>
using namespace std;
void fun(int Ar[],int s)  // or void fun(int *Ar, int s ) Arrays are always passed by address they cannot be passed by value
{
    for(int i=0;i<s;i++)
    {
        //In C
        //printf("Array value A[%d]=%d \n",i,Ar[i]);
        
        //In C++
        cout<<"Array value A["<<i<<"]="<<Ar[i]<<endl;
        
    }
}

int main()
{  int A[5] ={1,2,3,4,5}; //array declaration and initialization
   fun(A,5);
   return 0;
}

