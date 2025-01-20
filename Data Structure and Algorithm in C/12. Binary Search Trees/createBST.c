#include <stdio.h>
#include <stdlib.h>

struct tnode 
{
    struct tnode *lchild;
    int data;
    struct tnode *rchild;
}*root = NULL;

void createBST(int *a, int size)
{   
    /* t pointer is for traversing */
    struct tnode *t;  
    struct tnode *r, *p;

    /* Create root node */
    root = (struct tnode*)malloc(sizeof(struct tnode));
    root->data = a[0];
    root->lchild = root->rchild = NULL;
    t = root;

    /* Repeating Procedure */
    /* Iterate over the array to insert elements into the BST */
    for(int i = 1; i < size; i++)
    {
        while(t != NULL)
        {   /* Move Tailing Pointer 'r' to t */
            r = t;   
            if(a[i] < t->data)
                t = t->lchild;
            else if(a[i] > t->data)
                t = t->rchild;
            else
                return; // Element already exists in the BST
        }

        /* Create a new node */
        p = (struct tnode*)malloc(sizeof(struct tnode));
        p->data = a[i];
        p->lchild = p->rchild = NULL;

        /* Attach the new node to the appropriate parent node */
        if(a[i] < r->data)
            r->lchild = p;
        else
            r->rchild = p;

        /* Move traverse pointer again back to root */
        t = root;
    }
}

void insert(int key)
{   
    /* t pointer is for traversing */
    struct tnode *t= root;  
    struct tnode *r, *p;
    
    /* root == NULL */
    if(!root)
    {
        /* Create root node */
        root = (struct tnode*)malloc(sizeof(struct tnode));
        root->data = key;
        root->lchild = root->rchild = NULL;
        return;
    }

    while(t != NULL)
    {   /* Move Tailing Pointer 'r' to t */
        r = t;   
        if(key < t->data)
            t = t->lchild;
        else if(key > t->data)
            t = t->rchild;
        else
            return; // Element already exists in the BST
    }

    /* Create a new node */
    p = (struct tnode*)malloc(sizeof(struct tnode));
    p->data = key;
    p->lchild = p->rchild = NULL;

    /* Attach the new node to the appropriate parent node */
    if(key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
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
    int arr[] = {9,15,5,20,16,8,12,3,6};
    printf("CREATING BINARY SEARCH TREE BY PASSING ARRAY TO FUNC:\n");
    createBST(arr,sizeof(arr)/sizeof(arr[0]));
    preOrder(root);
    
    /* CREATING BINARY SEARCH TREE USING INSERT FUNCTION */
    printf("\nCREATING BINARY SEARCH TREE USING INSERT FUNCTION:\n");
    insert(9);
    insert(15);
    insert(5);
    insert(20);
    insert(16);
    insert(8);
    insert(12);
    insert(3);
    insert(6);
    preOrder(root);
}