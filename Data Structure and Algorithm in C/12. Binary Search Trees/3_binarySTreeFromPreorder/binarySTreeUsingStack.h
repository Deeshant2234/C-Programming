struct tnode
{
    struct tnode *lchild;
    int data;
    struct tnode *rchild;
};

struct stack
{
    int size;
    int top;
    struct tnode **S;
};

void createS(struct stack *st,int size)
{
    st->size = size;
    st->top = -1;
    st->S = (struct tnode **)malloc(st->size*sizeof(struct tnode*));
}

void push(struct stack *st, struct tnode *p)
{
    if(st->top==st->size-1)
        return;
    else
    {
        st->top++;
        st->S[st->top]=p;
    }
}

struct tnode* pop(struct stack *st)
{   
    struct tnode *p;
    if(st->top==-1)
        return NULL;
    else
    {
        p=st->S[st->top--];
    }
    return p;
}

int isEmptyS(struct stack st)
{
    if(st.top==-1)
        return 1;
    return 0;
}