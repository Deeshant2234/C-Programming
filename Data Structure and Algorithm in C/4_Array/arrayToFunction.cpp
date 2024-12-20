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

