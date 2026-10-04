#include <iostream>
using namespace std;
#define MAX 100
class Stack
{
public:
    char arr[MAX];
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
    void push(char c)
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
    if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9')
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
string infixtopostfix(string infix)
{
    string postfix = "";
    Stack s;
    for (int i = 0; i < infix.length(); i++)
    {
        if (isOperand(infix[i]))
        {
            postfix += infix[i];
        }
        else if (isOpening(infix[i]))
        {
            s.push(infix[i]);
        }
        else if (isClosing(infix[i]))
        {
            while (!s.isEmpty() && !isOpening(s.peek()))
            {
                postfix += s.pop();
            }
            if (!s.isEmpty())
            {
                s.pop();
            }
        }
        else
        {
            while (!s.isEmpty() && s.peek() != '(' && precedence(s.peek()) >= precedence(infix[i]) && infix[i] != '^')
            {
                postfix += s.pop();
            }
            s.push(infix[i]);
        }
    }
    while (!s.isEmpty())
    {
        postfix += s.pop();
    }
    return postfix;
}
void reverse(string &infix)
{
    int left = 0;
    int right = infix.length() - 1;
    while (left < right)
    {
        char temp = infix[left];
        infix[left] = infix[right];
        infix[right] = temp;
        right--;
        left++;
    }
}
void swapBrac(string &infix)
{
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == ')')
        {
            infix[i] = '(';
        }
        else if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == '{')
        {
            infix[i] = '}';
        }
        else if (infix[i] == '}')
        {
            infix[i] = '{';
        }
        else if (infix[i] == '[')
        {
            infix[i] = ']';
        }
        else if (infix[i] == ']')
        {
            infix[i] = '[';
        }
    }
}
int main()
{
    string infix;
    cout << "Enter Infix: ";
    cin >> infix;
    if (!Balanced(infix))
    {
        cout << "Not Balanced Expression!" << endl;
        return 0;
    }
    reverse(infix);
    swapBrac(infix);
    string postfix = infixtopostfix(infix);
    reverse(postfix);
    cout << postfix;
}