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
        printf("%d \n",p->data);
        p=p->next;
    }
}

void maxelement(struct Node *p){
    int max=INT32_MIN; // INT32_MIN is a constant defined in the C programming language that represents
    //the minimum value that can be stored in a variable of type int.
    //It is defined as -2147483648, which is the smallest (most negative) value that a 32-bit signed integer can hold.
    while(p){
        if(p->data>max){
            max=p->data;
        }
      p=p->next;
    }
    printf("Max element= %d \n",max);
}

int main()
{   int a[]={2,4,32,29};
    create(a,4);
    display(first);
    maxelement(first);
    
    return 0;
}
