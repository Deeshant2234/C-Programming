/* For Binary Search Tree Inorder Traversal is not required for 
generating BST because we know Inorder traversal of BST is sorted
array so we can generate that array ourself */

#include <stdio.h>
#include <stdlib.h>
#include "binarySTreeUsingStack.h"

struct tnode *root =NULL;

void createBST(int pre[],int n)
{
    int i = 0;
    struct tnode * t ,*p;

    /* Create Stack */
    struct stack st;
    createS(&st,10);

    /* Create Root Node */
    root = (struct tnode*)malloc(sizeof(struct tnode));
    root->data = pre[i++];
    root->lchild = root->rchild = NULL;
    p = root;

    while(i<n)
    {
        if(pre[i]<p->data)
        {
            t = (struct tnode*)malloc(sizeof(struct tnode));
            t->data = pre[i++];
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            push(&st,p);
            p = t;
        }
        else
        {
            if (pre[i] > p->data && pre[i] < (isEmptyS(st) ? INT_MAX : st.S[st.top]->data))
            {
                t = (struct tnode*)malloc(sizeof(struct tnode));
                t->data = pre[i++];
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                p = t;
            }
            else
            {   
                p = pop(&st);
            }
        }
    }

}

void preOrder(struct tnode *p)
{
    if(p)
    {
        printf("%d ", p->data);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

int main()
{
    int arr[] = {30,20,10,15,25,40,50,45};
    createBST(arr,sizeof(arr)/sizeof(arr[0]));
    preOrder(root);
}