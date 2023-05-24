/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
#include <stdio.h>
using namespace std;
int main()
{ int a[5]={2,3,4,2,4};
  int *p;
  p=a;
  //or
  //p=&a[0];
  printf("a[0]=%d\n p[0]=%d\n",a[0],p[0]);
    return 0;
}
