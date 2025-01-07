#include <stdio.h>
#include <stdlib.h>
#include "bTreeQueueStack.h"

/** 
 * Example tree structure: 
 * 
 *         1
 *        / \
 *       2   3
 *      / \   \
 *     4   5   6
 * 
 */

struct tnode *root = NULL;

void tcreate()
{  
    int x;
    struct tnode *p,*t;

    /*Create Queue */
    struct qnode q;
    createQ(&q,10);
    
    /* Create Root */
    printf("Enter root value: ");
    scanf("%d",&x);
    root = (struct tnode*)malloc(sizeof(struct tnode));
    root->data = x;
    root->lchild = root->rchild = NULL;

    /* Insert Root in Queue */
    enqueue(&q,root);

    while(!isEmptyQ(q))
    {
        /* Remove node from Queue and assign left and right child */
        p = dequeue(&q);
        
        printf("Enter left child of %d: ",p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            t = (struct tnode*)malloc(sizeof(struct tnode));
            t->data = x;
            t->lchild = t->rchild =NULL;
            p->lchild = t;
            enqueue(&q,t);
        }

        printf("Enter right child of %d: ",p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            t = (struct tnode*)malloc(sizeof(struct tnode));
            t->data = x;
            t->lchild = t->rchild =NULL;
            p->rchild = t;
            enqueue(&q,t);
        }
    }
}

void iterPreorder(struct tnode *p)
{   
    struct stack st;
    createS(&st,10);

    while(p || !isEmptyS(st))
    {   if(p)
        {
            printf("%d ",p->data);
            push(&st,p);
            p = p->lchild;
        }
        else
        {
            p = pop(&st);
            p = p->rchild;
        }
    }
    printf("\n");
}

void iterInOrder(struct tnode *p)
{
    struct stack st;
    createS(&st,10);

    while(p||!isEmptyS(st))
    {
        if(p)
        {
            push(&st,p);
            p = p->lchild;
        }
        else
        {
            p = pop(&st);
            printf("%d ",p->data);
            p = p->rchild;
        }
    }
}

void iterPostOrder(struct tnode *p)
{
    struct stack st;
    long int temp;
    createS(&st,10);

    while(p||!isEmptyS(st))
    {
        if(p)
        {
            push(&st,p);
            p = p->lchild;
        }
        else
        {
            temp = (long int)pop(&st);
            if(temp>0)
            {
                push(&st,(struct tnode*)(-temp));
                p = ((struct tnode*)temp)->rchild;
            }
            else
            {
                printf("%d ",((struct tnode*)(-temp))->data);
                p = NULL;
            }
        }
    }
}

void iterLevelOrder(struct tnode *p)
{ 
    struct qnode q;
    createQ(&q,10);

    /* Print and Add root into Queue */
    printf("%d ",p->data);
    enqueue(&q,root);

    while(!isEmptyQ(q))
    {
        p = dequeue(&q);
        if(p->lchild)
        {
            printf("%d ",p->lchild->data);
            enqueue(&q,p->lchild);
        }
        if(p->rchild)
        {
            printf("%d ",p->rchild->data);
            enqueue(&q,p->rchild);
        }
    }
}

int main()
{
    tcreate();

    printf("----------------------------------------------------------- \n");
    printf("-----------Tree Display: PreOrder Traversal --------------- \n");
    iterPreorder(root);
    printf("----------------------------------------------------------- \n");
    printf("-----------Tree Display: InOrder Traversal ---------------- \n");
    iterInOrder(root);
    printf("----------------------------------------------------------- \n");
    printf("-----------Tree Display: PostOrder Traversal -------------- \n");
    iterPostOrder(root);
    printf("----------------------------------------------------------- \n");
    printf("-----------Tree Display: LevelOrder Traversal ------------- \n");
    iterLevelOrder(root);
    printf("----------------------------------------------------------- \n");
    return 0;
}