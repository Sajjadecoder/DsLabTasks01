#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node (int val){
        data = val;
        next = NULL;
    }
    void insertAtTail(Node *&head,int val){
        Node *newNode = new Node(val);
        if (head==NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        
    }
    void display(Node *&head){
        Node *temp = head;
        while (temp)
        {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }cout<<"NULL\n";
        
    }
    int getLength(Node *&head,int count){
        if (head==NULL)
        {
            return count;
        }
        getLength(head->next,count+1);
        
    }

};
int main(){
    Node *list = NULL;
    Node *head= list;
    list->insertAtTail(head,20);
    list->insertAtTail(head,30);
    list->insertAtTail(head,40);
    list->insertAtTail(head,50);
    list->display(head);
    cout<<"Length of list: "<<list->getLength(head,0);
    return 0;
}