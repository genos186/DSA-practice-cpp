#include<bits/stdc++.h>
using namespace std;

class StackNode
{
    public:
        int data;
        StackNode *next;
};

StackNode *NewNode(int info)
{
    StackNode *node=new StackNode();
    node->data=info;
    node->next=NULL;
    return node;
}

int isEmpty(StackNode *root)
{
    return !root;
}

void push( StackNode **root,int data )
{
    StackNode *node=NewNode(data);
    if( isEmpty(*root) )
    {
        *root=node;
        return;
    }
    node->next = *root;
    *root=node;
}

int pop( StackNode **root )
{
    if( isEmpty(*root) )
    {
        return INT_MIN;
    }
    StackNode *temp= *root;
    *root= (*root)->next;
    int pop_ele=temp->data;
    free(temp);
    return pop_ele;
}

int peek( StackNode *root )
{
    if( isEmpty(root) )
    {
        return INT_MIN;
    }
    return root->data;
}