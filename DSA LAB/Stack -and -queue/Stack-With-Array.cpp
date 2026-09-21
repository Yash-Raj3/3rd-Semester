#include <iostream>
using namespace std;
// using array
class stack
{
    int *sk;
    int size;
    int top;

public:
    stack(int size) : size(size)
    {
        sk = new int[size];
        top = -1;
    }
    void push(int val)
    {
        if (isfull())
        {
            cout << "Stack is Full!" << endl;
            return;
        }
        else
        {
            sk[++top] = val;
        }
    }
    void print()
    {
        if (top == -1)
        {

            cout << "Stack Empty!" << endl;
            return;
        }
        for (int i = top; i >= 0; i--)
        {
            cout << sk[i] << endl;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!" << endl;
            return;
        }
        else
        {
            top--;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
    bool isfull()
    {
        if (top == size - 1)
        {
            return true;
        }
        return false;
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return sk[top];
    }
    ~stack()
    {
        delete[] sk;
    }
};

int main()
{
    stack sk(10);
    sk.push(10);
    sk.push(10);
    sk.push(10);
    sk.push(10);
    sk.push(10);
    sk.push(10);
    sk.push(10);
    sk.push(10);
    sk.push(10);
    sk.push(10);
    // sk.push(10);
    sk.pop();
    sk.pop();
    sk.pop();
    sk.pop();
    sk.pop();
    sk.pop();
    sk.pop();
    sk.pop();
    sk.pop();
    sk.pop();
    sk.push(100);

    sk.print();
}