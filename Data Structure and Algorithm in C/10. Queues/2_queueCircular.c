#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void ccreate(struct queue* q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int*)malloc(q->size*sizeof(int));
}

void cenqueue(struct queue* q, int x)
{
    if((q->rear+1)%q->size==q->front)   //circularly next == front
    {
        printf("Queue is Full");
    }
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}

int cdequeue(struct queue* q)
{
    int x = -1;
    if(q->front == q-> rear)
    {
        printf("Queue is Empty");
    }
    else
    {
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct queue* q)
{
    if(q->front == q->rear)
        return 1;
    return 0;
}

int isFull(struct queue* q)
{
    if((q->rear+1)%q->size == q->front)
        return 1;
    return 0;
}

int main()
{
    struct queue q;
    ccreate(&q,5);
    cenqueue(&q,15);
    cenqueue(&q,23);
    cenqueue(&q,50);
    cdequeue(&q);
    
    for(int i=q.front+1;i<=q.rear;i++)
        printf("%d\n",q.Q[i]);
    free(q.Q);  
    return 0;
}