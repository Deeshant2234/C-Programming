#include <stdio.h>
#define SIZE 10

int hash(int key)
{
    return key%SIZE;
}

void insertLinearProbing(int *H, int key)
{
    int index = hash(key);
    
    if(H[index]!=0)
    {   
        int i = 0;
        /* Finding empty index linearly in circular fashion */
        while(H[(index+i)%SIZE]!=0)  
            i++;
        H[(index+i)%SIZE]=key;
    }
    else
    {
        H[index]=key;
    }
}

int search(int H[], int key)
{   int index=hash(key);
    int i = 0;
    while(H[(index+i)%SIZE]!=key)
    {
        if(H[(index+i)%SIZE]==0)
            return -1;
        i++;
    } 
    return (index+i)%SIZE;
}

int main()
{
    int HT[SIZE] = {0};
    insertLinearProbing(HT,12);
    insertLinearProbing(HT,2);
    insertLinearProbing(HT,4);
    insertLinearProbing(HT,22);
    printf("Key found at %d index", search(HT,12));
    return 0;
}