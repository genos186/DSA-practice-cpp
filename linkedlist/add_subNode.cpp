#include <iostream>
using namespace std;

struct node {
 
    int key;
    node* next;
 
    node(int n)
    {
        key = n;
        next = NULL;
    }
};

class LinkedList {
 
    node* head;
 
public:
    LinkedList();
    void insert(node* n);
    void addDigit(int n);
    void subDigit(int n);
    void remove();
    void printList();
    void reverse();
};
 
LinkedList::LinkedList()
{
    head = NULL;
}

void LinkedList::remove()
{
    node *temp=head;
    node *prev=NULL;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    delete temp;
}

void LinkedList::insert(node* n)
{
    if (head == NULL)
        head = n;

    else {
        n->next = head;
        head = n;
    }
}

void LinkedList::reverse()
{
    node *temp=head;
    node *prev=NULL;
    node *next;

    while( temp!=NULL )
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
}

void LinkedList::printList()
{
    node* ptr = head;
 
    while (ptr) {
        cout << ptr->key << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

void LinkedList::addDigit(int n)
{
    node *temp=head;
    node *lnode=NULL;

    while( temp->next!=NULL )
    {
        if( temp->key<9 )
        {
            lnode=temp;
        }
        temp=temp->next;
    }
    
    temp->key=temp->key + n;

    if( temp->key>9 )
    {
        temp->key=temp->key%10;

        if( lnode==NULL )
        {
            insert(new node(1));
        }
        lnode=head->next;
    }

    while( lnode!=temp )
    {
        lnode->key=(lnode->key+1)%10;
        lnode=lnode->next;
    }
}



void LinkedList::subDigit(int n)
{
    reverse();
    node *temp=head;
    node *fnode=NULL;

    int borrow=0;

    temp->key=temp->key-n;
    if( temp->key<0 )
    {
        temp=temp->next;
        while( temp!=NULL )
        {
            if( temp->key<1 )
        }
    }

}

int main()
{
    LinkedList* l1 = new LinkedList();

    l1->insert(new node(9));
    l1->insert(new node(8));
    l1->insert(new node(9));

    l1->printList();

    l1->addDigit(5);

    l1->printList();

    l1->subDigit(5);

    l1->printList();
 
    return 0;
}