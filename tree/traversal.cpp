// tree traversal using stacks in preorder, inorder and postorder
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

void traversal(Tnode *root)
{
    stack<pair<Tnode*,int>> s;
    vector<int> in;
    vector<int> pre;
    vector<int> post;

    s.push(make_pair(root,1));
    
    while( !s.empty() )
    {
        pair<Tnode*,int> p=s.top();

        if( p.second == 1 )
        {
            s.top().second++;
            pre.push_back(p.first->data);

            if( p.first->left )
            {
                s.push(make_pair(p.first->left,1));
            }
        }

        else if( p.second == 2 )
        {
            s.top().second++;
            in.push_back(p.first->data);

            if( p.first->right )
            {
                s.push(make_pair(p.first->right,1));
            }
        }
        
        else
        {
            post.push_back(p.first->data);
            s.pop();
        }
    }

    // printing preorder, inorder and postorder paths of a tree
    // preorder
    for(int i=0;i<pre.size();i++)
    {
        cout<<pre[i]<<" ";
    }
    cout<<endl;

    // inorder
    for(int j=0;j<in.size();j++)
    {
        cout<<in[j]<<" ";
    }
    cout<<endl;

    // postorder
    for(int k=0;k<post.size();k++)
    {
        cout<<post[k]<<" ";
    }
    cout<<endl;
}

int main()
{
    struct Tnode* root = new Tnode(1);
    root->left = new Tnode(2);
    root->right = new Tnode(3);
    root->left->left = new Tnode(4);
    root->left->right = new Tnode(5);
    root->right->left = new Tnode(6);
    root->right->right = new Tnode(7);

    traversal(root);

    return 0;
}

void Inorder(Tnode *root)
{
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Preorder(Tnode *root)
{
    Preorder(root->left);
    Preorder(root->right);
    cout<<root->data<<" ";
}

void Postorder(Tnode *root)
{
    cout<<root->data<<" ";
    Postorder(root->left);
    Postorder(root->right);
}