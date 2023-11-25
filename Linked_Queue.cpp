#include <iostream>
#include <cassert>
using namespace std;
#define ll long long
#define endl '\n'
class Linked_Queue
{
private:
    struct Node
    {
        int item;
        Node * next;
    };
    Node * front , * back;
    int size;
public:
    Linked_Queue()
    {
        size = 0;
        front = NULL;
        back = NULL;
    }
    ///////////////////////////////////////
    bool isEmpty()
    {
        //return front == NULL && back == NULL;
        return size == 0;
    }
    /////////////////////////////////////////
    void Add(int element)
    {
        Node * newnode = new Node;
        newnode->item = element;
        if (isEmpty())
        {
            front = newnode;
            front->next = NULL;
            back = front;
        }
        else
        {
            newnode->next = NULL;
            back->next = newnode;
            back = newnode;
        }
        size++;
    }
    ////////////////////////////////////////////
    void remove(int element)
    {
        if (isEmpty())
        {
            cout << "Empty so we cannot dequeue" << endl;
            return;
        }
        else if (size == 1)
        {
            front = back = NULL;
            size = 0;
            delete front;
            free(back);
        }
        
        else
        {
            Node * temp = new Node;
            temp = front;
            front = front ->next;
            temp ->next = NULL;
            delete temp;
            size--;
        }
    }
    ////////////////////////////////////////////
    int getFront()
    {
        assert(isEmpty());
        return front->item;
    }
    ////////////////////////////////////////////
    int getBack()
    {
        assert(isEmpty());
        return back->item;
    }
    ////////////////////////////////////////////
    // void getFront(int&ele)
    // {
    //     ele = front ->item;
    // }
    ////////////////////////////////////////////
    // void getFront(int&ele)
    // {
    //     ele = back ->item;
    // }
    ////////////////////////////////////////////
    void clear()
    {
        Node * cur = new Node;
        while (front != NULL)
        {
            cur = front;
            front = front ->next;
            delete cur;
        }
        back = NULL;
    }
    ////////////////////////////////////////////
    void print()
    {
        Node * cur = new Node;
        cur = front;
        cout << "[ ";
        while (cur != NULL)
        {
            cout << cur->item << " ";
            cur = cur->next;
        }
        cout << "]" << endl;
    }
};

int main()
{
    Linked_Queue l;
    l.Add(10);
    l.Add(20);
    l.Add(30);
    l.Add(40);
    l.Add(50);
    l.print();
}