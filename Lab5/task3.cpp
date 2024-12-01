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
            cout<<temp->data<<" ";
            temp = temp->next;
        }cout<<endl;
        
    }
    void searchVal(Node *&head,int val,bool &exist){
        if (head==NULL)
        {
            return;
        }
        searchVal(head->next,val,exist);
        if (val==head->data)
        {
            cout<<"Found\n";
            exist  = true;

        }
        
    }

};
int main(){
    Node *list = NULL;
    Node *head= list;
    list->insertAtTail(head,20);
    list->insertAtTail(head,30);
    list->insertAtTail(head,40);
    list->insertAtTail(head,70);
    list->insertAtTail(head,80);
    list->insertAtTail(head,50);
    cout<<"List: ";list->display(head);
    cout<<"Enter Number to be searched in the List: ";
    int searchNum;
    cin>>searchNum;
    bool exist = false;
    list->searchVal(head,searchNum,exist);
    if (!exist)
    {
        cout<<searchNum<<" not found\n";
    }
        
    return 0;
}