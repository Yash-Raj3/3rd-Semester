#include <iostream>
using namespace std;
class Node
{
public:
    string name;
    Node *next;
    Node(string n)
    {
        name = n;
        next = NULL;
    }
};
class Circular
{
    Node *head;
    Node *tail;
    Node *curr;

public:
    Circular()
    {
        head = tail = curr = NULL;
    }

    void AddPlayer(string name)
    {
        Node *newPlayer = new Node(name);
        if (head == NULL)
        {
            head = tail = newPlayer;
            tail->next = head;
            curr = head;
        }
        else
        {
            tail->next = newPlayer;
            tail = newPlayer;
            tail->next = head;
        }
    }
    void nextTurn()
    {
        if (curr == NULL)
        {
            cout << "No Players Available!" << endl;
            return;
        }
        if (curr->next != NULL)
        {
            curr = curr->next;
            cout << "Next Player: " << curr->name << endl;
        }
    }
    void removePlayer(string name)
    {
        if (head == NULL)
        {
            cout << "No Players Available!" << endl;
            return;
        }
        if (head == tail)
        {
            if (head->name == name)
            {
                delete head;
                head = tail = NULL;
            }
            return;
        }
        if (head->name == name)
        {
            Node *del = head;
            head = head->next;
            tail->next = head;
            if (curr == del)
            {
                curr = head;
            }
            delete del;
            return;
        }
        Node *temp = head;
        while (temp->next != head && temp->next->name != name)
        {
            temp = temp->next;
        }
        if (temp->next->name == name)
        {
            Node *del = temp->next;
            temp->next = del->next;
            if (curr == del)
            {
                curr = del->next;
            }
            if (del == tail)
            {
                tail = temp;
                temp->next = head;
            }
            delete del;
        }
    }
    void Display()
    {
        if (head == NULL)
        {
            cout << "No players Available!" << endl;
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->name << "->";
            temp = temp->next;

        } while (temp != head);
        cout << endl;
    }
};
int main()
{
    Circular c;
    c.AddPlayer("Yash");
    c.AddPlayer("Mahboor");
    c.AddPlayer("Qasim");
    c.AddPlayer("Ali Raza");
    c.AddPlayer("Khunais Baig");
    c.AddPlayer("Anas");

    c.Display();
    c.nextTurn();
    c.removePlayer("Qasim");
    c.Display();
}