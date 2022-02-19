#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 



vector<int> inOrder(Node* root)
{
    Node *temp=root;
    stack<Node *> s;
    vector<int> result;
    
    while( temp!=NULL || s.empty()==false )
    {
        while( temp!=NULL )
        {
            s.push(temp);    
            temp=temp->left;
        }
        temp=s.top();
        s.pop();
        int res=temp->data;
        result.push_back(res);
        temp=temp->right;
    }
    return result;
}

int main()
{
    struct Node *root=new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    vector<int> res=inOrder(root);

    for(int i=0;i<res.size();i++)
    {
        cout<<res.at(i)<<" ";
    }
    cout<<endl;
}