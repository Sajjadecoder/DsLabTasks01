#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
    int getSize(Node *&head)
    {
        int cnt = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
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
        reverseNodeHead = prev;
        return reverseNodeHead;
    }
    bool isPalindrome(Node *&head)
    {
        int n = getSize(head);
        Node *slowptr = head;
        Node *fastptr = head;
        if (n & 1)
        {
            while (fastptr != NULL && fastptr->next != NULL)
            {

                slowptr = slowptr->next;
                fastptr = fastptr->next;
                if (fastptr->next != NULL)
                {
                    fastptr = fastptr->next;
                }
            }
        }
        else
        {
            int iterator = 1;
            while ( iterator!=(n/2) )
            {
                slowptr = slowptr->next;
                iterator++;
            }
        }

        slowptr->next = reverseLL(slowptr->next);
        Node *forwardPtr = slowptr->next;
        Node *temp = head;
        while (forwardPtr!=NULL && temp!=NULL)
        {
            if (temp->data!=forwardPtr->data)
            {
                return false;
            }
            temp = temp->next;
            forwardPtr = forwardPtr->next;
            
        }
        
        return true;
    }
    void insertAtTail(Node *&head, int val)
    {
        if (head == NULL)
        {
            Node *newNode = new Node(val);
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new Node(val);
    }
    void display(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    Node *list = NULL;
    Node *head = list;
    list->insertAtTail(head, 1);
    list->insertAtTail(head, 2);
    list->insertAtTail(head, 2);
    list->insertAtTail(head, 3);
    list->insertAtTail(head, 2);
    list->insertAtTail(head, 1);
    list->display(head);
    bool check = list->isPalindrome(head);
    if (check)
    {
        cout<<"List is Palindrome\n";
    }else{
        cout<<"List is not a Palindrome\n";

    }

    return 0;
}