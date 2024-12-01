#include <iostream>
#include <cstdlib>
#include <ctime> // added these libraries to generate random integers between 1 to n
#include<string>
using namespace std;
struct Node {
    string task;
    int priority;
    Node* next;
};

class PriorityQueue {
private:
    Node* head;

public:
    PriorityQueue() {
        head = NULL;
    }

    void push(string  newTask, int priority) {
        Node* newNode = new Node();
        newNode->task =newTask;
        newNode->priority = priority;
        if (head == NULL || newNode->priority < head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;

            while (temp->next != NULL && temp->next->priority <= newNode->priority) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    int viewPriority(){
        if (!head)
        {
            return -1;
        }return head->priority;
        
    }
    void pop() {
        if (head == NULL) {
            cout << "Priority Queue is empty." << endl;
            return;
        }
            Node* temp = head;
            head = head->next;
            delete temp;
        
    }
    string peek() {
        if (head == NULL) {
            cout << "Priority Queue is empty." << endl;
            return ""; 
        }
        return head->task;
    }
};
void printAllTasks(PriorityQueue &queue){
    while (queue.peek()!="")
    {
        cout<<queue.peek()<<"\t->  Priority: "<<queue.viewPriority()<<endl;
        queue.pop(); 
    }
    
}
int main()
{
    PriorityQueue queue;
    int n;
    cout<<"Enter n(no. of nodes to be inserted in priority Queue): ";
    cin>>n;
    srand(time(0));//generates new random numbers
    for (int i = 0; i < n; i++)
    {
        int randomPriority = rand()%10 +1;
        string newTask = "Task "+ to_string(i+1);
        queue.push(newTask, randomPriority);
    }
    printAllTasks(queue);
    
}