#ifndef STACK_H
#define STACK_H

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node *prev;

    Node(T value){
        data = value;
        prev = next = nullptr;
    }
};

template <typename T>
class Stack
{
    Node<T> *head;
    int size;
public:
    Stack() {
        head = nullptr;
        size = 0;
    }

    void push(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        head = newNode;
        size++;
    }

    T pop()
    {
        if (isEmpty())
        {
            exit(1);
        }

        Node<T> *temp = head;
        T val= temp->data;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        delete temp;
        size--;
        return val;
    }

    T peek()
    {
        if (!isEmpty())
        {
            
            return head->data;
        }
    }

    bool isEmpty() 
    {
        return head == nullptr;
    }

    int getSize() 
    {
        return size;
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

#endif