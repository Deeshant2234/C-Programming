#ifndef openHashingChaining_h
#define openHashingChaining_h
#include<stdlib.h>

// Structure of Node in Linked List
struct Node
{
    int data;
    struct Node *next;
};

// Function to Insert Node in a Linked List at sorted position
// If you use struct Node *H (a single pointer):
// You can traverse the list and modify its nodes.
// However, you cannot change the head of the list because you
// are only modifying a copy of the head pointer inside the function.
static void sortedInsert(struct Node **H,int x)
{
    struct Node *t,*q=NULL,*p=*H;

    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(*H==NULL)
        *H=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }   
        if(p==*H)
        {
            t->next=*H;
            *H=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }

}

// Function to search for a key in sorted Linked List
static struct Node* search(struct Node *p,int key)
{
    while(p!=NULL)
    {
        if(key==p->data)
        {
            return p;
        }
            p=p->next;
    }
    return NULL;

}

#endif /* openHashingChaining_h */