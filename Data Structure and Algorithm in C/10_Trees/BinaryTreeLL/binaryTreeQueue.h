struct node
{
    struct node* lchild;
    int data;
    struct node* rchild;
};

struct queue
{
    int size;
    int front;
    int rear;
    struct node* *Q;
};

void createQueue( struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear=0;
    q->Q = (struct Node **)malloc(q->size*sizeof(struct Node *));
}

int isEmpty(struct queue q)
{
    return q.front==q.rear;
}

void enqueue(struct queue *q, struct node *x)
{
    if((q->rear+1)%q->size==q->front)
        printf("Queue is Full");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

struct node* dequeue(struct queue *q)
{   struct Node* x=NULL;
    if(q->front==q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}