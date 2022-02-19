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

struct Tnode *Search(Tnode *root,int key)
{
    if( root==NULL || root->data==key )
    {
        return root;
    }
    if( root->data>key )
    {
        return Search(root->left,key);
    }
    return Search(root->right,key);
}
/*
function to find the kth smallest element
Node* kthSmallest(Node* root, int k)
{
    // base case
    if (root == NULL)
        return NULL;
 
    int count = root->lCount + 1;
    if (count == k)
        return root;
 
    if (count > k)
        return kthSmallest(root->left, k);
 
    // else search in right subtree
    return kthSmallest(root->right, k - count);
}
*/
int main()
{
    struct Tnode *root=new Tnode(1);
    root->left = new Tnode(2);
    root->right = new Tnode(3);
    root->left->left = new Tnode(4);
    root->left->right = new Tnode(5);
    root->right->left = new Tnode(6);
    root->right->right = new Tnode(7);
    
    Search(root,6);
    return 0;
}