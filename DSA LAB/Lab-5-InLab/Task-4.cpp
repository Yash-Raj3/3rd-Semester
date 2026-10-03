#include <iostream>
using namespace std;
class Queue
{
public:
    int cap;
    string *arr;
    int rear;
    int front;
    Queue(int c = 100)
    {
        arr = new string[c];
        rear = -1;
        front = -1;
        cap = c;
    }
    void enqueue(string c)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else if (isEmpty())
        {
            rear = 0;
            front = 0;
        }
        else
        {
            rear = (rear + 1) % cap;
        }
        arr[rear] = c;
        cout << "----------------------\n";
        cout << c << " Added to Queue" << endl;
        cout << "----------------------\n";
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Serving: " << arr[front] << endl;
        if (rear == front)
        {
            rear = front = -1;
        }
        else
        {
            front = (front + 1) % cap;
        }
    }
    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "------Customer Queue------\n";
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
        cout << "\n----------------------";
        cout << endl;
    }
    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return ((rear + 1) % cap) == front;
    }
    ~Queue()
    {
        delete[] arr;
    }
};
void display()
{
    cout << "1.Add Customer\n2.Serve Customer\n3.View Queue\n4.Exit\n";
    cout << "Enter Choice: ";
}
int main()
{
    int n;
    cout << "Enter Queue Size: ";
    cin >> n;
    Queue q(n);
    int choice = 0;
    while (choice != 4)
    {
        display();
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string s;
            cout << "Enter Name of Customer: ";
            cin >> s;
            q.enqueue(s);
            break;
        }
        case 2:
            q.dequeue();
            break;
        case 3:
            q.displayQueue();
            break;
        case 4:
            cout << "Exiting the System...." << endl;
            return 0;
        default:
            cout << "Invalid Choice!" << endl;
        }
    }
}