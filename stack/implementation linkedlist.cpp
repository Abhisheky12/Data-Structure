// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

// this class is only for node
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

// this class is for stack
class stack
{
public:
    Node *top;
    int size;
    stack()
    {
        top == NULL;
        size = 0;
    }

    // push
    void push(int value)
    {
        Node *temp = new Node(value);
        // if headbecomes full when you create many node
        if (temp == NULL)
        {
            cout << "stack overflow" << endl;
            return;
        }
        else
        {
            temp->next = top;
            top = temp;
            size++;
            cout << "pushed" << value << endl;
        }
    }

    // pop
    void pop()
    {
        if (top == NULL)
        {
            cout << "stack underflow";
            return;
        }
        else
        {
            Node *temp = top;
            top = top->next;
            size--;
            cout << "deleted" << temp->data << endl;
            delete temp;
        }
    }

    // peek
    int peek()
    {
        if (top == NULL)
        {
            cout << "stack is empty";
            return -1;
        }
        else
        {
            return top->data;
        }
    }
    // isempty
    int isempty()
    {
        if (top == NULL)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    // issize
    int issize()
    {
        return size;
    }
};
int main()
{
    stack S;
    S.push(5);
    S.push(10);
    S.push(15);
    S.push(20);
    S.push(25);
    S.pop();
    cout << S.isempty() << endl;
    cout << S.issize();

    return 0;
}