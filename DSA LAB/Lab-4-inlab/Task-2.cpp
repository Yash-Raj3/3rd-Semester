#include <iostream>
using namespace std;
class Node
{
public:
	Node *next;
	int val;
	Node(int v)
	{
		val = v;
		next = NULL;
	}
};
class SinglyLL
{
public:
	Node *head;
	Node *tail;

	SinglyLL()
	{
		head = tail = NULL;
	}

	void insertAThead(int val)
	{
		Node *newNode = new Node(val);
		if (head == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}
	void insertATtail(int val)
	{
		Node *newNode = new Node(val);
		if (head == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}
	void insert_After(int val, int pos)
	{
		if (pos < 0)
		{
			cout << "Invalid Position" << endl;
			return;
		}
		if (head == NULL)
		{
			cout << "Linked List is Empty" << endl;
			return;
		}
		Node *newNode = new Node(val);
		if (head == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			Node *temp = head;
			for (int i = 0; i < pos - 1; i++)
			{
				if (temp == NULL)
				{
					cout << "Invalid Position" << endl;
					return;
				}
				temp = temp->next;
			}
			if (temp == NULL)
			{
				cout << "Invalid Position" << endl;
				return;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
	void display()
	{
		Node *temp = head;
		while (temp != NULL)
		{
			cout << temp->val << "->";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
};
int main()
{
	SinglyLL sl;
	sl.insertATtail(10);
	sl.insertATtail(20);
	sl.insertAThead(5);
	sl.insert_After(15, 1);
	sl.display();
}
