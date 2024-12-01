#include <iostream>
using namespace std;

class Node

{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}

    void print(Node *&head)
    {
        if (head == NULL)
        {
            cout << "List Is Empty\n";
        }
        Node *temp = head;
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    void insertAtEnd(Node *&head, int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
    }
    void swapNodes(Node *&head, int key1, int key2)
    {
        if (key1 == key2 || (key1 < 0 || key2 < 0))
        {
            return;
        }

        Node *node1 = head;
        Node *node2 = head;
        for (int i = 0; i < key1; i++)
        {
            node1 = node1->next;
        }
        for (int i = 0; i < key2; i++)
        {
            node2 = node2->next;
        }
        if (key1 + 1 == key2)
        {
            Node *prev1 = node1->prev;
            Node *next2 = node2->next;
            prev1->next = node2;
            next2->prev = node1;
            node2->prev = prev1;
            node2->next = node1;
            node1->prev = node2;
            node1->next = next2;
            return;
        }
        swap(node1->next, node2->next);
        swap(node1->prev, node2->prev);
        swap(node1->next->prev, node2->next->prev);
        swap(node1->prev->next, node2->prev->next);

    }
};
int main()
{
    Node *list = NULL;
    Node *head = list;
    list->insertAtEnd(head, 1);
    list->insertAtEnd(head, 7);
    list->insertAtEnd(head, 4);
    list->insertAtEnd(head, 2);
    list->insertAtEnd(head, 6);
    list->insertAtEnd(head, 4);
    list->insertAtEnd(head, 5);
    list->insertAtEnd(head, 3);
    list->insertAtEnd(head, 9);
    list->insertAtEnd(head, 8);
    list->print(head);
    cout << "Enter two node keys: ";
    int key1, key2;
    cin >> key1 >> key2;
    list->swapNodes(head, key1, key2);
    list->print(head);
}