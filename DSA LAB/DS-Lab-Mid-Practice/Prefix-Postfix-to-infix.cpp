#include <iostream>
using namespace std;
#define MAX 100
class Stack
{
public:
    string arr[MAX];
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
    void push(string c)
    {
        if (isFull())
        {
            return;
        }
        arr[++top] = c;
    }
    string pop()
    {
        if (isEmpty())
        {
            return "";
        }
        return arr[top--];
    }
    string peek()
    {
        if (isEmpty())
        {
            return "";
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
string prefixToinfix(string prefix)
{
    Stack s;
    for (int i = prefix.length() - 1; i >= 0; i--)
    {

        if (isOperand(prefix[i]))
        {
            string temp = "";
            temp += prefix[i];
            s.push(temp);
        }
        else if (isOperator(prefix[i]))
        {
            if (s.size() < 2)
            {
                cout << "Malformed Expression!" << endl;
                return "";
            }
            string a = s.pop();
            string b = s.pop();
            string result = "(" + a + prefix[i] + b + ")";
            s.push(result);
        }
        else
        {
            cout << "Invalid Character!" << endl;
            return "";
        }
    }
    if (s.size() != 1)
    {
        cout << "Malformed Expression!" << endl;
        return "";
    }
    return s.pop();
}
string postfixToInfix(string postfix)
{
    Stack s;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperand(postfix[i]))
        {
            string temp = "";
            temp += postfix[i];
            s.push(temp);
        }
        else if (isOperator(postfix[i]))
        {
            if (s.size() < 2)
            {
                cout << "Malformed!" << endl;
                return "";
            }
            string b = s.pop();
            string a = s.pop();
            string result = "(" + a + postfix[i] + b + ")";
            s.push(result);
        }
        else
        {
            cout << "Invalid Character!" << endl;
            return "";
        }
    }
    if (s.size() != 1)
    {
        cout << "Malformed!" << endl;
        return "";
    }
    return s.pop();
}
int main()
{
    string postfix;
    cout << "Enter Postfix: ";
    cin >> postfix;
    string result = postfixToInfix(postfix);
    cout << result;
}