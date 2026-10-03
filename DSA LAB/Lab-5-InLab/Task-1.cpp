#include <iostream>
#include <string>

using namespace std;
#define MAX 1000
class ToDO
{
public:
    string *arr;
    int top;
    ToDO()
    {
        arr = new string[MAX];
        top = -1;
    }
    void add(string x)
    {
        if (isFull())
        {
            return;
        }
        arr[++top] = x;
    }
    string undoLastTask()
    {
        if (IsEmpty())
        {
            return "TO-DO-LIST-EMPTY!";
        }
        cout << "Task Removed: " << arr[top] << endl;
        cout << "------------------------\n";
        return arr[top--];
    }
    void dsiplay()
    {
        if (IsEmpty())
        {
            cout << "TO-DO-LIST-EMPTY!" << endl;
            return;
        }
        cout << "-----To-Do-List-----\n";
        for (int i = 0; i <= top; i++)
        {
            cout << i + 1 << ". " << arr[top - i] << endl;
        }
        cout << "------------------------\n";
    }
    int search(string s)
    {
        int above = 0;
        for (int i = 0; i <= top; i++)
        {
            if (arr[i] == s)
            {
                return i;
            }
        }
        return -1;
    }
    bool IsEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == MAX - 1;
    }
};

void display()
{
    cout << "1.Add Task\n2.Remove Last Task\n3.View All\n4.Search\n5.Exit\n";
    cout << "Enter Choice: ";
}
int main()
{
    int choice = 0;
    ToDO list;
    while (choice != 5)
    {
        display();
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string s;
            cout << "Enter Task: ";
            cin.ignore();
            getline(cin, s);

            list.add(s);
            cout << "Task Added!" << endl;
            cout << "Enter any button to continue";
            getchar();
            system("cls");
            break;
        }

        case 2:

            list.undoLastTask();

            break;
        case 3:
            list.dsiplay();

            break;
        case 4:
        {
            string s;
            cout << "Enter Task: ";
            cin.ignore();
            getline(cin, s);
            cout << "------------------------\n";
            cout << "Above Task Number: " << list.search(s);
            cout << "------------------------\n";
            cout << endl;

            break;
        }

        case 5:
            cout << "Exiting the system...." << endl;
            return 0;
            break;
        default:
            cout << "Invalid Choice!" << endl;
        }
    }
}