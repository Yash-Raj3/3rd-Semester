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
        prev = next = NULL;
        this->val = val;
    }
};
class Singly
{
public:
    Node *head;
    Node *tail;

    Singly()
    {
        head = tail = NULL;
    }

    void insertAthead(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
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
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
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
    void insertAtpos(int val, int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid Position!" << endl;
            return;
        }
        if (isEmpty())
        {
            cout << "List is Empty!" << endl;
            return;
        }
        if (pos == 0)
        {
            insertAthead(val);
            return;
        }
        Node *newNode = new Node(val);

        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Invalid Position!" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Invalid Position!" << endl;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }
        if (temp == tail)
        {
            tail = newNode;
        }
        temp->next = newNode;
    }
    void insertSorted(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            head = tail = newNode;
        }
        if (val <= head->val)
        {
            insertAthead(val);
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL && temp->next->val < val)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL)
            {
                temp->next->prev = newNode;
            }
            if (temp == tail)
            {
                tail = newNode;
            }
            temp->next = newNode;
        }
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    void print()
    {
        if (isEmpty())
        {
            cout << "List is Empty!" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void reverse()
    {
        Node *temp;
        Node *curr = head;

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
    void deleteAtfront()
    {
        if (isEmpty())
        {
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        Node *del = head;
        head = head->next;
        head->prev = NULL;
        delete del;
    }
    void deleteATend()
    {
        if (isEmpty())
        {
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        Node *del = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete del;
    }
    void deleteAtpos(int pos)
    {
        if (isEmpty())
        {
            return;
        }
        if (pos < 0)
        {
            cout << "Invalid Position!" << endl;
            return;
        }
        if (pos == 0)
        {
            deleteAtfront();
            return;
        }

        Node *temp = head;
        for (int i = 0; i < pos; i++)
        {
            if (temp->next == NULL)
            {
                cout << "Invalid Position!" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Invalid Position!" << endl;
            return;
        }
        if (temp == tail)
        {
            deleteATend();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
    void remove_Dups_from_Sorted()
    {
        if (isEmpty())
        {
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->val == temp->next->val)
            {
                Node *del = temp->next;
                temp->next = del->next;
                if (del->next != NULL)
                {
                    del->next->prev = temp;
                }
                if (del == tail)
                {
                    tail = temp;
                }
                delete del;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    void insertion_sort()
    {
        Node *sorted = NULL;
        Node *curr = head;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            if (sorted == NULL || curr->val < sorted->val)
            {
                curr->next = sorted;
                if (sorted != NULL)
                {
                    sorted->prev = curr;
                }
                sorted = curr;
            }
            else
            {
                Node *temp = sorted;
                while (temp->next != NULL && temp->next->val < curr->val)
                {
                    temp = temp->next;
                }
                curr->next = temp->next;
                curr->prev = temp;
                if (temp->next != NULL)
                {
                    temp->next->prev = curr;
                }
                temp->next = curr;
            }
            curr = next;
        }
        head = sorted;
        tail = head;
        if (tail != NULL)
        {
            while (tail->next != NULL)
            {
                tail = tail->next;
            }
        }
    }
    int middle()
    {
        if (isEmpty())
        {
            return -1;
        }
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->val;
    }
    void selection_sort()
    {
        Node *i = head;
        while (i != NULL)
        {
            Node *min = i;
            Node *j = i->next;
            while (j != NULL)
            {
                if (j->val < min->val)
                {
                    min = j;
                }
                j = j->next;
            }
            int temp = i->val;
            i->val = min->val;
            min->val = temp;
            i = i->next;
        }
    }
    // void Selection_Sort_By_Nodes()
    // {
    //     Node *i = head;
    //     Node *pi = NULL;
    //     while (i != NULL)
    //     {
    //         Node *min = i;
    //         Node *pmin = pi;

    //         Node *j = i->next;
    //         Node *pj = i;

    //         while (j != NULL)
    //         {
    //             if (j->val < min->val)
    //             {
    //                 min = j;
    //                 pmin = pj;
    //             }
    //             pj = j;
    //             j = j->next;
    //         }
    //         if (min != i)
    //         {
    //             pmin->next = min->next;
    //             min->next = i;
    //             if (pi == NULL)
    //             {
    //                 head = min;
    //             }
    //             else
    //             {
    //                 pi = min;
    //             }
    //             i = min;
    //         }
    //         pi = i;
    //         i = i->next;
    //     }
    // }
    void remove_dups_from_unsorted()
    {
        Node *i = head;
        while (i != NULL)
        {

            Node *j = i->next;
            while (j != NULL)
            {
                if (i->val == j->val)
                {
                    Node *del = j;
                    j = j->next;

                    if (del->prev != NULL)
                    {
                        j->prev->next = del->next;
                    }
                    if (del->next != NULL)
                    {
                        del->next->prev = del->prev;
                    }
                    if (del == tail)
                    {
                        tail = del->prev;
                    }

                    delete del;
                }
                else
                {

                    j = j->next;
                }
            }
            i = i->next;
        }
    }
    bool isPalindrome()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        Node *curr = slow;
        Node *prev = NULL;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        Node *left = head;
        Node *right = prev;
        while (right != NULL)
        {
            if (left->val != right->val)
            {
                return false;
            }
            right = right->next;
            left = left->next;
        }
        return true;
    }
    void bubble_sort()
    {
        if (head == NULL)
        {
            cout << "Empty!" << endl;
            return;
        }
        bool swapped = true;
        while (swapped)
        {
            Node *i = head;
            swapped = false;
            while (i->next != NULL)
            {
                if (i->val > i->next->val)
                {
                    int temp = i->val;
                    i->val = i->next->val;
                    i->next->val = temp;
                    swapped = true;
                }
                i = i->next;
            }
        }
    }
};
int main()
{
}