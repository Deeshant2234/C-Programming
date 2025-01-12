// COUNT SORT
#include <stdio.h>

int getMax(int* arr, int n)
{
    int max = arr[0];
    for(int i=0; i<n;i++)
    {
        if(max<arr[i])
            max=arr[i];
    }
    return max;
}

void countSort(int *arr, int n)
{
    int max = getMax(arr,n);
    int count[max+1];
    int temp[n];
    for(int i=0; i<max+1;i++)
        count[i]=0;
    
    for(int i=0;i<n;i++)
        count[arr[i]]++;
    int i = 0;
    int j = 0;
    while(i<max+1){
        if(count[i]!=0)
        {
            arr[j++]=i;
            count[i]--;
        }
        else
            i++;
    }
    // //---------OR-------------- //
    // // Finding sorted indexes for all values
    // for(int i=1; i<max+1; i++)
    //     count[i]+=count[i-1];
    // // For each arr[i] check its sorted index and copy in temp array
    // for(int i=0; i<n; i++)
    //     temp[--count[arr[i]]]=arr[i];
    // for(int i=0; i<n; i++)
    //     arr[i]=temp[i];
}

int main()
{
    int arr[]= {3,4,1,2,4,29,10,9,7,11,30,1,22,4};
    countSort(arr,14);
    for(int i=0; i<14; i++){
        printf("%d ",arr[i]);
    }
}