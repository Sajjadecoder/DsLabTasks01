#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
    void insertAtTail(Node *&head, int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    int getListLength(Node *&head)
    {
        Node *temp = head;
        int cnt = 0;
        while (temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    void print(Node *&head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    Node *reverseLL(Node *&reverseNodeHead)
    {
        Node *temp = reverseNodeHead;
        Node *prev = NULL;
        while (temp != NULL)
        {
            Node *forwardNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = forwardNode;
        }
        reverseNodeHead= prev;
        return reverseNodeHead;
    }
    void appendingFromList(Node *&head)
    {
        int listSize = getListLength(head);
        if (listSize== 0)
        {
            cout << "List is Empty\n";
            return;
        }
        listSize/= 2;
        Node *temp = head->next;
        Node *prev = head;
        int swapCount = 0;
        while (swapCount != listSize && temp != NULL)
        {
            insertAtTail(head, temp->data);
            prev->next = temp->next;
            prev = temp->next;
            delete temp;
            temp = prev->next;
            swapCount++;
        }
        temp = head;
        int iterate = 1;
        while (iterate != listSize)
        {
            temp = temp->next;
            iterate++;
        }
        temp->next = reverseLL(temp->next);
    }
};
int main()
{
    Node *list = NULL;
    Node *head = list;
    list->insertAtTail(head, 10);
    list->insertAtTail(head, 4);
    list->insertAtTail(head, 9);
    list->insertAtTail(head, 1);
    list->insertAtTail(head, 3);
    list->insertAtTail(head, 5);
    list->insertAtTail(head, 9);
    list->insertAtTail(head, 4);
    cout << "Before appending and reversing alternate nodes\n";
    list->print(head);
    list->appendingFromList(head);
    cout << "After appending and reversing alternate nodes\n";
    list->print(head);

    return 0;
}