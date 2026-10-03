#include <iostream>
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
    int numOfoperands()
    {
        return top + 1;
    }
};
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*')
    {
        return true;
    }
    return false;
}
int evaluate(string s)
{
    Stack st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else if (isOperator(s[i]))
        {
            if (st.numOfoperands() < 2)
            {
                cout << "Malformed Expression!" << endl;
                return 0;
            }
            int b = st.pop();
            int a = st.pop();
            int result;
            if (s[i] == '+')
            {
                result = a + b;
            }
            else if (s[i] == '-')
            {
                result = a - b;
            }
            else if (s[i] == '*')
            {
                result = a * b;
            }
            else
            {
                if (b == 0)
                {
                    cout << "Error Can't Divide By 0!" << endl;
                    return 0;
                }
                result = a / b;
            }
            st.push(result);
        }
        else
        {
            cout << "Invalid Character!" << endl;
            return 0;
        }
    }
    if (st.numOfoperands() != 1)
    {
        cout << "Malformed Expression!" << endl;
        return 0;
    }
    return st.pop();
}

int main()
{
    string s;
    cout << "Enter Equation: ";
    cin >> s;
    int result = evaluate(s);
    cout << "Result Of Operation: " << result << endl;
}