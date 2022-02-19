#include<bits/stdc++.h>
using namespace std;

struct Tnode
{
    int data;
    struct Tnode *left;
    struct Tnode *right;
    bool rThread;
    bool lThread;
};

struct Tnode *insert( struct Tnode *root,int val )
{
    struct Tnode *temp=root;
    struct Tnode *parent=NULL;
    //checking for existence of node with same value
    while( temp!=NULL )
    {
        if( val==temp->data )
        {
            cout<<"Duplicate";
            return root;
        }
        parent=temp;

        if( val<temp->data )
        {
            if( temp->lThread==false )
                temp=temp->left;
            
            else
                break;
        }
        else
        {
            if( temp->rThread==false )
                temp=temp->right;
            
            else    
                break;
        }
    }
    //there are 3 possibilities
    Tnode *node=new Tnode;
    node->data=val;
    node->rThread=true;
    node->rThread=true;

    //1:no root, tree doesn't exist
    if( parent==NULL )
    {
        root=node;
        node->left=NULL;
        node->right=NULL;
    }
    //2:new node to be inserted as left child, as the parent is greater than the child
    else if( val<parent->data )
    {
        node->left=parent->left;
        node->right=parent;
        parent->lThread=false;
        parent->left=node;
    }
    //3:new node to be inserted as right child, as the parent is lesser than the child
    else
    {
        node->left=parent;
        node->right=parent->right;
        parent->rThread=false;
        parent->right=node;
    }

    return root;
}

struct Tnode *inorderSuccessor(struct Tnode *ptr)
{
    // If rthread is set, we can quickly find
    if (ptr -> rThread == true)
        return ptr->right;
 
    // Else return leftmost child of right subtree
    ptr = ptr -> right;
    while (ptr -> lThread == false)
        ptr = ptr -> left;
    return ptr;
}
 
// Printing the threaded tree
void inorder(struct Tnode *root)
{
    if (root == NULL)
        cout<<"Tree is empty";
 
    // Reach leftmost node
    struct Tnode *ptr = root;
    while (ptr -> lThread == false)
        ptr = ptr -> left;
 
    // One by one print successors
    while (ptr != NULL)
    {
        cout<<ptr->data;
        ptr = inorderSuccessor(ptr);
    }
}

int main()
{
    struct Tnode *root=NULL;
    root=insert(root,20);
    root=insert(root,10);
    root=insert(root,30);
    root=insert(root,5);
    root=insert(root,16);
    root=insert(root,14);
    root=insert(root,17);
    root=insert(root,13);
    root=insert(root,15);

    inorder(root);
    return 0;
}