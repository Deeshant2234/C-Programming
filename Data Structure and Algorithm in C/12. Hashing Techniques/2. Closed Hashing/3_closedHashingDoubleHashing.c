#include <stdio.h>
#define SIZE 10
#define PRIME 7    // Nearest Prime Number smaller than SIZE

int hash(int key){
    return key % SIZE;
}
 
int primeHash(int key){
    return PRIME - (key % PRIME);
}

void insertDoubleHashing(int* H, int key)
{
    int index = hash(key);
    if(H[index]!=0)
    {   int i = 0;
        int h2 = primeHash(key);
        while(H[(index+i*h2)%SIZE]!=0)
            i++;
        H[(index+i*h2)%SIZE] = key;
    }
    else
    {
        H[index] = key;
    }
}

int search(int* H, int key)
{
    int index = hash(key);
    int h2 = primeHash(key);
    int i=0;
    
    while(H[(index+i*h2)%SIZE]!=key)
    {
        if(H[(index+i*h2)%SIZE]==0)
            return -1;
        i++;
    }
    return (index+i*h2)%SIZE;
}


int main()
{   
    int A[] = {5, 25, 15, 35, 95};
    int n = sizeof(A)/sizeof(A[0]);

    // Hash Table
    int HT[SIZE] = {0};
    for (int i=0; i<n; i++){
        insertDoubleHashing(HT, A[i]);
    }

    printf("\n Key found at %d\n", search(HT,35));
    return 0;
}