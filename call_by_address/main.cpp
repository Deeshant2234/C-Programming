// CALL BY ADDRESS: PARAMETER PASSING METHOD

#include<iostream>
#include <stdio.h>
using namespace std;

void swap(int *x, int *y)   // In call by address formal parameters are the pointers those 
                            //are pointing to the address of the actual parameters
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
    cout<<"----------FORMAL PARAMETERS-----------"<<endl;
    cout<<"In C"<<endl;
    printf("x=%d\n",*x);
    printf("y=%d\n",*y);
    cout<<"In C++"<<endl;
    cout<<"X="<<*x<<endl;
    cout<<"Y="<<*y<<endl;
}

int main()
{
    
    int a=10,b=20;
    cout<<"----------ACTUAL PARAMETERS-----------"<<endl;
    printf("a=%d\n",a);
    printf("b=%d\n",b);
    swap(&a,&b);   // In this method we have passed address instead of value
    cout<<"----------ACTUAL PARAMETERS AFTER SWAP-----------"<<endl;
    printf("a=%d\n",a);
    printf("b=%d\n",b);
    return 0;
}

//this program is an example of call by address in this program any change in the formal 
//parameters is reflected in the actual parameters