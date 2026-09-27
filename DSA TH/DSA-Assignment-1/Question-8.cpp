#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    int move;
    Node *next;

    Node(char d, int m)
    {
        data = d;
        move = m;
        next = NULL;
    }
};

class Stack
{
public:
    Node *top;
    int pos;
    int moves;
    int undos;

    Stack()
    {
        top = NULL;
        pos = 0;
        moves = 0;
        undos = 0;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(char c, int m)
    {
        Node *n = new Node(c, m);
        n->next = top;
        top = n;
    }

    int pop()
    {
        Node *temp = top;
        int m = temp->move;

        top = top->next;
        delete temp;

        return m;
    }

    void move(char c)
    {
        if (c == 'R')
        {
            pos++;
            push('R', 1);
            moves++;
        }

        else if (c == 'L')
        {
            if (pos > 0)
            {
                pos--;
                push('L', -1);
                moves++;
            }
        }

        else if (c == 'J')
        {
            pos += 2;
            push('J', 2);
            moves++;
        }

        else if (c == 'B')
        {
            if (!isEmpty())
            {
                pos -= pop();
                undos++;
            }
        }
    }

    void display()
    {
        Node *temp = top;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    Stack s;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        s.move(c);
    }

    cout << "Final Position: " << s.pos << endl;
    cout << "Successful Movements: " << s.moves << endl;
    cout << "Successful Undo: " << s.undos << endl;

    cout << "Remaining Stack: ";
    s.display();

    return 0;
}