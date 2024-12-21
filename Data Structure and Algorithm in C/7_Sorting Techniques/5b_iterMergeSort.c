// MERGE SORT: TWO SORTED LISTS IN ONE ARRAY
// Let we have a array ={3,4,6,7,12,13,14,16} 
// first sorted list is 3,4,6,7 and 2nd is 12,13,14,16
#include <stdio.h>

void mergeSort(int* arr, int l, int mid, int h)
{
    int B[12]={0};
    int i,j,k;
    i=k=0;
    j=mid+1;
    while(i<=mid&&j<=h)
    {
        if(arr[i]<arr[j]){
            B[k++]=arr[i];
            i++;
        }
        else
        {
            B[k++]=arr[j];
            j++;
        }
    }
    for(;i<=mid;i++)
    {
        B[k++]=arr[i];
    }
    for(;j<=h;j++)
    {
        B[k++]=arr[j];
    }

    //Copying B back in arr
    for(int i = 0; i<=h;i++)
    {
        arr[i] = B[i]; 
    }

}

int main()
{
    int arr[] = {3,4,6,7,12,13,14,16,20,200}; 
    mergeSort(arr,0,3,9);
}