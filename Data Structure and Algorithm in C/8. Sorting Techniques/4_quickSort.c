// QUICK SORT
#include<stdio.h>

void swap(int *a,int *b)
{   
    /* Fails when swapping same memory location (a[i] with a[i])
    In quicksort, sometimes i==j during partition
    XOR swap corrupts value when a and b point to same location */
    
    if(a != b)
    {
        *a = *a^*b;
        *b = *a^*b;
        *a = *a^*b;
    }

}

int partitioningFunc(int *arr, int l, int h)
{
    int pivot = arr[l];
    int i = l;
    int j = h;

    do
    { 
        do{i++;}while(arr[i]<=pivot);
        do{j--;}while(arr[j]>pivot);
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    while(i<j);
    swap(&arr[l],&arr[j]);
    return j;
}

void quickSort(int *arr, int l , int h)
{   
    int j; //Pivot Index

    if(l<h)
    {
        j = partitioningFunc(arr,l,h);
        quickSort(arr,l,j);
        quickSort(arr,j+1,h);
    }
}

int main()
{   
    int arr[] = {4,2,9,5,1,7,10,50,0,4,2,9,5,1,7,10,50,0};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,size);
    
    printf(" Sorted Array: ");

    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}