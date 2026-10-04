#include <iostream>
#include <cmath>
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
    void push(int c)
    {
        if (isFull())
        {
            return;
        }
        arr[++top] = c;
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
            return 0;
        }
        return arr[top];
    }
    int size()
    {
        return top + 1;
    }
};
bool isOperand(char c)
{
    if (c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return true;
    }
    return false;
}
int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    return 0;
}
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
bool Balanced(string infix)
{
    Stack s;
    for (int i = 0; i < infix.length(); i++)
    {
        if (isOpening(infix[i]))
        {
            s.push(infix[i]);
        }
        else if (isClosing(infix[i]))
        {
            if (s.isEmpty())
            {
                return false;
            }
            else if (infix[i] == ')' && s.peek() != '(')
            {
                return false;
            }
            else if (infix[i] == '}' && s.peek() != '{')
            {
                return false;
            }
            else if (infix[i] == ']' && s.peek() != '[')
            {
                return false;
            }
            s.pop();
        }
    }
    return s.isEmpty();
}
int calculate(int a, int b, char c)
{
    if (c == '+')
    {
        return a + b;
    }
    else if (c == '-')
    {
        return a - b;
    }
    else if (c == '*')
    {
        return a * b;
    }
    else if (c == '/')
    {
        if (b == 0)
        {
            cout << "Can't Divide by Zero!" << endl;
            return -1;
        }
        return a / b;
    }
    else if (c == '^')
    {
        return pow(a, b);
    }
}
int postfixE(string postfix)
{
    Stack s;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperand(postfix[i]))
        {
            s.push(postfix[i] - '0');
        }
        else if (isOperator(postfix[i]))
        {
            if (s.size() < 2)
            {
                cout << "Malformed Expression!" << endl;
                return -1;
            }
            int b = s.pop();
            int a = s.pop();
            int result = calculate(a, b, postfix[i]);
            s.push(result);
        }
        else
        {
            cout << "Invalid Character!" << endl;
            return -1;
        }
    }
    if (s.size() != 1)
    {
        cout << "Malformed Expression!" << endl;
        return -1;
    }
    return s.pop();
}
int PrefixE(string prefix)
{
    Stack s;
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (isOperand(prefix[i]))
        {
            s.push(prefix[i] - '0');
        }
        else if (isOperator(prefix[i]))
        {
            if (s.size() < 2)
            {
                cout << "Malformed Expression!" << endl;
                return -1;
            }
            int a = s.pop();
            int b = s.pop();
            int result = calculate(a, b, prefix[i]);
            s.push(result);
        }
        else
        {
            cout << "Invalid Character!" << endl;
            return -1;
        }
    }
    if (s.size() != 1)
    {
        cout << "Malformed Expression!" << endl;
        return -1;
    }
    return s.pop();
}
int main()
{
    string postfix, prefix;
    cout << "Enter prefix: ";
    cin >> prefix;
    if (!Balanced(prefix))
    {
        cout << "Not Balanced Expression!" << endl;
        return 0;
    }
    int result = PrefixE(prefix);
    cout << result;
}