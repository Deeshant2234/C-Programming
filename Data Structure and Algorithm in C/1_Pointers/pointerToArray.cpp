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
