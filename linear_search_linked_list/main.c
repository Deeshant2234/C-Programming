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

struct Node* lsearch(struct Node *p,int key){
    while(p){
        if(key==p->data){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

struct Node* lsearch_improved(struct Node *p,int key){   //improving linear search by moving the key node to head 
    struct Node*q;
    while(p){
        if(key==p->data){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

int main(){
    struct Node *temp;
    int a[]={1,2,42,43,12,2};
    create(a,6);
    display(first);
    temp=lsearch(first,12);
    if(temp){
        printf("\nKey found: Data= %d  Address %p",temp->data, temp->next);
    }
    else{
        printf("\nKey not found");
    }
    
    printf("\n---------------------------");
    printf("\nLinear Search with Moving to Head");
    temp=lsearch_improved(first,12);
    
     if(temp){
        printf("\nKey found: Data= %d  Address %p",temp->data, temp->next);
        printf("\nModified Liked List for Linear Search\n");
        display(first);
    }
    else{
        printf("\nKey not found");
    }
    
}



