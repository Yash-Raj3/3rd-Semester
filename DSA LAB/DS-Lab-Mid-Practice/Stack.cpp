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
    int peek()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[top];
    }
    void removeElement(int x)
    {
        stack temp;
        while (!isEmpty())
        {
            int val = pop();
            if (val != x)
            {
                temp.push(val);
            }
        }
        while (!temp.isEmpty())
        {
            push(temp.pop());
        }
    }
    bool contain(int x)
    {
        for (int i = 0; i <= top; i++)
        {
            if (arr[i] == x)
            {
                return true;
            }
        }
        return false;
    }
    void remove_dups()
    {
        stack temp;
        while (!isEmpty())
        {
            int x = pop();
            if (!temp.contain(x))
            {
                temp.push(x);
            }
        }
        while (!temp.isEmpty())
        {
            push(temp.pop());
        }
    }
    void bubble_sort()
    {
        for (int i = 0; i <= top; i++)
        {
            for (int j = 0; j < top - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    void selection_sort()
    {
        for (int i = 0; i <= top; i++)
        {
            int min = i;
            for (int j = i + 1; j <= top; j++)
            {
                if (arr[j] < arr[min])
                {
                    min = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
    stack merge(stack s1, stack s2)
    {
        stack result;
        while (!s1.isEmpty() && !s2.isEmpty())
        {
            if (s1.peek() < s2.peek())
            {
                result.push(s1.pop());
            }
            else
            {
                result.push(s2.pop());
            }
        }
        while (!s1.isEmpty())
        {
            result.push(s1.pop());
        }
        while (!s2.isEmpty())
        {
            result.push(s2.pop());
        }
        return result;
    }
};
int main()
{
    stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(30);
    s1.push(50);
    s1.push(30);
    s1.display();
    cout << "------------------\n";
    s1.selection_sort();
    s1.display();
}