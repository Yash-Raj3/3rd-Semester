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
class queueList
{
    Node *head;
    Node *tail;
    int count;
    const int MAX;

public:
    queueList() : MAX(100)
    {
        count = 0;
        head = tail = NULL;
    }
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is Full!" << endl;
            return;
        }
        Node *newNode = new Node(val);

        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }
    void dequeue()
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
    queueList ql;
    ql.enqueue(10);
    ql.enqueue(15);
    cout << ql.peek() << endl;
}