#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create( struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size*sizeof(int));  
    // The result of malloc is a void*, which needs to be typecast
    // to int* because Q is a pointer to an integer.
}

int isEmpty(struct queue *q)
{
    if(q->front==q->rear)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if(q->rear==q->size-1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int x)
{
    if(q->rear==q->size-1)
        printf("Queue is full");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct queue *q)
{   int x;
    if(!isEmpty(q))
    {
        q->front++;
        x = q->Q[q->front];

    }
    else
    {   printf("Queue is Empty");
        return -1;
    }
    return x;
}

int main()
{
    struct queue q;
    create(&q,5);
    enqueue(&q,15);
    enqueue(&q,23);
    
    for(int i=q.front+1;i<=q.rear;i++)
        printf("%d\n",q.Q[i]);
    
    free(q.Q);

}