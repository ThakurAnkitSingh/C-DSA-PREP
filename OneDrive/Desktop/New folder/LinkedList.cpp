#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // 
    // Destructor for memory free
    ~Node(){
        int value = this->data;
        // memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "Erased or deleted of value from the memory : " << value << endl;
    }
};

void insertAtHead(Node *&head, int data)
{
    // Create New Node
    Node *temp = new Node(data);
    // temp next address should be head like first value ka head ka address
    temp->next = head;
    // Head address also changed
    head = temp;
}

void printLinkedList(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << "Node Value : " << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtMiddle(Node* &tail, Node* &head, int idx, int data){
    Node* nodeToInsert = new Node(data);
    Node* temp = head;
    // Inserting at first position
    if(idx == 1){
        insertAtHead(head, data);
        return;
    }
    int count = 1;
    while(count < idx-1){
        temp = temp->next;
        count++;
    }
    // Insertung at tail or last position
    if(temp->next == NULL){
        insertAtTail(tail, data);
        return;
    }
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}



void deleteAtPostion(Node* &tail, Node* &head, int postion){
    if(postion == 1){
        // deletion at First or head node
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        if(head == NULL){
            tail = NULL;
        }
    }else{
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while(count < postion){
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        if(curr->next == NULL){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}



int main()
{

    // Heap Created a new Node
    Node *node1 = new Node(10);

    // cout << node1->data << endl;
    // cout << node1->next << endl;

    Node *head = node1;
    // printLinkedList(head);

    // insertAtHead(head, 12);
    // insertAtHead(head, 14);
    // insertAtHead(head, 16);
    // printLinkedList(head);

    Node *tail = node1;
    // printLinkedList(tail);

    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    insertAtTail(tail, 22);
    // printLinkedList(head);

    // insertAtMiddle(tail, head, 2, 11);
    printLinkedList(head);
    cout << "Head : " << head << endl;
    cout << "Tail : " << tail << endl;

    // Deletion at any position
    deleteAtPostion(tail, head, 4);
    printLinkedList(head);
    cout << "Head : " << head << endl;
    cout << "Tail : " << tail << endl;

    delete head;
}