#include <stdio.h>
#include <stdlib.h>
#include "binaryTreeQueue.h"

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

struct tnode *root=NULL;

void createTree()
{
    struct tnode *p,*t;
    int x;

    /* Create Queue */
    struct qnode q;
    createQ(&q,10);

    /* Create Root Node */
    printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct tnode *)malloc(sizeof(struct tnode));
    root->data = x;
    root->lchild = root->rchild = NULL;
    
    /* Insert Root in Queue */
    enqueue(&q,root); 

    while(!isEmpty(q))
    {   
        p = dequeue(&q);         // dequeue will return a pointer to tnode
        
        printf("enter left child of %d: ",p->data);
        scanf("%d", &x);
        if(x!=-1)
        {
          t = (struct tnode*)malloc(sizeof(struct tnode));
          t->data = x;
          t->lchild = t->rchild = NULL;
          p->lchild = t;
          enqueue(&q,t);
        }
        
        printf("enter right child of %d: ",p->data);
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

void preorderTraversal(struct tnode *p)
{ 
    if(p)
    {
        printf("Data %d\n", p->data);
        preorderTraversal(p->lchild);
        // printf("Data %d\n", p->data);  // Inorder Traversal
        preorderTraversal(p->rchild);
        // printf("Data %d\n", p->data);  // PostOrder Traversal
    }
}

int main()
{   
    createTree();
    printf("--------------------------------------------------------- \n");
    printf("-----------Tree Display: PreOrder Traversal ------------- \n");
    preorderTraversal(root);
    return 0;
}

