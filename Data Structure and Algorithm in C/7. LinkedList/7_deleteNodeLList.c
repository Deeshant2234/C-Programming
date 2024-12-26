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

int count(struct Node*p){
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}

int deleteNode(struct Node* p,int index){
    struct Node *q=NULL,*t=NULL;
    if(index<1||index>count(first)){
        return -1;
    }
    if(index==1){
        t=first;
        int x=first->data;
        first=first->next;
        free(t);
        return x;
    }
    else{
        for(int i=1;i<=index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        int x=p->data;
        free(p);
        return x;
        
    }
}

int main()
{   int a[]={2,4,6,9,11,14,19}; //I have shorted linked list now i have to insert node in this shorted List 
    int index=14;
    create(a,7);
    display(first);
    int data=deleteNode(first,index);
    printf("\nAfter deleting node %d from the linked list of value %d \n",index,data);
    display(first);
    return 0;
}



