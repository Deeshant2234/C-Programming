#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*top=NULL;

void push(int key)
{
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    
    if(t==NULL)
        return;
    else
    {
        t->data = key;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct node *t;
    int x;
    if(top==NULL)
        return -1;
    else
    {
        t=top;
        x = t->data;
        top = top->next;
        free(t);
    }
    return x;
}

int isEmpty()
{
    if(top==NULL)
        return 1;
    return 0;
}

void display()
{   struct node *s = top;
    while(s!=NULL)
    {
        printf("%d \n",s->data);
        s = s->next;
    }
}

int main()
{  
    
    for(int i=0;i<5;i++)
    {
        printf("Pushing %d to stack\n",i+1);
        push(i+1);
    }

    printf("\n");
    printf("\n");

    for(int i=0;i<5;i++)
        printf("Popped %d from top \n",pop());

    printf("\nStack is Empty: %s\n",isEmpty()?"YES":"NO");

    return 0;
}
