#include<bits/stdc++.h>
using namespace std;

struct Tnode
{
    int data;
    Tnode *left;
    Tnode *right;

    Tnode (int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

void LevelOrder( Tnode *root )
{
    if( root==NULL )
        return;

    queue<Tnode*> q;
    q.push(root);

    while( !q.empty() )
    {
        Tnode *temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        
        if( temp->left!=NULL )
            q.push(temp->left);
        
        if( temp->right!=NULL )
            q.push(temp->right);
    }
}

int main()
{
    struct Tnode *root=new Tnode(1);
    root->left = new Tnode(2);
    root->right = new Tnode(3);
    root->left->left = new Tnode(4);
    root->left->right = new Tnode(5);
    root->right->left = new Tnode(6);
    root->right->right = new Tnode(7);
    
    LevelOrder(root);

    return 0;
}