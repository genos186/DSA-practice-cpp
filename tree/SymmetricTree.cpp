#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}

bool isSymmetric(Node *root)
{
    if (!root)
        return true;

    return symmetry(root->left, root->right);
}

bool symmetry(Node *l, Node *r)
{
    if (!l && !r)
        return true;
    if (!l || !r)
        return false;

    return (l->val == r->val) && symmetry(l->right, r->left) && symmetry(l->left, r->right);
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(3);
    root->right->left = newNode(4);

    isSymmetric(root);

    return 0;
}

/*
                    1
                  / | \
                2   |   2
               / \  |  / \
              3   4 | 4   3
*/