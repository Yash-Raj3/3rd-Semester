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
class LL
{
public:
    Node *head;
    Node *tail;
    LL()
    {
        head = tail = NULL;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void split(int n, LL &ll, LL &gEL)
    {

        if (head == NULL)
        {
            cout << "Empty!" << endl;
            return;
        }
        while (head != NULL)
        {
            if (head->val < n)
            {
                if (ll.head == NULL)
                {
                    ll.head = ll.tail = head;
                }
                else
                {
                    ll.tail->next = head;
                    ll.tail = head;
                }
            }
            else
            {
                if (gEL.head == NULL)
                {
                    gEL.head = gEL.tail = head;
                }
                else
                {
                    gEL.tail->next = head;
                    gEL.tail = head;
                }
            }
            head = head->next;
        }
        if (ll.tail != NULL)
        {
            ll.tail->next = NULL;
        }
        if (gEL.tail != NULL)
        {
            gEL.tail->next = NULL;
        }
    }
};
int main()
{
    LL l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.insert(6);
    l1.insert(7);
    l1.insert(8);
    LL ll, gEl;
    l1.split(3, ll, gEl);
    ll.print();
    gEl.print();
}