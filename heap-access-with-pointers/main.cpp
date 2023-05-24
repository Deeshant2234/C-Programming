/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

//malloc function is used in C to access heap memory with Pointer and new func. is used in C++ 
#include <iostream> //C++
#include <stdio.h>  //C
#include <stdlib.h>
using namespace std; //C++
int main()
{   
    int *p;
    int *p1;
    p=(int*)malloc(5*sizeof(int));          // C language 
    p1= new int[5];                         // C++
    p[0]=0; p[1]=1; p[2]=2; p[3]=3; p[4]=4; // C
    p1[0]=0;p1[1]=1;p1[2]=2;p1[3]=3;p1[4]=4;
    
    cout<<"Value of Array i.e. created in Heap and Accessed by pointer p1 (C++)  "<<endl;
    for(int i=0;i<=4;i++)
    {
        cout<<p1[i]<<endl;
    }
    
    printf("Value of Array i.e. created in Heap and Accessed by pointer p (C)");
    for(int i=0;i<=4;i++)
    {
        printf("\n %d",p1[i]);
    }

    return 0;
}



