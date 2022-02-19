#include<bits/stdc++.h>
using namespace std;

class nlist
{
    public:
        int data;
        nlist *next;
};

nlist *NewNode(int info)
{
    nlist *node=new nlist();
    node->data=info;
    node->next=NULL;
    return node;
}

void push(nlist **head,int info)
{
    nlist *node=NewNode(info);
    
    if( *head==NULL )
    {
        *head=node; 
        return;
    } 

    else
    {
        node->next=*head;
        *head=node;
        return;
    }
}

void append(nlist **head,int info)
{
    nlist *node=NewNode(info);
    nlist *last=*head;

    if( *head==NULL )
    {
        *head=node;
        return;
    }

    while( last->next!=NULL )
    {
        last=last->next;
    }
    last->next=node;
    return;
}

void insert_after(nlist *prev,int info)
{
    nlist *node=NewNode(info);

    if( prev->next==NULL )
    {
        cout<<"can't input as no successor element\n";
        return;
    }
    node->next=prev->next;
    prev->next=node;
}

void delete_node(nlist **head,int key)
{
    nlist *node=*head;
    nlist *prev=NULL;

    if( node!=NULL && node->data==key )
    {
        *head=node->next;
        delete node;
        return;
    }

    else
    {
        while( node!=NULL && node->data!=key )
        {
            prev=node;
            node=node->next;
        }
        
        if( node==NULL )
            return;
        prev->next=node->next;
        delete node;
    }
}

void print_list(nlist *node)
{
    cout<<node->data;
    node=node->next;
    while(node!=NULL)
    {
        cout<<"->"<<node->data;
        node=node->next;
    }
    cout<<endl;
}

int main()
{
    nlist *head=NULL;
    push(&head,8);
    append(&head,10);
    push(&head,7);
    insert_after(head->next,9);
    push(&head,6);
    print_list(head);
    delete_node(&head,7);
    print_list(head);
    return 0;
}