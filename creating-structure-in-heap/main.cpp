/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle *p;
    struct Rectangle *p1;
    p=(struct Rectangle*)malloc(sizeof(struct Rectangle));
    p1=new Rectangle;
    p->length=10;
    p->breadth=5;
    p1->length=10;
    p1->breadth=5;
    
    printf("--------------\n");
    printf("C Code\n");
    printf("--------------\n");
    printf("Length p= %d\n",p->length);
    printf("Breadth p= %d\n",p->breadth);
    
    cout<<"--------------"<<endl;
    cout<<"C++ Code"<<endl;
    cout<<"--------------"<<endl;
    cout<<"Length p1= "<<p1->length<<endl;
    cout<<"Breadth p1= "<<p1->breadth<<endl;
    
    return 0;
}