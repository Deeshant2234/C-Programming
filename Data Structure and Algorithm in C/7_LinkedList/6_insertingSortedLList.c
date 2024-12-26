#include <stdio.h>
#include <stdlib.h> 
#include <stdint.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create(int a[],int n){
    struct Node*t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    
    for(int i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display(struct Node *p){
    while(p){
        printf("%d, ",p->data);
        p=p->next;
    }
}

void insertSorted(struct Node* p,int value){
    struct Node *q,*temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=value;
    temp->next=NULL;
    if(first==NULL){  // If Linked List is Empty
        first=temp;
    }
    else{
        while(p&&value>p->data)
        {
            q=p;
            p=p->next;
        }
        if(p==first) // If p is stopped at first node i.e. insert 2 in LL: 3,4,5,6,7
        {
            temp->next=first;
            first=temp;
        }
        else
        {
            temp->next=q->next;
            q->next=temp;
        }
    }
}

int main()
{   int a[]={2,4,6,9,11,14,19}; //I have shorted linked list now i have to insert node in this shorted LlS 
    create(a,7);
    display(first);
    insertSorted(first,5);
    printf("\nAfter Interting in a shorted list\n");
    display(first);
    return 0;
}


