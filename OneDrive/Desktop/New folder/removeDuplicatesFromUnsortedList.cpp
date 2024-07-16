#include <bits/stdc++.h>
using namespace std;

Node *removeDuplicates(Node *head)
{
    if (head == NULL && head->next == NULL)
        return head;
    Node *temp = head;
    Node *prev = NULL;
    map<int, bool> duplicate;
    while (temp != NULL)
    {
        int element = temp->data;
        if (duplicate[element] == true)
        {
            Node *next_next = temp->next;
            delete (temp);
            prev->next = next_next;
            temp = next_next;
        }
        else
        {
            duplicate[element] = true;
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Note: We made dummy node and attachec to the current head and start removing nodes and dry run it.
*/

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *temp = new ListNode(0);
    temp->next = head;
    ListNode *curr = temp;

    while (curr->next && curr->next->next)
    {
        if (curr->next->val == curr->next->next->val)
        {
            int variable = curr->next->val;
            while (curr->next != NULL && curr->next->val == variable)
            {
                curr->next = curr->next->next;
            }
        }
        else
        {
            curr = curr->next;
        }
    }
    return temp->next;
}