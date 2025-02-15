#include<stdio.h>
#include<stdlib.h>
#include <windows.h>

void swap(int *a,int *b)
{   
    /* Fails when swapping same memory location (a[i] with a[i])
    In quicksort, sometimes i==j during partition
    XOR swap corrupts value when a and b point to same location */
    
    if(a != b)
    {
        *a = *a^*b;
        *b = *a^*b;
        *a = *a^*b;
    }

}

void printArray(int a[], int n)
{
    int i=0;
    while(i<n)
    {
        printf("%d ",a[i]);
        i++;
    }
    printf("\n");
}

/*********************************************************************************/
/*******************************| Sorting Algorithms |****************************/
/*********************************************************************************/

void bubbleSort(int a[], int n)
{
    for(int i=0;i<n-1;i++)              //For Number of Passes
    {
        for(int j=0;j<n-1-i;j++)        //Number of Comparison
        {
            if(a[j]>a[j+1])
                swap(&a[j],&a[j+1]);
        }
    }
}

void insertionSort(int a[], int n)
{   
    int j,x;
    for(int i=1;i<n;i++)                // Number of element to insert
    {
        x = a[i];                       // Element to be inserted
        j = i-1;
        while(j>=0 && a[j]>x)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}

void selectionSort(int a[], int n)
{   
    int j,k;
    for(int i=0;i<n;i++)                // Hold the position to be sorted
    {
        for(j=k=i;j<n;j++)              // iterate through the array
        {
            if(a[j]<a[k])
                k=j;
        }
        swap(&a[i],&a[k]);              // ith pos. is sorted with sorted element from kth pos.
    }
}

// { QUICK SORT
int partition(int *a, int l, int h)
{
    int pivot = a[l];                   // Choose the pivot element
    int i = l, j = h;
    
    do
    {
        do{i++;}while(a[i]<=pivot);     // Increment i until an element greater than pivot is found
        do{j--;}while(a[j]>pivot);      // Decrement j until an element less than or equal to pivot is found
        if(i<j)
            swap(&a[i],&a[j]);          
    } while(i<j);

    swap(&a[l],&a[j]);                  // Swap pivot element with element at j
    return j;                           // Return the partition index
}

void quickSort(int *a, int l, int h)
{
    int j;
    if(l<h)
    {
        j = partition(a,l,h);            // Partition the array
        quickSort(a,l,j);                // Recursively sort the left subarray
        quickSort(a,j+1,h);              // Recursively sort the right subarray
    }
}
// }

//{ MERGE SORT

void merge(int *a, int l, int mid, int h)
{
    int B[20] = {0};
    int i = l;
    int j = mid+1;
    int k = l;

    while(i<=mid && j<=h)
    {
        if(a[i]<a[j])
            B[k++]=a[i++];
        else
            B[k++]=a[j++];
    }

    for(;i<=mid;i++)
        B[k++]=a[i];
    for(;j<=h;j++)
        B[k++]=a[j];

    // Copying Back to a
    for(i=l;i<=h;i++)
        a[i]=B[i];
}

void mergeSort(int *a,int n)
{   
    int p, l, mid, h, i;
    for(p=2; p<=n; p*=2)
    {
        for(i=0; i+p-1<n; i+=p)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(a,l,mid,h);
        }
        if(n-i>p/2)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(a,l,mid,n-1);
        }
    }
    if(p/2<n)
        merge(a,0,p/2-1,n-1);
}

//}

/*********************************************************************************/
/*********************************************************************************/
/*********************************************************************************/

int main()
{
    int arr1[] = {4,2,9,5,1,7,10,50,0,4,2,9,5,1,7,10,50,0};
    int arr2[] = {4,2,9,5,1,7,10,50,0,4,2,9,5,1,7,10,50,0};
    int arr3[] = {4,2,9,5,1,7,10,50,0,4,2,9,5,1,7,10,50,0};
    int arr4[] = {4,2,9,5,1,7,10,50,0,4,2,9,5,1,7,10,50,0};
    int arr5[] = {4,2,9,5,1,7,10,50,0,4,2,9,5,1,7,10,50,0};
    int size = sizeof(arr1)/sizeof(arr1[0]);

    LARGE_INTEGER frequency, start, end;
    double interval;

    QueryPerformanceFrequency(&frequency);

    // Bubble Sort Timing
    QueryPerformanceCounter(&start);
    bubbleSort(arr1, size);
    QueryPerformanceCounter(&end);
    interval = ((double)(end.QuadPart - start.QuadPart) * 1000000.0) / frequency.QuadPart;
    printf("Time Taken By Bubble Sort: %.2f microseconds\n", interval);
    
    // Insertion Sort Timing
    QueryPerformanceCounter(&start);
    insertionSort(arr2, size);
    QueryPerformanceCounter(&end);
    interval = ((double)(end.QuadPart - start.QuadPart) * 1000000.0) / frequency.QuadPart;
    printf("Time Taken By Insertion Sort: %.2f microseconds\n", interval);

    // Selection Sort Timing
    QueryPerformanceCounter(&start);
    insertionSort(arr3, size);
    QueryPerformanceCounter(&end);
    interval = ((double)(end.QuadPart - start.QuadPart) * 1000000.0) / frequency.QuadPart;
    printf("Time Taken By Selection Sort: %.2f microseconds\n", interval);

    
    // Quick Sort Timing
    QueryPerformanceCounter(&start);
    quickSort(arr4,0,size);
    QueryPerformanceCounter(&end);
    interval = ((double)(end.QuadPart - start.QuadPart) * 1000000.0) / frequency.QuadPart;
    printf("Time Taken By Quick Sort: %.2f microseconds\n", interval);
    
     // Quick Sort Timing
    QueryPerformanceCounter(&start);
    mergeSort(arr5,size);
    QueryPerformanceCounter(&end);
    interval = ((double)(end.QuadPart - start.QuadPart) * 1000000.0) / frequency.QuadPart;
    printf("Time Taken By Merge Sort: %.2f microseconds\n", interval);

    printf("\n1. Bubble Sort Result: ");
    printArray(arr1, size);
    printf("2. Insertion Sort Result: ");
    printArray(arr2, size);
    printf("3. Selection Sort Result: ");
    printArray(arr3, size);
    printf("4. Quick Sort Result: ");
    printArray(arr4, size);
    printf("5. Merge Sort Result: ");
    printArray(arr5, size);

    return 0;
}
