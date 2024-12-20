/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int nxor(int x){
    if(x%4==0){
        return x;
    }
    else if(x%4==1){
        return 1;
    }
    else if(x%4==2){
        return x+1;
    }
    else{
        return 0;
    }
}

int main()
{   
    int n=0;
    printf("enter Input");
    scanf("%d",&n);
    int x=nxor(n);
    printf("XOR of 1-to-%d is %d",n,x);
    return 0;
}

