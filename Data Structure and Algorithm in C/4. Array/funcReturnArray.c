#include <stdio.h>
#include <stdlib.h> //In order to use malloc function in C we have to add this header file

//since we want to return pointer pointing to an array i.e. in heap from the function so we cannot use void in this case

int* func(int s){
    int* p;
    p = (int*) malloc(sizeof(int)*s);    //p=new int[s];  C++
    return p;    
}

int main() {
    int Arsize;
    printf("Enter the array size ");
    scanf("%d",&Arsize);                 //cin>>Arsize; C++
    int* A;                              //pointer that will point to array
    A = func(Arsize);                    // A is a pointer that is indirectly pointing to a array dynamically created in Heap Memory 
    
    for(int i=0;i<Arsize;i++){
        A[i] = i+4;
        printf("A(%d)=%d\n", i, A[i]);
    }
    free(A);                             //delete[] A; //C++
    return 0;
}


