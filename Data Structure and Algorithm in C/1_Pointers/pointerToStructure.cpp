#include <stdio.h>
#include <iostream>
using namespace std;

struct Rectangle
{
   int length;
   int breadth;
};

int main()
{   
    struct Rectangle r={10,3};
    struct Rectangle *p ;
    p=&r;
    printf("Printing r and p in C Language\n");
    printf("r(0)= %d\n",r.length);  //c
    printf("r(1)= %d\n",r.breadth);  //c
    printf("p(0)= %d\n",(*p).length); //c
    printf("p(1)= %d\n",p->breadth); //c
    
    cout<<"Printing using C++"<<endl;
    cout<<p->length<<endl; //c++
    cout<<p->breadth<<endl; //c++
    
    return 0;
}


