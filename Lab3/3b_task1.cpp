#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) : data(val), next(NULL) {}
    ~Node(){
        cout<<"Memory freed with the value: "<<data<<endl;
    }
};
class DoublyCircularList
{
    Node *head;

public:
    DoublyCircularList() : head(NULL) {}
    void print()
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
    void printInReverse()
    {
        if (head == NULL)
        {
            cout << "List Is Empty\n";
        }
        Node *temp = head->prev;
        do
        {
            cout << temp->data << " -> ";
            temp = temp->prev;
        } while (temp != head->prev);
        cout << endl;
    }
    void insertAtEnd(int val)
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
        head->prev=newNode;
    }
    void insertAtStart(int val){
        Node *newNode = new Node(val);
        if (head==NULL)
        {
            head = newNode;
            head->next = newNode;
            head->prev = newNode;
            return;
        }
        Node *lastNode = head;
        while (lastNode->next!=head)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;

        newNode->prev = head->prev;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        
    }
    void insertAtGivenPos(int pos,int val){
        Node *newNode = new Node(val);
        if (pos==1)
        {
            insertAtStart(val);
            return;
        }
        Node *temp = head;
        Node *previous = NULL;
        for (int i = 0; i < pos-1; i++)
        {
            previous = temp;
            temp = temp->next;
        }
        if (temp->next == head)
        {
            insertAtEnd(val);
            return;
        }
        newNode->prev = temp->prev;
        newNode->next = previous->next;
        temp->prev = newNode;
        previous->next = newNode;
        
        
    }
    void deleteNode(int val)
    {
        if (head->data==val)//if first node is to be deleted
        {
            Node *lastNode = head->prev;
            lastNode->next= head->next;
            Node *temp = head;
            head = head->next;
            head->prev=  lastNode;
            delete temp;
            return;
        }
        Node *temp = head;
        Node *previous = temp;
        Node *lastNode = head->prev;
        bool found = false;
        if (val==lastNode->data)//if last node is to be deleted
        {
            lastNode->prev->next= head;
            head->prev = lastNode->prev;
            temp = lastNode;
            delete temp;
            return;
        }
        while (temp!=head->prev && !found)
        {
            if (temp->data==val)
            {
                found = true;
            }else{
                previous = temp;
                temp = temp->next;

            }
            
        }
        if (!found)
        {
            cout<< val<<" doesn't exists in the list\n";
            return;
        }
        previous->next = temp->next;
        temp->next->prev = previous;
        delete temp;
    }
};
int main()
{
    DoublyCircularList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.insertAtStart(100);
    cout<<"Initial List: ";
    list.print();
    list.insertAtGivenPos(3,8);
    list.deleteNode(100);
    cout<<"\tafter 100 is deleted\n";
    cout<<"List: ";
    list.print();
    list.deleteNode(30);
    cout<<"\tafter 30 is deleted\n";
    cout<<"List: ";
    list.print();
    list.deleteNode(50);
    cout<<"\tafter 50 is deleted\n";
    cout<<"List: ";
    list.print();
    return 0;
}