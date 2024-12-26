// CALL BY VALUE: PARAMETER PASSING METHOD
#include<iostream>
#include <stdio.h>
using namespace std;

void swap(int x, int y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
    cout<<"----------FORMAL PARAMETERS-----------"<<endl;
    cout<<"In C"<<endl;
    printf("x=%d\n",x);
    printf("y=%d\n",y);
    cout<<"In C++"<<endl;
    cout<<"X="<<x<<endl;
    cout<<"Y="<<y<<endl;
}

int main()
{
    
    int a=10,b=20;
    swap(a,b);
    cout<<"----------ACTUAL PARAMETERS-----------"<<endl;
    printf("a=%d\n",a);
    printf("b=%d\n",b);
    return 0;
}

//this program is an example of call by value in this program any change in the formal 
//parameters is not reflected in the actual parameters