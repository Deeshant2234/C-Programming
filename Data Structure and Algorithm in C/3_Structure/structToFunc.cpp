//we can pass structure as a (1) Value  (2) Reference (3) Address*
#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

int area_v(struct Rectangle r1){
    return(r1.length*r1.breadth);
}
int area_r(struct Rectangle &r1){
    return(r1.length*r1.breadth);
}

int area_a(struct Rectangle *p){
    return(p->length*p->breadth);
}


int main()
{
    struct Rectangle r; //structure declaration in main;
    r={10,5};
    
    printf("-------Structure Call by Value--------\n");
    int a_v=area_v(r); //structure call by value
    printf("Area of the Rectangle= %d\n",a_v);
    
    printf("-------Structure Call by Reference--------\n");
    int a_r=area_r(r); //structure call by reference
    printf("Area of the Rectangle= %d\n",a_r);
    
    printf("-------Structure Call by Address--------\n");
    int a_a=area_a(&r); //structure call by address
    printf("Area of the Rectangle= %d\n",a_a);
    
    return 0;
}
