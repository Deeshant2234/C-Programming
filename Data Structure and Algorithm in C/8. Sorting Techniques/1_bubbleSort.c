// BUBBLE SORT
#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Swap variables using Bit Manipulation */
void swapBitManipulation(int *a, int *b)
{
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}

void bubbleshort(int* arr, int size)
{
    for(int i=0; i<size-1;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                // swap(&arr[j],&arr[j+1]);
                swapBitManipulation(&arr[j],&arr[j+1]);
            }
        }
    }
    
}

void bubbleshort_adaptive(int* arr, int size)
{
    for(int i=0; i<size-1;i++)
    {
        int flag =0;
        for(int j=0;j<size-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                flag=1;
            }
        }
        /* If number of Swaps in 1st pass is Zero
           then array already Sorted */
        if(flag==0)
            break;
    }
    
}

int main()
{
    int a[] = {12,3,4,5,2,2,0};
    int b[] = {1,2,3,4,5};
    printf("Performing Bubble Short\n");
    
    bubbleshort(a,7);
    printf("Sorted Array1: ");
    for(int i=0;i<7;i++)
    {
        printf("%d ",a[i]);
    }
    
    bubbleshort_adaptive(b,5);
    
    printf("\n");
    printf("Sorted Array2: ");
    for(int i=0;i<5;i++)
        printf("%d ",b[i]);
        
    return 0;
}