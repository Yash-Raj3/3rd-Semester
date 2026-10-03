#include <iostream>
using namespace std;

class Stack
{
public:
    char arr[100];
    int top;

    Stack()
    {
        top = -1;
    }

    void push(char x)
    {
        arr[++top] = x;
    }

    char pop()
    {
        return arr[top--];
    }

    char peek()
    {
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int precedence(char op)
{
    if (op == '^')
        return 3;

    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' ||
           c == '/' || c == '^';
}

string infixToPostfix(string infix)
{
    Stack s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

    
        if ((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9'))
        {
            postfix += c;
        }


        else if (c == '(')
        {
            s.push(c);
        }

        
        else if (c == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix += s.pop();
            }

            if (!s.isEmpty())
                s.pop();
        }

        else if (isOperator(c))
        {
            while (!s.isEmpty() &&
                   s.peek() != '(' &&
                   (precedence(s.peek()) > precedence(c) ||
                    (precedence(s.peek()) == precedence(c) && c != '^')))
            {
                postfix += s.pop();
            }

            s.push(c);
        }
    }

    while (!s.isEmpty())
    {
        postfix += s.pop();
    }

    return postfix;
}

bool validParentheses(string infix)
{
    int count = 0;

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
            count++;

        else if (infix[i] == ')')
        {
            count--;

            if (count < 0)
                return false;
        }
    }

    return count == 0;
}

int main()
{
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    if (!validParentheses(infix))
    {
        cout << "Invalid Expression" << endl;
    }
    else
    {
        cout << "Postfix: " << infixToPostfix(infix) << endl;
    }

    
}
