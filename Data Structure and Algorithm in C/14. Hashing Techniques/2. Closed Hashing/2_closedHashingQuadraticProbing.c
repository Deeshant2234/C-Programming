#include <stdio.h>
#define SIZE 10

int hash(int key)
{
    return key%SIZE;
}

void insertQuadraticProbing(int *H, int key)
{
    int index = hash(key);
    
    if(H[index]!=0)
    {   
        int i = 0;
        /* Finding empty index linearly in circular fashion */
        while(H[(index+i*i)%SIZE]!=0)                         // (index+i^2)%SIZE ; i = 0,1,2,3,4..
            i++;
        H[(index+i*i)%SIZE]=key;
    }
    else
    {
        H[index]=key;
    }
}

int search(int H[], int key)
{   int index=hash(key);
    int i = 0;
    while(H[(index+i*i)%SIZE]!=key)
    {
        if(H[(index+i*i)%SIZE]==0)
        {   
            return -1;
        }
        i++;
    } 
    return (index+i*i)%SIZE;
}

int main()
{
    int HT[SIZE] = {0};
    insertQuadraticProbing(HT,12);
    insertQuadraticProbing(HT,2);
    insertQuadraticProbing(HT,4);
    insertQuadraticProbing(HT,22);
    printf("Key found at %d index", search(HT,13));
    return 0;
}