#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int val):data(val),next(NULL){}
    void ModifyList(Node *&head){
        Node *evenList = NULL;
        Node* evenHead = evenList;
        Node* evenTail = evenList;
        Node *oddList = NULL;
        Node* oddHead = oddList;
        Node* oddTail = oddList;
        Node *temp = head;
        while (temp!=NULL)  
        {
            if (temp->data %2==0)   
            {
                if (evenList==NULL)
                {
                    Node *newNode = new Node(temp->data);
                    evenList = newNode;
                    evenHead = newNode;
                    evenTail = newNode;

                }else{
                    evenTail->next = new Node(temp->data);
                    evenTail = evenTail->next;
                }
                
            }else{
                if (oddList==NULL)
                {
                    Node *newNode = new Node(temp->data);
                    oddList = newNode;
                    oddHead = newNode;
                    oddTail = newNode;

                }else{
                    oddTail->next = new Node(temp->data);
                    oddTail = oddTail->next;
                }

            }
            temp = temp->next;
            
        }
        if (oddHead== NULL)
        {
            head = evenHead;
            return;

        }
        if (evenHead==NULL)
        {
            head = oddHead;
            return;
        }
        
        
        evenTail->next = oddHead;
        head = evenHead;

        

    }
    void insertAtTail(Node *&head,int val)
    {
        if (head==NULL)
        {
            Node *newNode = new Node (val);
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next=  new Node(val);
        
        
    }
    void display(Node *head){
        Node *temp  =head;
        while (temp!=NULL)
        {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }cout<<"NULL\n";
        
    }
};
int main(){
    Node *list = NULL;
    Node *head = list;
    cout<<"Case 1 (when the list has both even and odd values):\n";
    cout<<"  Original List\n";
    list->insertAtTail(head,1);
    list->insertAtTail(head,3);
    list->insertAtTail(head,4);
    list->insertAtTail(head,8);
    list->insertAtTail(head,9);
    list->display(head);
    cout<<"  After Modification\n";
    list->ModifyList(head);
    list->display(head);
    cout<<"Case 2 (when the list has ony even values):\n";
    Node *list2 = NULL;
    Node *head2 = list2;
    list2->insertAtTail(head2,2);
    list2->insertAtTail(head2,4);
    list2->insertAtTail(head2,6);
    list2->insertAtTail(head2,8);
    list2->insertAtTail(head2,10);
    cout<<"  Original List\n";
    list2->display(head2);
    list2->ModifyList(head2);
    cout<<"  After Modification\n";
    list2->display(head2);
    cout<<"Case 3 (when the list has only odd values):\n";
    Node *list3 = NULL;
    Node *head3 = list3;
    list3->insertAtTail(head3,1);
    list3->insertAtTail(head3,3);
    list3->insertAtTail(head3,5);
    list3->insertAtTail(head3,7);
    list3->insertAtTail(head3,9);
    cout<<"  Original List\n";
    list3->display(head3);
    list3->ModifyList(head3);
    cout<<"  After Modification\n";
    list3->display(head3);
    return 0;
}