#include <iostream>
using namespace std;
class Node
{
public:
    string val;
    Node *next;
    Node(string x)
    {
        val = x;
        next = NULL;
    }
};

class Stack
{
public:
    Node *head;
    Node *tail;

    Stack()
    {
        head = tail = NULL;
    }
    void visit(string x)
    {
        Node *newNode = new Node(x);

        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        cout << "Now At < " << x << " >" << endl;
    }
    string goBack()
    {
        if (head == NULL || head->next == NULL)
        {
            return "No previous page in history";
        }

        Node *del = head;

        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        delete del;
        return head->val;
    }
    bool isEmpty()
    {
        return head == NULL;
    }

    string peek()
    {
        if (isEmpty())
        {

            return "No previous page in history";
        }
        return head->val;
    }
};
int main()
{
    Stack s;
    s.visit("google.com");
    s.visit("github.com");
    s.visit("docs.com");
    cout << "Back to: " << s.goBack() << endl;
    cout << "Back to: " << s.goBack() << endl;
    cout << s.goBack() << endl;
}