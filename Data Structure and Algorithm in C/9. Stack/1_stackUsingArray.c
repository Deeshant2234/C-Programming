#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    /* Pointer to array */
    int *S;     
};

void create(struct stack *s, int size)
{
    s->size = size;
    s->top = -1;
    s->S = (int *)malloc(s->size*sizeof(int));
}

void push(struct stack *s, int key)
{
    if(s->top==s->size-1)
        return;
    else
    {
        s->top++;
        s->S[s->top]=key;
    }
}

int pop(struct stack *s)
{   
    int x;
    if(s->top==-1)
        return -1;
    else
    {   
        x = s->S[s->top];
        s->top--;
    }
    return x;
}

int isEmpty(struct stack s)
{
    if(s.top==-1)
        return 1;
    return 0;
}

int isFull(struct stack s)
{
    if(s.top==s.size-1)
        return 1;
    return 0;
}

int main()
{   
    struct stack st;
    create(&st,5);
    
    for(int i=0;i<5;i++)
    {
        printf("Pushing %d to stack\n",i+1);
        push(&st,i+1);
    }

    printf("Stack is Full : %s\n",isFull(st)?"Yes":"NO");

    for(int i=0;i<5;i++)
        printf("Popped %d from top \n",pop(&st));

    printf("\nStack is Empty: %s",isEmpty(st)?"YES":"NO");
}