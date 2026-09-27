#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        next = prev = NULL;
    }
};
class Doubly
{
public:
    Node *head;
    Node *tail;
    Doubly()
    {
        head = tail = NULL;
    }
    // -----------Task 1----------------
    void displayForward()
    {
        if (head == NULL)
        {
            cout << "Empty!" << endl;
            return;
        }
        cout << "NULL" << "<->";
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "<->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void displayBackward()
    {
        if (head == NULL)
        {
            cout << "Empty!" << endl;
            return;
        }
        cout << "NULL" << "<->";
        Node *temp = tail;
        while (temp != NULL)
        {
            cout << temp->val << "<->";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
    //-----------Task 2---------------
    void insertAtstart(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void insertAtend(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void insertAtPosition(int val, int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid Position!" << endl;
            return;
        }
        if (pos == 0)
        {
            insertAtstart(val);
            return;
        }
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Invalid Postion!" << endl;
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        temp->next = newNode;
    }
    //----------------Task 3----------------
    void deleteFromStart()
    {
        if (head == NULL)
        {
            cout << "Empty!" << endl;
            return;
        }
        Node *del = head;
        head = head->next;
        head->prev = NULL;
        delete del;
    }
    void deleteFromEnd()
    {
        if (head == NULL)
        {
            cout << "Empty!" << endl;
            return;
        }
        Node *del = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete del;
    }
    void deleteValue(int val)
    {
        if (head == NULL)
        {
            cout << "Empty!" << endl;
            return;
        }
        if (head->val == val)
        {
            Node *del = head;
            head = head->next;
            if (head != NULL)
            {
                head->prev = NULL;
            }
            else
            {
                tail = NULL;
            }
            delete del;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL && temp->next->val != val)
        {
            temp = temp->next;
        }
        if (temp->next == NULL || temp->next->val != val)
        {
            cout << "Not Found!" << endl;
            return;
        }
        else
        {
            Node *del = temp->next;
            temp->next = del->next;
            if (del->next != NULL)
            {
                del->next->prev = temp;
            }
            else
            {
                tail = temp;
            }

            delete del;
        }
    }
    //------------Task 4--------------
    void reverse()
    {
        if (head == NULL)
        {
            cout << "Empty!" << endl;
            return;
        }
        Node *curr = head;
        Node *temp = NULL;
        while (curr != NULL)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        temp = head;
        head = tail;
        tail = temp;
    }
    
};
int main()
{
    Doubly dl;
    dl.insertAtend(10);
    dl.insertAtend(30);
    dl.insertAtPosition(20, 1);
    dl.displayForward();
    dl.displayBackward();
    // dl.deleteFromEnd();
    dl.deleteValue(10);
    dl.displayForward();
    dl.reverse();
    dl.displayForward();
}