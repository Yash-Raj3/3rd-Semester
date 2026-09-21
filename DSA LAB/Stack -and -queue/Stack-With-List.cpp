#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        next = NULL;
        this->val = val;
    }
};
class StackList
{
    Node *head;
    Node *tail;
    int count;
    const int MAX;

public:
    StackList() : MAX(100)
    {
        count = 0;
        head = tail = NULL;
    }
    void push(int val)
    {
        if (isFull)
        {
            cout << "Stack is Full!" << endl;
            return;
        }
        Node *newNode = new Node(val);

        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        count++;
    }
    void pull()
    {
        if (isEmpty())
        {
            cout << "Empty!" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            count--;
        }
    }
    int peek()
    {
        return head == NULL ? -1 : head->val;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    bool isFull()
    {
        return count == MAX;
    }
};
int main()
{
    StackList sl;
    sl.pull();
    sl.peek();
    sl.push(10);
    sl.push(99);
    sl.push(12);
    cout << sl.peek();
}