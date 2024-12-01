#include<iostream>
using namespace std;
class myQueue{
    int *array;
    int rear,front,size;
    public:
    myQueue(int n){
        size = n;
        array = new int[n];
        rear=  -1;
        front = -1;
    }
    void enQueue(int val){
        if (rear==size-1)
        {
            cout<<"Queue is full\n";
            return;
        }
        if(rear==-1){

            front = 0;
        }
        array[++rear] = val; 
      
    }
    int dequeue(){
        if (front ==-1 || front>rear)
        {
            cout<<"Queue is empty\n";
            return -1;
        }
        
        return array[front++];
        
    }
    int getFront(){
        if (front!=-1)
        {
            return array[front];
            
        }
        return -1;
        
    }
    int getRear(){
        if (rear==-1)
        {
            return array[rear];
        } 
    }
};
int main(){
    myQueue queue(7);
    queue.enQueue(13);
    queue.enQueue(7);
    queue.enQueue(4);
    queue.enQueue(1);
    queue.enQueue(6);
    queue.enQueue(8);
    queue.enQueue(10);
    cout<<"Checking out\n";
    int id = 0;
    int count = 1;
    do{

        id = queue.dequeue();
        if (id!=-1)
        {
            cout<<"Checkout ID "<<count<<": "<<id<<endl;

        }
        count++;
        
    }while(id!=-1);
    
    
    return 0;
}