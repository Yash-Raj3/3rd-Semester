#include <iostream>
using namespace std;
class rider
{
public:
	int riderID;
	string riderName;
	int NumofOrders;
	rider *next;
	rider(int id, string name, int orders)
	{
		riderID = id;
		riderName = name;
		NumofOrders = orders;
		next = NULL;
	}
};
class KFCriders
{
public:
	rider *first;
	rider *last;
	int count;

	KFCriders()
	{
		count = 0;
		first = last = NULL;
	}

	void insertAtBeginning(int id, string name, int orders)
	{
		rider *newRider = new rider(id, name, orders);
		if (first == NULL)
		{
			first = last = newRider;
			last->next = first;
		}
		else
		{
			newRider->next = first;
			first = newRider;
			last->next = first;
		}
		count++;
	}
	void insertAtend(int id, string name, int orders)
	{
		rider *newRider = new rider(id, name, orders);
		if (first == NULL)
		{
			first = last = newRider;
			last->next = first;
		}
		else
		{
			last->next = newRider;
			last = newRider;
			last->next = first;
		}
		count++;
	}
	void insertAtposition(int id, string name, int orders, int position)
	{
		if (position < 0 || position > count)
		{
			cout << "Invalid Position!\n";
			return;
		}
		if (position == 0)
		{
			insertAtBeginning(id, name, orders);
			return;
		}
		if (position == count)
		{
			insertAtend(id, name, orders);
			return;
		}
		rider *newRider = new rider(id, name, orders);
		rider *temp = first;
		for (int i = 0; i < position - 1; i++)
		{
			temp = temp->next;
		}
		newRider->next = temp->next;
		temp->next = newRider;
		count++;
	}
	void display()
	{
		if (first == NULL)
		{
			cout << "No riders available." << endl;
			return;
		}
		rider *temp = first;
		cout << "----All Available Riders----\n";
		for (int i = 0; i < count; i++)
		{
			cout << "Rider ID: " << temp->riderID << ", Name: " << temp->riderName << ", Orders: " << temp->NumofOrders << endl;
			temp = temp->next;
		}
	}
	void deletionfromBeginning()
	{
		if (first == NULL)
		{
			cout << "No riders available." << endl;
			return;
		}
		else if (first == last)
		{
			delete first;
			first = last = NULL;
		}
		else
		{
			rider *temp = first;
			first = first->next;
			last->next = first;
			temp->next = NULL;
			delete temp;
			count--;
		}
	}
	void deletionfromend()
	{
		if (first == NULL)
		{
			cout << "No riders available." << endl;
			return;
		}
		else if (first == last)
		{
			delete first;
			first = last = NULL;
		}
		else
		{
			rider *temp = last;
			rider *prev = first;
			while (prev->next != last)
			{
				prev = prev->next;
			}
			last = prev;
			last->next = first;

			temp->next = NULL;
			delete temp;
			count--;
		}
	}

	rider *search(int id)
	{
		if (first == NULL)
		{
			cout << "No Riders Available!\n";
			return NULL;
		}
		rider *temp = first;
		for (int i = 0; i < count; i++)
		{
			if (temp->riderID == id)
			{
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}
	void updateRider(int id, string NewName, int orders)
	{
		if (first == NULL)
		{
			cout << "No Riders Available!\n";
			return;
		}
		rider *temp = search(id);
		if (temp == NULL)
		{
			cout << "Rider Not Found!\n";
			return;
		}
		else
		{
			temp->riderName = NewName;
			temp->NumofOrders = orders;
			cout << "Rider Information Updated!\n";
			cout << "Name: " << temp->riderName << ", Orders: " << temp->NumofOrders << endl;
		}
	}
	void deletionformPostion(int position)
	{
		if (position < 0 || position > count)
		{
			cout << "Invalid Position!\n";
			return;
		}
		if (position == 0)
		{
			deletionfromBeginning();
			return;
		}
		if (position == count)
		{
			deletionfromend();
			return;
		}
		rider *temp = first;
		rider *prev = NULL;
		for (int i = 0; i < position; i++)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		temp->next = NULL;
		delete temp;
		count--;
	}
	void TotalRiders()
	{
		cout << "Total Riders: " << count << endl;
	}
	void traverseRider(int id)
	{
		if (first == NULL)
		{
			cout << "No Riders Available!\n";
			return;
		}
		rider *start = search(id);

		if (start == NULL)
		{
			cout << "Rider Not Found!\n";
			return;
		}
		else
		{
			rider *temp = start;
			while (temp->next != start)
			{
				cout << "Rider ID: " << temp->riderID << ", Name: " << temp->riderName << ", Orders: " << temp->NumofOrders << endl;
				temp = temp->next;
			}
			cout << "Rider ID: " << temp->riderID << ", Name: " << temp->riderName << ", Orders: " << temp->NumofOrders << endl;
		}
	}
};
int main()
{
	KFCriders kfc;
	kfc.insertAtBeginning(1, "John", 5);
	kfc.insertAtend(2, "Alice", 3);
	kfc.insertAtBeginning(3, "Bob", 7);
	kfc.insertAtposition(22, "Yash", 3, 3);
	kfc.display();
	// kfc.updateRider(22, "Raj", 133);
	kfc.deletionformPostion(2);
	kfc.display();
}