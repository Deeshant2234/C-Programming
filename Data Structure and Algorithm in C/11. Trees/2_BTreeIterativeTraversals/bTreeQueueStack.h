struct tnode
{
    struct tnode *lchild;
    int data;
    struct tnode *rchild;
};

/*----------------------------------QUEUE FOR TREES-----------------------------------*/
struct qnode
{
    int size;
    int front;
    int rear;
    struct tnode **Q ;  // Array of pointers to tree nodes 
};

void createQ(struct qnode *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (struct tnode **)malloc(q->size*sizeof(struct tnode*));
}

void enqueue(struct qnode *q, struct tnode *t)
{
    /* Before adding check if Queue is not circularly full*/
    if((q->rear+1)%q->size==q->front)
        return;
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = t;
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
    if(q.rear==q.front)
        return 1;
    return 0;
} 


/*----------------------------------STACK FOR TREES-----------------------------------*/

/* Stack Data Structure is required for Iterative Traversal of a Tree */

struct stack
{
    int size;
    int top;
    struct tnode **S;   //Array of pointer to tree nodes
};

void createS(struct stack *st, int size)
{
    st->size  = size;
    st->top = -1;
    st->S = (struct tnode **)malloc(st->size*sizeof(struct tnode*));
}

void push(struct stack *st, struct tnode *x)
{   
    if(st->top == st->size-1)
        return;                 // Stack is full
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

struct tnode* pop(struct stack *st)
{
    struct tnode *x=NULL;
    if(st->top==-1)
        return NULL;
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int isEmptyS(struct stack st)
{
    if(st.top==-1)
        return 1;
    return 0;
}
