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

	int Search(int key)
	{
		if (head == NULL)
		{
			cout << "LinkedList is Empty\n";
			return false;
		}
		Node *temp = head;
		int idx = 0;
		while (temp != NULL)
		{
			if (temp->val == key)
			{
				return idx;
			}
			idx++;
			temp = temp->next;
		}
		return -1;
	}

	int countNodes()
	{
		Node *temp = head;
		int count = 0;
		while (temp != NULL)
		{
			temp = temp->next;
			count++;
		}
		return count;
	}

	int sumOfnodes()
	{
		Node *temp = head;
		int sum = 0;
		while (temp != NULL)
		{
			sum += temp->val;
			temp = temp->next;
		}
		return sum;
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

	int choice;
	int val;
	int pos;
	int key;

	do
	{
		cout << "\n========== MENU ==========" << endl;
		cout << "1. Insert at Head" << endl;
		cout << "2. Insert at Tail" << endl;
		cout << "3. Insert After" << endl;
		cout << "4. Search" << endl;
		cout << "5. Display" << endl;
		cout << "6. Count Nodes" << endl;
		cout << "7. Sum of Nodes" << endl;
		cout << "8. Exit" << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{

		case 1:
			cout << "Enter value: ";
			cin >> val;
			sl.insertAThead(val);
			break;

		case 2:
			cout << "Enter value: ";
			cin >> val;
			sl.insertATtail(val);
			break;

		case 3:
			cout << "Enter value: ";
			cin >> val;

			cout << "Enter position: ";
			cin >> pos;

			sl.insert_After(val, pos);
			break;

		case 4:
			cout << "Enter value to search: ";
			cin >> key;

			if (sl.Search(key) != -1)
			{
				cout << "Element Node: " << sl.Search(key) << endl;
			}
			else
			{
				cout << "Not Found " << sl.Search(key) << endl;
			}
			break;

		case 5:
			sl.display();
			break;

		case 6:
			cout << "Total Nodes: " << sl.countNodes() << endl;
			break;

		case 7:
			cout << "Sum of All Nodes: " << sl.sumOfnodes() << endl;
			break;

		case 8:
			cout << "Program Exited." << endl;
			break;

		default:
			cout << "Invalid Choice" << endl;
		}

	} while (choice != 8);

	return 0;
}
