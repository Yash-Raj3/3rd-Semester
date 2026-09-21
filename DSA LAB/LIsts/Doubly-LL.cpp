#include <iostream>
using namespace std;

class Node
{
public:
	Node *next;
	Node *prev;
	int val;
	Node(int v)
	{
		val = v;
		next = prev = NULL;
	}
};
class DoublyLL
{
public:
	Node *head;
	Node *tail;

	DoublyLL()
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
			head->prev = newNode;
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
			newNode->prev = tail;
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
		if (pos == 0)
		{
			insertAThead(val);
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
					cout << "Invalid Position\n";
					return;
				}
				temp = temp->next;
			}
			if (temp == NULL)
			{
				cout << "Invalid Position\n";
				return;
			}
			newNode->next = temp->next;
			newNode->prev = temp;
			if (temp->next != NULL)
			{
				temp->next->prev = newNode;
			}
			temp->next = newNode;
		}
	}
	bool Search(int key)
	{
		if (head == NULL)
		{
			cout << "LinkedList is Empty\n";
			return false;
		}
		Node *temp = head;
		while (temp != NULL)
		{
			if (temp->val == key)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	void reverse()
	{
		Node *temp = NULL;
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
	void print_reverse()
	{
		Node *temp = tail;
		while (temp != NULL)
		{
			cout << temp->val << "->";
			temp = temp->prev;
		}
		cout << "NULL" << endl;
	}
};
int main()
{
	DoublyLL dl;
	dl.insertAThead(12);
	dl.insertAThead(9);
	dl.insertATtail(98);
	dl.insertATtail(45);
	dl.insert_After(12, 3);
	dl.print();
	dl.insert_After(12, -1);
	dl.print();
	//	int key;
	//	cout<<"Enter Key: ";
	//	cin>>key;
	//	if(dl.Search(key)){
	//		cout<<"Found\n";
	//
	//	}else{
	//		cout<<"Not Found\n";
	//
	//	}
	// dl.print_reverse();
	dl.reverse();
	dl.print();
}
