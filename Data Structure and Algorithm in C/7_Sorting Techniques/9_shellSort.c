#include<stdio.h>

void shellSort(int* arr, int n)
{
    int gap,i,j,temp;

    for(gap=n/2;gap>=1;gap=gap/2)
    {
        for(int i=gap;i<n;i++)
        {
            temp = arr[i]; //element to be inserted (at gap)
            j  = i-gap; 
            while(j>=0 && arr[j]>temp)
            {
                arr[j+gap] = arr[j];
                j = j - gap;
            }
            arr[j+gap]=temp;
        }
    }
}

int main()
{   
    int arr[10] = {2,3,1,4,2,5,1,12,14,13};
   
    shellSort(arr,10);
   
    printf("Sorted Array: ");
    for(int i=0; i<10; i++)
        printf("%d ",arr[i]);

    return 0; 
}