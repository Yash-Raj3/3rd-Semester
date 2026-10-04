#include <iostream>
using namespace std;
#define MAX 100
class Queue
{
public:
    int arr[MAX];
    int rear;
    int front;
    Queue()
    {
        rear = front = 0;
    }
    bool isEmpty()
    {
        return front == rear;
    }
    bool isFull()
    {
        return rear == MAX - 1;
    }
    void enqueue(int x)
    {
        if (isFull())
        {
            return;
        }
        arr[rear++] = x;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front++];
    }
};
class Stack
{
public:
    Queue q1, q2;
    void push(int x)
    {
        while (!q1.isEmpty())
        {
            q2.enqueue(q1.dequeue());
        }
        q1.enqueue(x);
        while (!q2.isEmpty())
        {
            q1.enqueue(q2.dequeue());
        }
    }

    int pop()
    {
        if (q1.isEmpty())
        {
            return -1;
        }
        return q1.dequeue();
    }
};
int main()
{
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    cout << s1.pop() << " ";
    cout << s1.pop();
}