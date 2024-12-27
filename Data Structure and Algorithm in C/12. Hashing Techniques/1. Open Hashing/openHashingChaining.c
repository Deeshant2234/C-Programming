#include <stdio.h>
#include "openHashingChaining.h"

int hashFunction(int key)
{
    return key%10;
}

void insertHT(struct Node *H[], int key)
{   
    int index = hashFunction(key);
    sortedInsert(&H[index],key);   // Pass address of pointer
}

int main()
{   
    struct Node* HT[10];
    struct Node* temp;

    for(int i=0;i<10;i++)
        HT[i]=NULL;

    insertHT(HT,12);
    insertHT(HT,21);
    insertHT(HT,31);
    insertHT(HT,11);

    temp = search(HT[hashFunction(31)],31);
    printf("%d",temp->data);

    return 0;
}