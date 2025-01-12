// SELECTION SORT
#include <stdio.h>

void swap(int*x, int*y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void selectionSort(int arr[], int size){
    int i,j,k;
    for(i=0;i<size-1;i++)
    {
        for(j=k=i;j<size;j++)
        {
            if(arr[j]<arr[k])
                k=j;
        }
        swap(&arr[i],&arr[k]);
    }
}

int main()
{   
    int a[] = {374,6,1,233,5};
    selectionSort(a,5);
    printf("\n");
    printf("Sorted Array: ");
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }
    return 0;
}