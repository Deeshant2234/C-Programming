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

#include <stdio.h>
#include <stdlib.h>
#include "bTreeQueue.h"

struct tnode *root = NULL;

void createTree()
{    
    struct tnode *p,*t;
    int x;
    /* Create Queue */
    struct qnode q;
    qCreate(&q,10);

    printf("Enter Root Node of the Tree: ");
    scanf("%d", &x);
    root = (struct tnode*)malloc(sizeof(struct tnode));
    root->data = x;
    root->lchild = root->rchild = NULL;

    enqueue(&q,root);
    
    while(!isEmptyQ(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d:",p->data);
        scanf("%d", &x);
        if(x!=-1)
        {   
            t = (struct tnode*)malloc(sizeof(struct tnode));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q,t);
        }

        printf("Enter right child of %d:",p->data);
        scanf("%d", &x);
        if(x!=-1)
        {   
            t = (struct tnode*)malloc(sizeof(struct tnode));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q,t);
        }
    }

}

int countNodes(struct tnode *p)
{
    int x,y;
    if(p)
    {
        x = countNodes(p->lchild);
        y = countNodes(p->rchild);
        return x+y+1;
    }
    return 0;
}

int addNodes(struct tnode *p)
{
    int x,y;
    if(p)
    {
        x = addNodes(p->lchild);
        y = addNodes(p->rchild);
        return x+y+p->data;
    }
    return 0;
}

int heightTree(struct tnode *p)
{   
    int x,y;
    if(p)
    {   
        x = heightTree(p->lchild);
        y = heightTree(p->rchild);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}

int main()
{   
    createTree();

    // printf("root->lchild: %d , root->rchild: %d", root->lchild->data, root->rchild->data);
    
    printf("Number of Nodes: %d\n", countNodes(root));
    
    printf("Sum of Nodes: %d\n", addNodes(root));

    printf("Height of Binary Tree: %d\n", heightTree(root));

    return 0;
}

/**
 * Binary tree of height 1:
 * 
 *     1
 * 
 * Binary tree of height 2:
 * 
 *     1
 *    / \
 *   2   3
 * 
 * Binary tree of height 3:
 * 
 *         1
 *        / \
 *       2   3
 *      / \   \
 *     4   5   6
 */
