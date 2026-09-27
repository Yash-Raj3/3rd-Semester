#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        next = NULL;
        this->val = val;
    }
};
class Cl
{
public:
    Node *head;
    Node *tail;
    //--------------Task 5------------
    Cl()
    {
        head = tail = NULL;
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "Empty!" << endl;
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->val << "->";
            temp = temp->next;

        } while (temp != head);
        cout << endl;
    }
    //----------Task 6-----------------
    void Append(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }
    void insert(int pos, int val)
    {
        if (pos < 0)
        {
            cout << "Invalid!" << endl;
            return;
        }
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            if (pos != 0)
            {
                cout << "Invalid Position!" << endl;
                delete newNode;
                return;
            }
            head = tail = newNode;
            tail->next = head;
        }
        if (pos == 0)
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
            return;
        }
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
            if (temp == head)
            {
                cout << "Invalid Position!" << endl;
                delete newNode;
                return;
            }
        }

        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail)
        {
            tail = newNode;
            tail->next = head;
        }
    }
    void deleteValue(int val)
    {
        if (head == NULL)
        {
            cout << "Empty!" << endl;
            return;
        }
        if (head == tail)
        {
            if (head->val == val)
            {
                delete head;
                head = tail = NULL;
            }
            return;
        }
        if (head->val == val)
        {
            Node *del = head;
            head = head->next;
            tail->next = head;
            delete del;
            return;
        }
        Node *temp = head;
        while (temp->next != head && temp->next->val != val)
        {
            temp = temp->next;
        }
        if (temp->next->val == val)
        {
            Node *del = temp->next;
            temp->next = del->next;
            if (del == tail)
            {
                tail = temp;
                tail->next = head;
            }
            delete del;
        }
    }
    bool search(int key)
    {
        if (head == NULL)
        {
            cout << "Empty!" << endl;
            return false;
        }

        Node *temp = head;
        while (temp->next != head)
        {
            if (temp->val == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};
int main()
{
    Cl cl;
    cl.Append(100);
    cl.Append(10);
    cl.Append(98);
    cl.insert(2, 188);
    cl.insert(3, 988);
    cl.deleteValue(98);
    cl.display();
    if (cl.search(98))
    {
        cout << "Key Found!" << endl;
    }
    else
    {
        cout << "Key Not Found!" << endl;
    }
}