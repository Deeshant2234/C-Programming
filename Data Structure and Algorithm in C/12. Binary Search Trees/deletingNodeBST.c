/* THREE CASES */
/* 1. Deleting Leaf Node - We can simply delete it */
/* 2. Deleting Other Node - InOrder Predecessor or Successor
                            will take its place. We do this to
                            avoid multiple modifications in the tree. 
                            However, if the InOrder Predecessor or 
                            Successor are not leaf nodes, then multiple 
                            modifications are still required */
#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    struct tnode *lchild;
    int data;
    struct tnode *rchild;
}*root=NULL;

void insert(int key)
{
    struct tnode *t = root;
    struct tnode *r, *p;

    // If the tree is empty, create a new root node
    if (!root)
    {
        root = (struct tnode *)malloc(sizeof(struct tnode));
        root->data = key;
        root->lchild = root->rchild = NULL;
        return;
    }

    // Traverse the tree to find the appropriate position for the new node
    while (t)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return; // Key already exists, do not insert duplicate
    }

    // Create a new node
    p = (struct tnode *)malloc(sizeof(struct tnode));
    p->data = key;
    p->lchild = p->rchild = NULL;

    // Insert the new node at the appropriate position
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

int heightTree(struct tnode *p)
{
    int x,y;
    if(!p)
        return 0;
    x = heightTree(p->lchild);
    y = heightTree(p->rchild);
    return x>y?x+1:y+1;    
}

struct tnode* inOrderPre(struct tnode *p)
{   
    /* Right-Most Child of Left Sub-Tree */
    while (p && p->rchild != NULL)
        p = p->rchild;
    return p;
}

struct tnode* inOrderSucc(struct tnode *p)
{
    /* Left-Most Child of Right Sub-Tree */
    while (p && p->lchild != NULL)
        p = p->lchild;
    return p;
}

struct tnode* deleteNode(struct tnode* p, int key)
{
    struct tnode *q;
    
    // If the node to be deleted is not found, return NULL
    if(!p)
        return NULL;
    
    // If the node to be deleted is a leaf node.
    if(p->lchild == NULL && p->rchild==NULL && key == p->data)
    {
        if(p==root)
            root = NULL;
        // Free the memory allocated to the node
        free(p);
        return NULL;
    }

    // If the key to be deleted is smaller than the current node's data, go to the left subtree
    if(key<p->data)
        p->lchild = deleteNode(p->lchild,key);
    // If the key to be deleted is greater than the current node's data, go to the right subtree
    else if(key>p->data)
        p->rchild = deleteNode(p->rchild,key);
    else
    {
        // If the left subtree is taller, find the in-order predecessor
        if(heightTree(p->lchild)>heightTree(p->rchild))
        {
            q = inOrderPre(p->lchild);
            // Replace the current node's data with the in-order predecessor's data
            p->data = q->data;
            // Delete the in-order predecessor
            p->lchild = deleteNode(p->lchild,q->data);
        }
        // If the right subtree is taller or they are of equal height, find the in-order successor
        else
        {
            q =  inOrderSucc(p->rchild);
            // Replace the current node's data with the in-order successor's data
            p->data = q->data;
            // Delete the in-order successor
            p->rchild = deleteNode(p->rchild,q->data);
        }       
    }
    // Return the current node
    return p;
}

void preOrder(struct tnode *p)
{
    if(p)
    {
        printf("%d ",p->data);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

int main()
{   
    insert(9);
    insert(15);
    insert(5);
    insert(20);
    insert(16);
    insert(8);
    insert(12);
    insert(3);
    insert(6);

    printf("\nInOrder Traversal: ");
    preOrder(root);

    printf("\nDeleting Key 9 \n.\n.\n.\n.");
    deleteNode(root,9);
    
    printf("\nInOrder Traversal After Deleting: ");
    preOrder(root);
    printf("\n ");
    
    return 0;
}