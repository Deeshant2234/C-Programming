#include <stdio.h>
#include<stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void insert(struct Array *arr,int index,int x)
{
    int i;
    if(index>=0 && index <=arr->length)
    {
        for(i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;

    }
}

int main()
{
    struct Array arr;
    // printf("Enter Array Size: ");
    // scanf("%d",&arr.size);
    arr.size=5;
    //ARRAY IN HEAP
    arr.A=(int *)malloc(arr.size*sizeof(int));
    arr.length=0;

    //INSERTING ELEMENTS IN THE ARRAY
    for(int i=0;i<arr.size;i++)
        insert(&arr,0,i*4);

    return 0;
}