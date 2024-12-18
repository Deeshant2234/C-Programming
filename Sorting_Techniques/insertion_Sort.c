#include <stdio.h>

void insertionSort(int* arr, int size){
    for(int i=1; i<size;i++){
        int j = i-1;
        int x=arr[i];
        while(j>-1&&arr[j]>x){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=x;
    }
}

int main()
{   
    int a[] = {374,6,1,233,5,8};
    printf("Performing Insertion Sorting Algorithm");
    insertionSort(a,6);
    printf("\n");
    for(int i=0;i<6;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
