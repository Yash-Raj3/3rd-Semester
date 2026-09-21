#include <iostream>
using namespace std;

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
	sl.display();
}
