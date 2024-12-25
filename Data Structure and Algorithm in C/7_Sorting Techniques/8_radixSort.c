// RADIX SORT
#include<stdio.h>

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

void countSortDigitWise(int* arr,int n, int pos)
{   // This function is same as countSort but logic is updated
    // Here I have added one Important loop to count positions in Sorted array
    int count[10]={0};
    int temp[n];
    // loop will fill count array based on the digit
    for(int i=0; i<n; i++)
        count[(arr[i]/pos)%10]++;
    // Important step: Counting position in sorted array 
    for(int i=1; i<10; i++)
        count[i]+=count[i-1];
    // In temp array result of pass will be stored
    for(int i=n-1;i>=0;i--)
        temp[--count[(arr[i]/pos)%10]] = arr[i];
    // Pass result will be copied back to array arr
    for(int i=0; i<n; i++)
        arr[i]=temp[i]; 
}

void radixSort(int* arr,int n)
{
    int max = getMax(arr,n);
    for(int pos = 1; max/pos>0;pos=pos*10)
    {
        countSortDigitWise(arr,n,pos);
    }
}

int main()
{   int arr[] = {34,1,244,5,2,6};

    radixSort(arr,6);

    printf("Sorted Array: ");
    for (int i = 0; i < 6; i++)
        printf("%d ", arr[i]);
    return 0;
}