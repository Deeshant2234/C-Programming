struct tnode
{
    struct tnode *lchild;
    int data;
    struct tnode *rchild;
};  

struct qnode
{
    int size;
    int first;
    int last;
    struct tnode **Q;       // Pointer to a array of pointer to structure
}; 

void createQ(struct qnode *q, int size)
{
    q->size = size;
    q->first = q->last = -1;
    q->Q = (struct tnode **)malloc(q->size*sizeof(struct tnode *));
}

void enqueue(struct qnode *q, struct tnode *x)
{ 
    if((q->last+1)%q->size==q->first)
        printf("Queue is full");
    else
    {
        q->last=(q->last+1)%q->size;
        q->Q[q->last] = x;
    }
}

struct tnode* dequeue(struct qnode *q)
{
    struct tnode *x=NULL;
    if(q->first==q->last)
        printf("Queue is empty");
    else
    {
        q->first = (q->first+1)%q->size; 
        x = q->Q[q->first];
    } 
    return x;
}

int isEmpty(struct qnode q)
{
    if(q.first==q.last)
        return 1;
    return 0;
}

