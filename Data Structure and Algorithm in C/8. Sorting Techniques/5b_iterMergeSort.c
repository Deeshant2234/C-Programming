// MERGE SORT: TWO SORTED LISTS IN ONE ARRAY
// Let we have a array ={3,4,6,7,12,13,14,16} 
// first sorted list is 3,4,6,7 and 2nd is 12,13,14,16
// Merge Sort is the only algorithm which require extra spaces
#include <stdio.h>

void merge(int* arr, int l, int mid, int h)
{
    int B[27];            // Auxilary Array of Size>=Array To Be Sorted

    int i = l;
    int j = mid+1;
    int k = l;

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
    for(int i=l; i<=h;i++)
        arr[i] = B[i]; 
}

void iterMergeSort(int* arr, int n)
{
    int p,l,h,mid,i;
    // P is a pass In 1st Pass,1 elements lists will be merged
    // In 2nd pass,2 element lists will be merged and so on
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(arr,l,mid,h);
        }
 
        // Handle remaining elements if any
        if(n-i>p/2)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(arr,l,mid,n-1);
        }
    }
    // P value at which loop condition failed divide by 2 
    // If this value is less than n means array is of odd length
    // and one element is still left to be merged
    if(p/2<n)
        merge(arr,0,p/2-1,n-1);

}

int main()
{
    int arr[] = {4,2,9,5,1,7,10,50,4,2,9,5,1,7,10,50,45,2,1,444,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    iterMergeSort(arr,n);

    printf("Sorted Array by Iterator ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

}