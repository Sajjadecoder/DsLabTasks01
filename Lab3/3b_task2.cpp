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
};
Node *concatenate(Node *L, Node *M)
{
    Node *newNode = NULL;
    Node *tempL = L;
    while (tempL->next != L)
    {
        tempL = tempL->next;
    }
    Node *tempM = M;
    while (tempM->next != M)
    {
        tempM = tempM->next;
    }
    L->prev = tempM;
    tempM->next = L;
    M->prev = tempL;
    tempL->next = M;
    newNode = L;
    return newNode;
}

int main()
{
    Node *L = NULL;
    Node *LHead = L;
    Node *M = NULL;
    Node *MHead = M;
    L->insertAtEnd(LHead, 2);
    L->insertAtEnd(LHead, 4);
    L->insertAtEnd(LHead, 6);
    L->insertAtEnd(LHead, 8);
    L->insertAtEnd(LHead, 10);
    M->insertAtEnd(MHead, 1);
    M->insertAtEnd(MHead, 3);
    M->insertAtEnd(MHead, 5);
    M->insertAtEnd(MHead, 7);
    M->insertAtEnd(MHead, 9);
    cout << "L: ";
    L->print(LHead);
    cout << "M: ";
    M->print(MHead);
    Node *concatenatedListNode = concatenate(LHead, MHead);
    cout << "Concatenated List(L+M): ";
    concatenatedListNode->print(concatenatedListNode);
    return 0;
}