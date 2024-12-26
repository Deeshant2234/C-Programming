// MERGE SORT: TWO SORTED LISTS IN ONE ARRAY USING RECURSION
#include <stdio.h>

void merge(int* arr, int l, int mid, int h)
{
    int B[12]={0};
    int i,j,k;
    i=k=0;
    j=mid+1;
    while(i<=mid&&j<=h)
    {
        if(arr[i]<arr[j])
            B[k++]=arr[i++];
        else
            B[k++]=arr[j++];
    }
    for(;i<=mid;i++)
        B[k++]=arr[i];
    for(;j<=h;j++)
        B[k++]=arr[j];
    //Copying B back in arr
    for(int i = 0; i<=h;i++)
        arr[i] = B[i]; 
}

void recursiveMergeSort(int* arr, int l, int h)
{
    if(l<h)
    {
        int mid = (l+h)/2;
        recursiveMergeSort(arr,l,mid);
        recursiveMergeSort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }   
}

int main()
{
    int arr[] = {8,4,6,1,12,13,2,16,11,200};
    int n = 10;

    recursiveMergeSort(arr,0,9);
   
    printf("Sorted Array ");
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }

}