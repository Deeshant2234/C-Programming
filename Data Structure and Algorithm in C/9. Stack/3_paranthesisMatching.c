#include <stdio.h>
#include <stdlib.h>

/* Stack using Linked List */

struct node
{
    char data;
    struct node* next; 

}*first=NULL;

void push(char c)
{   
    struct node* t;
    t = (struct node*)malloc(sizeof(struct node)); 
    t->data = c;
    t->next = NULL;

    if(t==NULL)
        return; // Stack is Full
    else
    {
        t->next = first; 
        first = t;
    }
}

void pop()
{
    struct node *t;
    if(first==NULL)
        return;
    else
    {
        t  = first;
        first = first->next;
        free(t);
    }
}

void isBalanced(char *arr)
{
    int i=0;
    int balanced = 1;
    while(arr[i]!='\0' && balanced)
    {
        if(arr[i]=='(')
            push(arr[i]);
        else if(arr[i] == ')')
        {
            if(first == NULL) // More closing brackets than opening
            {
                balanced = 0;
            }
            else
                pop();
        }
        i++;
    }
    if(balanced && first==NULL)
        printf("Expression is Balanced");
    else  
        printf("Expression is not Balanced");
}

int main()
{
    char arr[] = "((a+b)+(a-b))";
    int size  = sizeof(arr)/sizeof(arr[0]);
    printf("Size of Expression: %d\n",size);
    isBalanced(arr);
    
    return 0;
}