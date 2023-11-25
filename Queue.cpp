#include <iostream>
#include <cassert>
#include <string>
#include <queue>
using namespace std;
#define endl '\n'
const int MAX_SIZE = 100;

template <class T>
class Queue
{
private:
    int front;
    int rear;
    int count;
    int * arr;
    int size;
    // int MAX_SIZE; 
public:
    Queue()
    {
        size = 100;
        arr = new int[size];
        front = 0;
        rear = MAX_SIZE - 1;
        count = 0;
    }
    Queue(int s)
    {
        size = s;
        if (size <= 0)
            // MAX_SIZE = 100;
            size = 100;
        else
            // MAX_SIZE = size;
            arr = new int[size];
            front = 0;
            rear = MAX_SIZE - 1;
            count = 0;
    }
    /////////////////////////
    bool isEmpty()
    {
        return count == 0;
    }
    ////////////////////////
    bool isFull()
    {
        return count == MAX_SIZE;
    }
    ////////////////////////
    void Add(int element)
    {
        if (isFull())
        {
            cout << "Cannot add as it's full\n" << endl;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
            arr[rear] = element;
            count++;
        }
    }
    ////////////////////////
    void remove()
    {
        if (isEmpty())
        {
            cout << "Empty\n" << endl;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
            count--;
        }
    }
    //////////////////////////
    int get_front()
    {
        assert(!isEmpty());
        return arr[front];
    }
    void get_front(int&front1)
    {
        front1 = arr[front];
    }
    ///////////////////////////
    int get_back()
    {
        assert(!isEmpty());
        return arr[rear];
    }
    //////////////////////////
    void print()
    {
        for (size_t i = front; i != rear; i = (i + 1) % MAX_SIZE)
        {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }
    /////////////////////////
    int search(T element)
    {
        int pos = -1;
        for (size_t i = front; i != rear; i = (i + 1) % MAX_SIZE)
        {
            if (arr[i] == element)
            {
                pos = i;
                break;
            }
            if (pos == -1)
            {
                if (arr[rear] == element)
                    pos = rear;
            }
        }
        return pos;
    }
    ///////////////////////////////
    void generateBinaryNumbers(int n)
    {
        Queue <string> q();

    }    
};
int main()
{
    Queue <string> q(1);
    q.Add(10);
    q.Add(20);
    q.Add(30);
    q.Add(40);
    q.Add(40);
    q.Add(40);
    q.Add(40);
    q.Add(40);
    q.Add(40);
    q.print();


    // int n = 10;
    // q.generateBinaryNumbers(n);
    // cout << endl;

}  