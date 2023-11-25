#include <iostream>
using namespace std;
#define ll long long
#define endl '\n'
template <class T>
class Doubly_Linked_List
{
private:
    struct Node
    {
        int item;
        Node * next , * prev;
    };
    Node * first, * last;
    int length;
public:
    Doubly_Linked_List()
    {
        first = NULL;
        last = NULL;
        length = 0;
    }
    ////////////////////////////////////
    void insertFirst(int element)
    {
        Node * newnode = new Node;
        newnode ->item = element;
        if (length == 0)
        {
            first = last = newnode;
            newnode ->next = newnode->prev = NULL;
        }
        else
        {
            newnode->next = first;
            first ->prev = newnode;
            first = newnode;
        }
        length++;
    }
    ////////////////////////////////////
    void print()
    {
        Node * curr = new Node;
        curr = first;
        cout << "[ ";
        for (int i = 0; i < length; i++)
        {
            cout << curr ->item << " ";
            curr = curr ->next;
        }
        cout << "]" << endl;
    }
    ////////////////////////////////////
    bool isEmpty()
    {
        return (first == NULL);
    }
    ////////////////////////////////////
    void insertLast(int element)
    {
        Node * newnode = new Node;
        newnode ->item = element;
        if (length == 0)
        {
            first = last = newnode;
        }
        else
        {
            newnode ->next = NULL;
            newnode ->prev = last;
            last->next = newnode;
            last = newnode;
        }
        length++;
    }
    ////////////////////////////////////////
    void inserAt(int pos , int element)
    {
        if (pos < 0 || pos > length)
        {
            cout << "Out Of Range\n";
        }
        else
        {
            Node * newnode = new Node;
            newnode ->item = element;
            if (pos == 0)
            {
                insertFirst(element);
            }
            else if (pos == length)
            {
                insertLast(element);
            }
            else
            {
                Node * curr = new Node;
                curr = first;
                for (int i = 1; i < pos; i++)
                {
                    curr = curr ->next;
                }
                newnode->next = curr->next;
                newnode->prev = curr;
                curr->next = newnode;
                curr->next->prev = newnode;
            }
            length++;
        }
    }
    ///////////////////////////////////////////
    void deleteFirst()
    {
        if (length == 0)
        {
            cout << "List is empty to delete\n"; 
        }
        else if (length == 1)
        {
            delete first;
            first = last = NULL;
        }
        else
        {
            Node * curr = new Node;
            curr = first;
            first = curr ->next; // What is the difference with first = first ->next;
            first->prev = NULL;
            delete curr;
            length--;
        }
    }
    ///////////////////////////////////////////
    void deleteLast()
    {
        if (length == 0)
        {
            cout << "List is empty to delete\n"; 
        }
        else if (length == 1)
        {
            delete first;
            first = last = NULL;
        }
        else
        {
            Node * curr = new Node;
            curr = last;
            last = curr ->prev; // What is the difference with first = last ->next;
            last->next = NULL;
            delete curr;
            length--;
        }
    }
    ///////////////////////////////////
    // void remove(int element)
    // {
    //     if (length == 0)
    //     {
    //         cout << "List is empty\n";
    //     }
    //     else
    //     {
    //         if (first ->item == element)
    //         {
    //             deleteFirst();
    //         }
    //         else
    //         {
    //             Node * curr = first;
    //             while (curr != NULL && curr->item != element)
    //             {
    //                 curr = curr ->next;
    //             }
    //             if (curr == NULL)
    //             {
    //                 cout << "Not Found!\n";
    //                 return;
    //             }
    //             else if (curr ->next == NULL)
    //             {
    //                 deleteLast();
    //             }
    //             else
    //             {
    //                 curr->prev->next = curr->next;
    //                 curr ->next->prev = curr->prev;
    //                 delete curr;
    //                 length--;
    //             }
    //         }
    //     }
    // }

    void removeAt(int index)
    {
        if (isEmpty())
        {
            cout << "List is empty!" << endl;
            return;
        }
        else if(index < 0 || index > length)
        {
            cout << "Out of range!" << endl;
            return;
        }
        else if (index == 0)
        {
            deleteFirst();
        }
        else
        {
            int pos = 0;
            Node * curr = new Node;
            curr = first;
            while (curr != NULL)
            {
                if (index == pos)
                {
                    curr -> prev -> next = curr -> next;
                    if (curr ->next != NULL)
                    {
                        curr -> next -> prev = curr -> prev;
                    }
                    free(curr);
                    break;
                }
                curr = curr ->next;
                pos++;
            }
            length--;
        }
    }
    //////////////////////////////////////////////////////////
    T retrieveAt(int index)
    {
        if (isEmpty())
        {
            cout << "List is empty!" << endl;
        }
        else if (index < 0 || index > length)
        {
            cout << "Out of range!" << endl;
        }
        else
        {
            Node * curr = new Node;
            curr = first;
            int pos = 0;
            while (curr != NULL)
            {
                if (index == pos)
                {
                    return curr ->item;
                }
                curr = curr ->next;
                pos++;
            }
        }
    }
    //////////////////////////////////////////////////////////////
    void replaceAt (T newElement, int index)
    {
        if (isEmpty())
        {
            cout << "List is empty!" << endl;
        }
        else if (index < 0 || index > length)
        {
            cout << "Out of range!" << endl;
        }
        else
        {
            Node * curr = new Node;
            curr = first;
            int pos = 0;
            while (curr != NULL)
            {
                if (index == pos)
                {
                    curr ->item = newElement;
                    break;
                }
                curr = curr ->next;
                pos++;
            }
        }
    }
    //////////////////////////////////////////////////////////////
    bool isExist (T element)
    {
        if (isEmpty())
        {
            cout << "List is empty!" << endl;
        }
        else
        {
            Node * curr = new Node;
            curr = first;
            while (curr != NULL)
            {
                if (curr -> item == element)
                {
                    return true;
                }
                curr = curr ->next;
            }
            return false;
        }
    }
    //////////////////////////////////////////////////////////////
    bool isItemAtEqual (T element, int index)
    {
        if (isEmpty())
        {
            cout << "List is empty!" << endl;
        }
        else if (index < 0 || index > length)
        {
            cout << "Out of range!" << endl;
        }
        else
        {
            Node * curr = new Node;
            curr = first;
            int pos = 0;
            while (curr ->next != NULL)
            {
                if ((index == pos) && (curr ->item == element))
                {
                    return true;
                }
                curr = curr ->next;
                pos++;
            }
            return false;
        }
    }
    //////////////////////////////////////////////////////////////
    void swap (int firstItemIdx, int secondItemIdx)
    {

    }

    //////////////////////////////////////////////////////////////
    void reverse()
    {
        if (isEmpty())
        {
            cout << "List is empty!" << endl;
            return;
        }
        else
        {
            Node* curr = first;
            Node* temp = nullptr;

            while (curr != nullptr)
            {
                temp = curr->prev;
                curr->prev = curr->next;
                curr->next = temp;
                curr = curr->prev;
            }

            if (temp != nullptr)
            {
                last = first;
                first = temp->prev;
            }
        }
    }
    //////////////////////////////////////////////////////////////      
};

int main()
{
    Doubly_Linked_List <int> d;
    d.insertFirst(10);
    d.insertFirst(20);
    d.insertFirst(30);
    d.insertFirst(40);
    d.inserAt(2 , 1000);
    d.print();
}