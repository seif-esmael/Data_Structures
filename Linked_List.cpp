#include <iostream>
using namespace std;
class linkedList
{
    struct Node
    {
        int item;
        Node * next;
    };
    Node * first, *last;
    int length;
public:
    linkedList()
    {
        first = last = NULL;
        length = 0;
    }
    ////////////////////////////////////////////////////
    bool isEmpty()
    {
        return length == 0;
    }
    ///////////////////////////////////////////////
    void insertFirst(int ele)
    {
        Node * newitem = new Node;
        newitem ->item = ele;
        if (length == 0)
        {
            first = last = newitem;
            newitem ->next = NULL;
        }
        else
        {
            newitem ->next=first;
            first = newitem;
        }
        length++;
    }
    ////////////////////////////////////////////
    void insertLast(int ele)
    {
        Node * newitem = new Node;
        newitem ->item = ele;
        if (length == 0)
        {
            first = last = newitem;
            newitem ->next = NULL;
        }
        else
        {
            last ->next = newitem;
            newitem->next = NULL; 
            last = newitem;
        }
        length++;
    }
    ///////////////////////////////////////////////
    void inserAt(int pos , int element)
    {
        if (pos < 0 || pos > length)
        {
            cout << "Out of Range\n";
        }
        else
        {
            Node * newnode = new Node;
            newnode ->item = element;
            if (pos == length)
            {
                insertLast(element);
            }
            else if (pos == 0)
            {
                insertFirst(element);
            }
            else
            {
                Node * cur = first;
                for (size_t i = 1; i < pos; i++)
                {
                    cur = cur ->next;
                }
                newnode ->next = cur->next;
                cur ->next = newnode;
            }
            length++;
        }
    }
    //////////////////////////////////////
    int getSize()
    {
        return length;
    }
    //////////////////////////////////////
    void removeFirst()
    {
        if (length == 0)
        {
            cout << "list is empty\n";
        }
        else if (length == 1)
        {
            delete first;
            last = first = NULL;
            length--;
        }
        else
        {
            Node * curr = first;
            first = first -> next;
            delete curr;
            length--;
        }
    }
    //////////////////////////////////////
    void removeLast()
    {
        Node * curr = first->next;
        Node * prev = first;
        while (curr != last)
        {
            prev = curr;
            curr = curr ->next;
        }
        delete curr;
        prev -> next = NULL;
        last = prev;
        length--;
    }
    ////////////////////////////////////
    void remove(int element)
    {
        if (isEmpty())
        {
            return;
        }
        Node * curr,*prev;
        if (first->item == element)
        {
            curr = first;
            first = first ->next;
            delete curr;
            length--;
            // if (length == 0)
            // {
            //     last = NULL;
            // }
        }
        else
        {
            curr = first ->next;
            prev = first;
            while (curr != NULL)
            {
                if (curr ->item == element)
                {
                    break;
                }
                prev = curr;
                curr = curr ->next;
            }
            if (curr == NULL)
            {
                cout << "NOT FOUND!\n";
            }
            else
            {
                prev->next = curr->next;
                if (last == curr)
                {
                    last = prev;
                }
                delete curr;
                length--;
            }   
        }
    }
    ////////////////////////////////////////////////
    void reverse()
    {
        Node * prev, * next, *curr;
        prev= NULL;
        curr = first;
        next=curr->next;
        while (next!= NULL)
        {
            next = curr -> next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        first = prev;
    }
    ///////////////////////////////////
    int search(int element)
    {
        Node * curr = new Node;
        curr = first;
        int pos = 0;
        while (curr != NULL)
        {
            if (curr ->item == element)
            {
                return pos;
            }
            curr = curr ->next;
            pos++;
        }
        return -1;
    }
    ///////////////////////////////////
    int getTop()
    {
        return first->item;
    }
    ///////////////////////////////////
    void Combine_Nodes_Between_Zeros(linkedList&result)
    {
        Node * curr = new Node;
        curr = first;
        int sum = 0;
        while (curr != NULL)
        {
        if (curr ->item == 0)
        {
            result.insertLast(sum);
            sum = 0;
        }
        sum += curr ->item;
        curr = curr ->next;
        }
    result.removeFirst();
    }
    ///////////////////////////////////////////////
    void Merge_K_Sorted_Linkedlists(linkedList *result, int number_of_lists)
    {
        linkedList pq;
        for (int i = 0; i < number_of_lists; i++)
        {
            if (result[i].first!= NULL)
            {
                pq.insertFirst(result[i].first->item);
            }
        }

        // Create a dummy node as the new merged list
        Node *dummy = new Node;
        Node *curr = dummy;

        // Merge and sort the linked lists
        while (!pq.isEmpty())
        {
            Node *minNode = pq.first;
            pq.removeFirst();

            // Append the minNode to the merged list
            curr->next = minNode;
            curr = curr->next;

            // Move minNode to its next
            if (minNode->next != NULL)
            {
                pq.insertLast(minNode->next->item);
            }
        }

        // Update the first and last pointers of the merged list
        first = dummy->next;
        last = curr;

        // Delete the dummy node
        delete dummy;
    }
    ///////////////////////////////////////////////
    void print()
    {
        Node * cur = first;
        cout << "[ ";
        while (cur != NULL)
        {
            cout << cur ->item << " ";
            cur = cur ->next;
        }        
        cout << "]\n";
    }
};

int main()
{
    linkedList l;
    linkedList result;
    l.insertLast(0);
    l.insertLast(3);
    l.insertLast(0);
    l.Combine_Nodes_Between_Zeros(result);
    result.print();
    // l1.insertLast(1);
    // l1.insertLast(3);
    // l1.insertLast(4);
    // /////////////////////////////
    // l2.insertLast(1);
    // l2.insertLast(3);
    // l2.insertLast(4);
    
    
    
}