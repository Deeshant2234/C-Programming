// MERGE SORT: TWO SEPERATE SORTED ARRAY
#include <stdio.h>
#include <stdlib.h>

//function updating resultant array with sorted elements from x and y
void mergeSort(int*x, int sizex, int*y , int sizey, int*z)
{   int i,j,k;
    i=j=k=0;
    while(i<sizex&&j<sizey)
    {
        if(x[i]<y[j])
        {
            z[k++]=x[i];
            i++;
        }
        else
        {
            z[k++]=y[j];
            j++;
        }
    }

    for(;i<sizex;i++)
    {
        z[k++] = x[i];
    }

    for(;j<sizey;j++)
    {
        z[k++] = y[j];
    }
    
}

//function returning array 
int* mergeSortArray(int* x, int* y, int sizex, int sizey)
{ 
    int i,j,k;
    i=j=k=0;
    
    //Output array created in heap 
    int *z=(int *)malloc((sizex+sizey)*sizeof(int));
    
    // Memory Allocation Check
    if (z == NULL) 
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    while(i<sizex&&j<sizey)
    {
        if(x[i]<y[j])
        {
            z[k++]=x[i];
            i++;
        }
        else
        {
            z[k++]=y[j];
            j++;
        }
    }

    for(;i<sizex;i++)
    {
        z[k++] = x[i];
    }

    for(;j<sizey;j++)
    {
        z[k++] = y[j];
    }

    return z ;
}


int main()
{
    int x[] = {2,4,5,6,8,13,34};
    int y[] = {3,4,5,6};
    int z[11] = {0}; /* Array to hold merged sorted array*/
    int* z_new;
    mergeSort(x,7,y,4,z);

    printf("Sorted Array: ");
    for(int i =0; i<11;i++)
    {
        printf("%d ",z[i]);
    }

    // function returning array 
    z_new = mergeSortArray(x,y,7,4);
    printf("\nSorted Array by Heap: ");
    for(int i =0; i<11;i++)
    {
        printf("%d ",z_new[i]);
    }
    free(z_new);
    return 0;
}