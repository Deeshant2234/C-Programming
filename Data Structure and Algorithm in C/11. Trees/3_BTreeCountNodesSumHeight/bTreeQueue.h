struct tnode
{
    struct tnode *lchild;
    int data;
    struct tnode *rchild;
};

struct qnode
{
    int size;
    int front;
    int rear;
    struct tnode **Q;   /* Pointer to a array of structure */
};

void qCreate(struct qnode *q, int size)
{
    q->size = size;
    q->front =q->rear = -1;
    q->Q = (struct tnode **)malloc(q->size * sizeof(struct tnode*));
}

void enqueue(struct qnode *q, struct tnode * x)
{
    if((q->rear+1)%q->size == q->front)
        return;    /* Queue is Full Circularly */
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    } 
}

struct tnode* dequeue(struct qnode *q)
{
    struct tnode *x = NULL;
    if(q->front == q->rear)
        return NULL;
    else
    {
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmptyQ(struct qnode q)
{
    if(q.front == q.rear)
        return 1;
    return 0;
}

