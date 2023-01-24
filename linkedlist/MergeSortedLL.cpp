#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode d(INT_MIN);
    ListNode *Node = &d;

    while (list1 && list2)
    {
        if (list1->val > list2->val)
        {
            Node->next = list2;
            list2 = list2->next;
        }
        else
        {
            Node->next = list1;
            list1 = list1->next;
        }
        Node = Node->next;
    }
    Node->next = list1 ? list1 : list2;
    return d.next;
}