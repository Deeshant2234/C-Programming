#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
}* front = NULL,* rear = NULL;

void enqueueLL(int x){
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    if(t==NULL)
        printf("Queue is Full\n");
    else
    {   
        t->data = x; 
        t->next = NULL; 
        if(front==NULL)
            front = rear = t;
        else    
        {   rear->next = t;
            rear = t;
        }
    }
}

int dequeueLL()
{   int x =-1;
    struct node* temp;
    if(front==NULL)
        printf("Queue is empty");
    else 
        x = front->data;
        temp = front;
        front = front->next;
        free(temp);
}

int isEmpty()
{
    if(front==NULL)
        return 1;
    return 0;
}

int isFull()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));   
    if(temp == NULL)
        return 1;
    return 0;
}

int main()
{
    for(int i=0;i<5;i++)
        enqueueLL(11+(2*i));

    dequeueLL();
    dequeueLL();

    struct node* disp = front;
    while(disp)
    {
        printf("%d ",disp->data);
        disp = disp->next;
    }

    printf("\nQueue is FULL(%d) or EMPTY(%d)",isFull(),isEmpty());
    return 0;
}