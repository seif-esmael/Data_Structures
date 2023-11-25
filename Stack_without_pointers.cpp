#include <iostream>
using namespace std;
#define endl '\n'
const int MAX_SIZE = 100;
template <class T>
class Stack
{
    int top;
    T item[MAX_SIZE];
    int size;
public:
    Stack()
    {
        top = -1;
        size = 0;
    }
//////////////////////////
    void push(T element)
    {
        top++;
        item[top] = element;
        size++;
    }
//////////////////////////
    bool isEmpty()
    {
        return top < 0;
    }
//////////////////////////
    void pop()
    {
        if (isEmpty())
        {
            cout << "The stack is empty to pop an element\n";
        }
        else
        {
            top--;
            size--;
        }
    }    
////////////////////////////
    int getsize()
    {
        cout << "Size = ";
        return size;
    }
///////////////////////////
    void print()
    {
        cout << "[ ";
        for (int i = top; i >= 0; i--)
        {
            cout << item[i] << " ";
        }
        cout << "]\n";
    }
///////////////////////////
    // T front()
    // {
    //     return item[top];
    // }
    void front(int& element)
    {
        element = item[top];
        //cout << element;
    }

};

int main()
{
    Stack <int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.print();
    int y = 1000;
    s.front(y);
    cout << y;
}