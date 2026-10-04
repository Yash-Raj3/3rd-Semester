#include <iostream>
using namespace std;
class Cqueue
{
public:
    int cap;
    int *arr;
    int rear;
    int front;
    Cqueue(int cap = 100)
    {
        this->cap = cap;
        arr = new int[cap];
        rear = front = -1;
    }
    bool isEmpty()
    {
        return rear == -1 && front == -1;
    }
    bool isFull()
    {
        return (rear + 1) % cap == front;
    }
    void enqueue(int x)
    {
        if (isFull())
        {
            return;
        }
        if (isEmpty())
        {
            rear = front = 0;
        }
        else
        {
            rear = (rear + 1) % cap;
        }

        arr[rear] = x;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }
        int x = arr[front];
        if (rear == front)
        {
            rear = front = -1;
        }
        else
        {
            front = (front + 1) % cap;
        }
        return x;
    }
    void display()
    {
        if (isEmpty())
        {
            return;
        }
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
            {
                break;
            }
            i = (i + 1) % cap;
        }
    }
    void bubble_sort()
    {

        int *temp = new int[cap];
        int n = 0;
        int i = front;
        while (true)
        {
            temp[n++] = arr[i];
            if (i == rear)
            {
                break;
            }
            i = (i + 1) % cap;
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (temp[j] > temp[j + 1])
                {
                    int t = temp[j];
                    temp[j] = temp[j + 1];
                    temp[j + 1] = t;
                }
            }
        }
        front = rear = -1;
        for (int i = 0; i < n; i++)
        {
            enqueue(temp[i]);
        }
    }
    ~Cqueue()
    {
        delete[] arr;
    }
};
int main()
{
    Cqueue cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(50);
    cq.enqueue(40);
    cq.enqueue(3);
    cq.enqueue(5);
    cq.bubble_sort();
    cq.display();
}
