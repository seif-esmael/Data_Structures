#include <iostream>
using namespace std;
#define enld '\n'
template <class T>
class Stack
{
    struct Node
    {
        T items;
        Node * next;
    };
    Node* top,*curr;
    int size;
public:
    Stack()
    {
        top = NULL;
        size = 0;
    }
    /////////////////////////////////////
    void push(T element)
    {
        Node * newitem = new Node;
        if (newitem == NULL)
        {
            cout << "Cannot allocate memory\n";
        }
        else{
        newitem -> items = element;
        newitem ->next = top;
        top = newitem; 
        size++;
        }
    }
    //////////////////////////////////////
    bool isEsmpty()
    {
        return top == NULL;
    }
    //////////////////////////////////////
    void pop()
    {
        if (isEsmpty())
        {
            cout << "Stack is Empty to pop an element\n";
        }
        else
        {
            Node * temp = top;
            top = top ->next;
            temp = temp ->next= NULL; 
            delete temp;            
        }
    }
    /////////////////////////////////////////
    void pop(T &stacktop)
    {
        if (isEsmpty())
        {
            cout << "Stack is Empty to pop an element\n";
        }
        else
        {
            stacktop = top ->items;
            Node * temp = top;
            top = top ->next;
            temp = temp ->next= NULL;
            delete temp;
        }
    }
    /////////////////////////////////////////
    void getTop(T &stackTop)
    {
        if (isEsmpty())
        {
            cout << "Stack is Empty to pop an element\n";
        }
        else
        {
            stackTop = top -> items;
        }
    }
    //////////////////////////////////
    void display()
    {
        curr = top;
        while (curr != NULL)
        {
            cout << curr ->items << " ";
            curr = curr -> next;
        }
    }
};
int main()
{
    Stack <int>s;
    s.push(100);
    s.push(200);
    s.push(300);
    s.pop();
    s.display();
}