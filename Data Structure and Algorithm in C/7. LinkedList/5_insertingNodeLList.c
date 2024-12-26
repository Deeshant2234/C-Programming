#include <stdio.h>
#include <stdlib.h>

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

int countNodes(struct Node *p){
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}

void insertNode(struct Node *p,int index, int value){
    if(index<0|| index>countNodes(first)){
        printf("\nIndex %d is not in scope of 0 to %d : No Insertion",index,countNodes(first));
        return ;
    }
    struct Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=value;
    if(index==0){
        temp->next=first;
        first=temp;
    }
    else if(index>0){
        for(int i=0;i<index-1&&p;i++)
            p=p->next;
        if(p)
        {   temp->next=p->next;
            p->next=temp;
        }
    }
}

void display(struct Node *p){
    while(p){
        printf("%d,",p->data);
        p=p->next;
    }
}

int main()
{   int a[]={2,4,32,29};
    create(a,4);
    display(first);
    insertNode(first,5,12);  //index 2 means new node after 2nd Node //data=12
    printf("\nAfter Inserting\n");
    display(first);
    return 0;
}


