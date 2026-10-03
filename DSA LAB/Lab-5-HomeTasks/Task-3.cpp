#include <iostream>
using namespace std;
#define MAX 100
class stack
{
public:
    char arr[MAX];
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
        return top == MAX;
    }
    void push(char c)
    {
        if (isFull())
        {
            return;
        }
        arr[++top] = c;
    }
    void pop()
    {
        if (isEmpty())
        {
            return;
        }
        top--;
    }
    char peek()
    {
        if (isEmpty())
        {
            return '!';
        }
        return arr[top];
    }
};
bool isOpening(char c)
{
    if (c == '(' || c == '{' || c == '[')
    {
        return true;
    }
    return false;
}
bool isClosing(char c)
{
    if (c == ')' || c == '}' || c == ']')
    {
        return true;
    }
    return false;
}

bool Balanced(char arr[])
{
    stack s;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (isOpening(arr[i]))
        {
            s.push(arr[i]);
        }
        else if (isClosing(arr[i]))
        {
            if (s.isEmpty())
            {
                return false;
            }
            else if (arr[i] == ')' && s.peek() != '(')
            {
                return false;
            }
            else if (arr[i] == '}' && s.peek() != '{')
            {
                return false;
            }
            else if (arr[i] == ']' && s.peek() != '[')
            {
                return false;
            }
            s.pop();
        }
    }
    return s.isEmpty();
}
int main()
{
    char arr[MAX];
    cout << "Enter Equation: ";
    cin >> arr;
    if (Balanced(arr))
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not Balanced!";
    }
}