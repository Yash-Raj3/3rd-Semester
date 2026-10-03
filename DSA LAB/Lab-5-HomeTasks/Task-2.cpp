#include <iostream>
using namespace std;
// In a linear queue, rear only moves forward and does not reuse the
// empty spaces created by dequeue(). Therefore, the queue can report
// "full" even when there are free spaces at the front. A circular queue
// solves this by allowing rear to wrap around and reuse those spaces.

class Queue
{
private:
    int rear;
    int front;
    int *arr;
    int cap;

public:
    Queue(int c)
    {
        cap = c;
        arr = new int[cap];
        front = -1;
        rear = -1;
    }
    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return rear == cap - 1;
    }
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is Full!" << endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
        }
        arr[++rear] = x;
        cout << arr[rear] << " Enqueued" << endl;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << arr[front] << " Dequeued" << endl;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
};
int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(60);
    q.enqueue(70);

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
}
