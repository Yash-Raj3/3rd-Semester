#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int val)
    {
        value = val;
        next = nullptr;
    }
};
class LinkedList
{
public:
    Node *head;
    Node *tail;
    LinkedList()
    {
        head = tail = nullptr;
    }
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void push_after(int val, int pos)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void reverse()
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    int middle()
    {
        Node *slow = head;
        Node *Fast = head;
        while (Fast != NULL && Fast->next != NULL)
        {
            Fast = Fast->next->next;
            slow = slow->next;
        }
        return slow->value;
    }
    Node *mergeSorted(Node *head1, Node *head2)
    {
        if (head1 == NULL && head2 == NULL)
        {
            return NULL;
        }
        if (head1 == NULL)
        {
            return head2;
        }
        if (head2 == NULL)
        {
            return head1;
        }
        Node *Mhead = NULL;
        if (head1->value < head2->value)
        {
            Mhead = head1;
            head1 = head1->next;
        }
        else
        {
            Mhead = head2;
            head2 = head2->next;
        }
        Node *Mtail = Mhead;
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->value < head2->value)
            {
                Mtail->next = head1;
                head1 = head1->next;
            }
            else
            {
                Mtail->next = head2;
                head2 = head2->next;
            }
            Mtail = Mtail->next;
        }
        if (head1 != NULL)
        {
            Mtail->next = head1;
        }
        else
        {
            Mtail->next = head2;
        }
        return Mhead;
    }
    void insertionSort()
    {
        Node *sorted = NULL;
        Node *curr = head;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            if (sorted == NULL || curr->value < sorted->value)
            {
                curr->next = sorted;
                sorted = curr;
            }
            else
            {
                Node *temp = sorted;
                while (temp->next != NULL && temp->next->value < curr->value)
                {
                    temp = temp->next;
                }
                curr->next = temp->next;
                temp->next = curr;
            }
            curr = next;
        }
        head = sorted;
    }
    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main()
{
    LinkedList ls;
    ls.push_back(1);
    ls.push_back(2);
    ls.push_back(3);
    ls.push_front(0);
    ls.push_front(-1);
    ls.push_after(4, 3);
    ls.push_front(3);
    ls.print();
    ls.reverse();
    ls.print();
    cout << "Middle of Linkedlist = " << ls.middle() << endl;
    ls.insertionSort();
    ls.print();
    // List 1
    // LinkedList ls1, ls2, ls3;
    // ls1.push_back(1);
    // ls2.push_back(2);
    // ls1.push_back(3);
    // ls2.push_back(5);
    // ls1.push_back(8);
    // ls2.push_back(10);
    // ls2.push_back(11);
    // ls3.head = ls3.mergeSorted(ls1.head, ls2.head);
    // ls3.print();
}
