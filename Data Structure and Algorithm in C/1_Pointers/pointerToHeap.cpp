#include <iostream>
#include <stdio.h>  //c
#include <stdlib.h> //c
using namespace std;

int main()
{   int *p;
    p=(int *)malloc(5*sizeof(int));
    //or
    //p=new int[5]; //c++
    p[1]=4;
    p[0]=9;
    
    int i=0;
    while(i<5){
        printf("p[%d]=%d\n",i,p[i]);
        i++;
    }
    free(p);
    // delete [] p; //c++
    return 0;
}
