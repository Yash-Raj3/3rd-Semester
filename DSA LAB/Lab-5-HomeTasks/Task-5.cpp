#include <iostream>
using namespace std;
#define MAX 100

class Stack
{
public:
    int arr[MAX];
    int top;
    Stack()
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
            return -1;
        }
        return arr[top--];
    }
};
class Queue
{
public:
    Stack StackIn, StackOut;

    void enqueue(int x)
    {
        StackIn.push(x);
    }
    int dequeue()
    {
        if (StackOut.isEmpty())
        {
            while (!StackIn.isEmpty())
            {
                StackOut.push(StackIn.pop());
            }
        }
        if (StackOut.isEmpty())
        {
            return -1;
        }
        return StackOut.pop();
    }
};
int main()
{
    Queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    cout << q1.dequeue() << " ";
    q1.enqueue(4);
    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";
}