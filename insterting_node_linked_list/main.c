/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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
        last->next=t;
        last=t;
    }
}

int count(struct Node *p){
    int count=0;
    while(p){
        p=p->next;
        count++;
    }
    return count;
}


void insert(struct Node *p,int index, int value){
    if(index<0|| index>count(first)+1){
        printf("\nIndex %d is not in scope of 0 to %d : No Insertion",index,count(first)+1);
        return;
    }
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=value;
    if(index==0){
        t->next=first;
        first=t;
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
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
    insert(first,-1,12);  //index 2 means new node after 2nd Node //data=12
    printf("\nAfter Inserting\n");
    display(first);
    return 0;
}


