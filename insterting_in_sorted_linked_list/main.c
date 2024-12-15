/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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

void insertshorted(struct Node* p,int value){
    struct Node *q,*t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=value;
    t->next=NULL;
    if(first==NULL){
        first=t;
    }
    else{
        while(p&&value>p->data){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}

int main()
{   int a[]={2,4,6,9,11,14,19}; //I have shorted linked list now i have to insert node in this shorted LlS 
    create(a,7);
    display(first);
    insertshorted(first,5);
    printf("\nAfter Interting in a shorted list\n");
    display(first);
    return 0;
}


