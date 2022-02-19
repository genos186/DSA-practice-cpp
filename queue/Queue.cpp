#include<bits/stdc++.h>
using namespace std;

//node creation for the queue
struct QNode {
    int data;
    QNode *next;
    QNode (int d)
    {
        data=d;
        next=NULL;
    }
};

struct Queue {
    QNode *front,*rear;     //front and rear pointers for the queue

    Queue()
    {
        front=rear=NULL;
    }
    //Data insertion and node creation to the queue
    void EnQueue(int x)
    {
        QNode *temp=new QNode(x);

        if( rear==NULL )
        {
            front=rear=temp;
            //front=rear;
            return;
        }

        rear->next=temp;
        rear=temp;
    }
    //Data and node deletion from the queue
    void DeQueue()
    {
        if( front==NULL )
        {
            cout<<"Empty Queue\n";
            return;
        }

        QNode *temp=front;
        front=front->next;

        if( front==NULL )
            rear=NULL;

        delete( temp );
    }
    //printing queue
    void PrintQueue()
    {
        QNode *temp=front;
        while( temp!=rear->next )
        {
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
        cout<<endl;
    }

};

int main()
{
    Queue q;
    q.EnQueue(10);
    q.EnQueue(20);
    q.EnQueue(30);
    q.EnQueue(40);
    q.EnQueue(50);
    q.PrintQueue();
    q.DeQueue();
    q.PrintQueue();
    q.DeQueue();
    q.DeQueue();
    q.PrintQueue();
    return 0;
}