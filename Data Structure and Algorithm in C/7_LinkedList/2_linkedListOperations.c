#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n){
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    
    for(int i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    
}

void Display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

void RDisplay(struct Node *p){
    if(p!=NULL){
        printf("%d ",p->data);
        RDisplay(p->next);
    }
}


void RDisplay_reverse(struct Node *p){
    if(p!=NULL){
        RDisplay_reverse(p->next);
        printf("%d ",p->data);
    }
}

int count(struct Node *p){
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}

int Rcount(struct Node *p){
    if(p!=NULL){
        return Rcount(p->next)+1;
    }
    else return 0;
}

int Esum(struct Node *p){
    int sum=0;
    while(p!=NULL){
        sum=sum+(p->data);
        p=p->next;
    }
    return sum;
}

int Rsum(struct Node *p){
    int sum=0;
    if(p!=NULL){
        return Rsum(p->next)+(p->data);
    }
    else return 0;
}

int main()
{   int A[]={3,5,7,10,15,10};
    create(A,6);
    
    printf("Printing Linked List \n");
    Display(first);
    
    printf("\nPrinting Linked List using Recursion \n");
    RDisplay(first);
    
    printf("\nPrinting reversed Linked List using Recursion \n");
    RDisplay_reverse(first);
    
    printf("\nReturning Number of Nodes \n");
    int c=count(first);
    printf("%d\n",c);
    
    printf("Returning Number of Nodes Counting Recursively \n");
    int rc=Rcount(first);
    printf("%d\n",rc);
    
    printf("Returning Sum of Elements \n");
    int sum=Esum(first);
    printf("%d\n",sum);
    
    printf("Returning Sum of Elements Recursively \n");
    int rsum=Rsum(first);
    printf("%d\n",rsum);
    
    return 0;
}
