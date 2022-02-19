#include<bits/stdc++.h>
using namespace std;

struct tree
{
    int data;
    tree *left;
    tree *right;

    tree (int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};



int main()
{
    tree *root=new tree(1);
    root->left=new tree(2);
    root->right=new tree(3);
    root->left->left=new tree(4);
    return 0;
}