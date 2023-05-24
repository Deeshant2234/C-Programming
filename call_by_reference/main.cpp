// CALL BY Reference: PARAMETER PASSING METHOD

#include<iostream>
#include <stdio.h>
using namespace std;

void swap(int &x, int &y)   // In call by reference formal parameters are just the 
                            //reference of the actual parameters
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
    cout<<"----------ACTUAL PARAMETERS-----------"<<endl;
    printf("a=%d\n",a);
    printf("b=%d\n",b);
    swap(a,b);   
    cout<<"----------ACTUAL PARAMETERS AFTER SWAP-----------"<<endl;
    printf("a=%d\n",a);
    printf("b=%d\n",b);
    return 0;
}

//this program is an example of call by reference in this program any change in the formal 
//parameters is reflected in the actual parameters because formal parameters are nothing but the
//reference or we can say that they are nothing but the other name of actual parameters
