#include <iostream>
using namespace std;
class Queue
{
    int *arr;
    int front;
    int rear;
    int count;
    int size;

public:
    Queue(int n)
    {
        size = n;
        arr = new int[n];
        front = 0;
        rear = -1;
        count = 0;
    }
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is Full!" << endl;
            return;
        }
        else
        {
            arr[++rear] = val;
            count++;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }
        else
        {
            front++;
            count--;
        }
    }
    int peek()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }

    bool isFull()
    {
        return count == size;
    }
    bool isEmpty()
    {
        return rear == -1;
    }
};
int main()
{
    Queue q1(10);
    q1.enqueue(11);
    q1.enqueue(11);
    q1.enqueue(12);
    q1.enqueue(11);
    q1.enqueue(11);
    q1.enqueue(41);
    q1.dequeue();
    cout << q1.peek() << endl;
}
