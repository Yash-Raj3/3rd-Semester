#include <iostream>
using namespace std;
#define MAX 100
class stack
{
public:
    int arr[MAX];
    int top;
    stack()
    {
        top = -1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == MAX - 1;
    }
    void push(int x)
    {
        if (isFull())
        {
            return;
        }
        arr[++top] = x;
    }
    int pop()
    {
        if (isEmpty())
        {
            return 0;
        }
        return arr[top--];
    }
};

class Queue
{
public:
    stack s1, s2;
    void enqueue(int x)
    {
        s1.push(x);
    }
    int dequeue()
    {
        if (s2.isEmpty())
        {
            while (!s1.isEmpty())
            {
                s2.push(s1.pop());
            }
        }
        if (s2.isEmpty())
        {
            return -1;
        }
        return s2.pop();
    }
};
int main()
{
    Queue q1;
    q1.enqueue(3);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(8);
    cout << q1.dequeue() << " ";
    cout << q1.dequeue();
}