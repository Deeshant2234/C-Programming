#include<stdio.h>

void swap(int*x, int*y){
    int temp=*x;
    *x=*y;
    *y=temp;
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
    int arr[] = {3,2,4,1,6,6,45,67,34,5,60};
    
    quickSort(arr,0,10);
    
    printf(" Sorted Array: ");

    for(int i=0; i<10; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}