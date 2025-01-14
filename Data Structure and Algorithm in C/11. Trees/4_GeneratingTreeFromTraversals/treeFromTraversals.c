#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    struct tnode *lchild;
    int data;
    struct tnode *rchild;
};

int searchInorder(int *inOrder, int indexStart, int indexEnd, int data)
{
    for(int i = indexStart; i<=indexEnd;i++)
    {
        if(inOrder[i]== data)
            return i;
    }
    return -1;
}

struct tnode* treeFromTraversals(int *preOrder, int *inOrder, int indexStart, int indexEnd)
{
    static int preIndex = 0;
    
    if(indexStart>indexEnd) 
        return NULL;

    struct tnode *t = (struct tnode*)malloc(sizeof(struct tnode));
    t->data = preOrder[preIndex++];
    t->lchild = t->rchild = NULL;

    if(indexStart==indexEnd) 
        return t;

    int splitIndex = searchInorder(inOrder,indexStart,indexEnd,t->data);
    t->lchild = treeFromTraversals(preOrder,inOrder,indexStart,splitIndex-1);
    t->rchild = treeFromTraversals(preOrder,inOrder,splitIndex+1,indexEnd);
    
    return t;
}

void printPostOrder(struct tnode *p)
{
    if(p)
    {
        printPostOrder(p->lchild);
        printPostOrder(p->rchild);
        printf("%d ", p->data);
    }
}

int main()
{   
    /* We can generate BT using any 2 traversals given one of them is Inorder */
    int preOrder[] = {10,5,2,6,14,12,15};
    int inOrder[] =  {2,5,6,10,12,14,15};
    int lengthInorder = sizeof(inOrder)/sizeof(inOrder[0])-1;
    struct tnode *root = treeFromTraversals(preOrder,inOrder,0,lengthInorder);
    printf("Post Order Traversal of Generated Tree: ");
    printPostOrder(root);
}