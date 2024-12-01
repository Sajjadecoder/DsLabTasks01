#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {}
    ~Node() { cout << "Memory freed with the value: " << data << endl; }
};
class CircularList
{
public:
    Node *head;
    Node *tail;
    CircularList()
    {
        head = NULL;
        tail = NULL;
    }
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            head->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        tail = newNode;
    }
    void insertAtStart(int val)
    {
        if (head == NULL)
        {
            Node *newNode =  new Node(val);
            head = newNode;
            head->next = head;
            tail = head;
            return;
        }
        Node *temp = head;
        do
        {
            temp = temp->next;
        } while (temp->next != head);
        Node *newNode = new Node(val);
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    void print()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;
        while (temp->next != head)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout<<temp->data;
        cout << endl;
    }
    void insertAtGivenPos(int pos, int val)
    {
        if (pos == 1)
        {
            insertAtStart(val);
            return;
        }
        Node *prev;
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp->next == head)
        {
            insertAtEnd(val);
            return;
        }
        Node *newNode = new Node(val);
        prev->next = newNode;
        newNode->next = temp;
    }
    void deleteNode(int val)
    {
        Node *temp = head;
        if (head->data == val)
        {
            head = head->next;
            tail->next = head;
            delete temp;
            return;
        }
        Node *prev;
        temp = temp->next;
        bool found = false;
        while (temp != head && !found)
        {
            if (temp->data == val)
            {
                found = true;
            }else{

            prev = temp;
            temp = temp->next;
            }

        } ;
        cout << endl;
        if (!found)
        {
            cout << val << " doesn't exists in the list\n";
            return;
        }
        if (temp->next == head)
        {
            tail = prev;
            tail->next = head;
            prev->next = head;
            delete temp;
            return;
        }
        prev->next = temp->next;
        delete temp;
    }
};
int main()
{
    CircularList list;
    
    list.insertAtStart(0); 
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    cout<<"Initial list\n";
    list.print();
    cout<<"list after inserting 75 at position 3\n";
    list.insertAtGivenPos(3, 75);
    list.print();
    list.deleteNode(4);
    list.print();
    list.deleteNode(50);
    cout<<"list after deleting 50\n";
    list.print();
    list.deleteNode(30);
    cout<<"list after deleting 30\n";
    list.print();
    return 0;
}