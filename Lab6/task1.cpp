#include<iostream>
using namespace std;
class myStack{
    int top,size;
    char *array;
    public:
    myStack(int n){
        array = new char[n];
        top = -1;
        size = n;

    }
    void push(char element){
        if (top!=size-1)
        {
            top++;
            array[top] = element;
        }else{
            return;
        }
        

    }
    char pop(){
        if (top!=-1)
        {
            top--;
            return array[top+1];
            
        }

    
        
    }
    char peek(){
        
        if(top>=0 && top<size){return array[top];}
    }
    bool isFull(){return top==size-1;}
    bool isEmpty(){return top==-1;}
    
    bool isPalindrome() {
    myStack thisStack = *this;  
    myStack tempStack(size);      

    while (!thisStack.isEmpty()) {
        tempStack.push(thisStack.pop());          
    }
    thisStack = *this;
    while (!thisStack.isEmpty()) {
        if (tempStack.peek() != thisStack.peek()) {
            return false;
        }

        thisStack.pop();
        tempStack.pop();
    }

    return true;  
}

};
int main(){
    myStack s1(9);
    s1.push('B');
    s1.push('O');
    s1.push('R');
    s1.push('R');
    s1.push('O');
    s1.push('W');
    s1.push('R');
    s1.push('O');
    s1.push('B');
    if (s1.isPalindrome())
    {
        cout<<"It is Palindrome\n";
    }else{
        cout<<"Not palindrome";
    }
    
    return 0;
}