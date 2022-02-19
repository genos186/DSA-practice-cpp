#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
};

Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
// converting into a mirror view of the original tree
void mirror(Node *root)
{
    if( root==NULL )
        return;

    queue<Node *> q;
    q.push(root);

    while( !q.empty() )
    {
        Node *temp=q.front();
        q.pop();

        swap( temp->left,temp->right );

        if( temp->left )
            q.push(temp->left);
        if( temp->right )
            q.push(temp->right);
    }
}

int main()
{
    Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);
 
    mirror(root);
}