#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int val){
        data = val;
        left = NULL;
	    right = NULL;
    }
};


int height(Node *node)
{
    if( node==NULL )
        return 0;
        
    else
    {
        int lheight=height(node->left);
        int rheight=height(node->right);
        
        if( lheight>rheight )
            return (lheight+1);
        if( rheight>lheight )
            return (rheight+1);
    }
}
    
    
vector<int> levelOrder(Node* node)
{
    queue<Node*> q;
    vector<int> res;
    
    q.push(node);
    
    while( !q.empty() )
    {
        Node *temp=q.front();
        res.push_back(temp->data);
        q.pop();
        
        if( temp->left!=NULL )
        {
            q.push(temp->left);
        }
        if( temp->right!=NULL )
        {
            q.push(temp->right);
        }
    }

    //height of the tree
    int h=height(node); 
    //total number of nodes for a perfect binary tree
    int Tnode=(pow(2,h))-1; 
    //if not binary tree, print remaining elements to complete binary tree as null
    if( res.size()<Tnode )
    {
        int counter=Tnode-res.size();
        for(int i=0;i<counter;i++)
        {
            res.push_back(NULL);
        }
    }
        
    return res;
}

    Node *InsertNode(Node *root,int val)
    {
	if( root==NULL )
	{	
	    root=new Node(val);
	    return root;
	}

	queue<Node*> q;
	q.push(root);

	while( !q.empty() )
	{
		Node *temp=q.front();
		q.pop();
		
		if( temp->left!=NULL )
			q.push(temp->left);
		else
		{
			temp->left=new Node(val);
			return root;
		}

		if( temp->right!=NULL )
			q.push(temp->right);
		else
		{
			temp->right=new Node(val);
			return root;
		}
	}
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
    
    vector<int> res=levelOrder(root);

    for(int i=0;i<res.size();i++)
    {
        cout<<res.at(i)<<" ";
    }
    cout<<endl;
    //cout<<res.capacity() <<endl;

    return 0;
}