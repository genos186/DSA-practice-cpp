#include<bits/stdc++.h>
using namespace std;

Node *merge(Node *firstNode,Node *secondNode) {
    Node *merged = new Node;
    Node *temp = new Node;
    
    //merged is equal to temp so in the end we have the top Node.
    merged = temp;
 
    //while either firstNode or secondNode becomes NULL
    while(firstNode != NULL && secondNode != NULL) {
     
        if(firstNode->data<=secondNode->data) {
            temp->next = firstNode;
            firstNode = firstNode->next;
        }
         
        else {
            temp->next = secondNode;
            secondNode = secondNode->next;
        }
        temp = temp->next;
    }
    
   //any remaining Node in firstNode or secondNode gets inserted in the temp List
    while(firstNode!=NULL) {
        temp->next = firstNode;
        firstNode = firstNode->next;
        temp = temp->next;
    }
 
    while(secondNode!=NULL) {
        temp->next = secondNode;
        secondNode = secondNode->next;
        temp = temp->next;
    }
    //return the head of the sorted list
    return merged->next;
}

Node *middle(Node *head) {
    Node *middle = head;
    Node *end = head->next;
    
    while(middle->next != NULL && (end!=NULL && end->next!=NULL)) {
        middle = middle->next;
        end = end->next->next;
    }
    return middle;
}