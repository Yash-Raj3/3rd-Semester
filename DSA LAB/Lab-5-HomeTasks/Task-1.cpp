#include <iostream>
using namespace std;
#define MAX 100
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*' || c == '^')
    {
        return true;
    }
    return false;
}
bool isOperand(char c)
{
    if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9')
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
    else if (c == '/' || c == '*')
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
bool balanced(char infix[])
{
    char stack[MAX];
    int top = -1;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (isOpening(infix[i]))
        {
            stack[++top] = infix[i];
        }
        else if (isClosing(infix[i]))
        {
            if (top == -1)
            {
                return false;
            }
            else if (infix[i] == ')' && stack[top] != '(')
            {
                return false;
            }
            else if (infix[i] == '}' && stack[top] != '{')
            {
                return false;
            }
            else if (infix[i] == ']' && stack[top] != '[')
            {
                return false;
            }
            top--;
        }
    }
    return top == -1;
}
void reverse(char infix[])
{
    int s = 0;
    int e = 0;
    while (infix[e] != '\0')
    {
        e++;
    }
    e -= 1;
    while (s < e)
    {
        char temp = infix[s];
        infix[s] = infix[e];
        infix[e] = temp;
        s++;
        e--;
    }
}
void swapBrac(char infix[])
{
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
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
void infixtoprefix(char infix[], char prefix[])
{
    int j = 0;
    char stack[MAX];
    int top = -1;
    reverse(infix);
    swapBrac(infix);

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (isOperand(infix[i]))
        {
            prefix[j++] = infix[i];
        }
        else if (isOpening(infix[i]))
        {
            stack[++top] = infix[i];
        }
        else if (isClosing(infix[i]))
        {
            while (top != -1 && !isOpening(stack[top]))
            {
                prefix[j++] = stack[top--];
            }
            if (top != -1)
            {
                top--;
            }
        }
        else
        {
            while (top != -1 && !isOpening(stack[top]) && precedence(stack[top]) > precedence(infix[i]))
            {
                prefix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }
    while (top != -1)
    {
        prefix[j++] = stack[top--];
    }
    prefix[j] = '\0';
    reverse(prefix);
}
int main()
{
    char infix[MAX];
    char prefix[MAX];
    cout << "Enter Infix: ";
    cin >> infix;
    if (!balanced(infix))
    {
        cout << "Not Balanced!" << endl;
        return 1;
    }
    infixtoprefix(infix, prefix);
    cout << prefix << endl;
}