#include <iostream>
#include <stdlib.h>
using namespace std;
int *resizeArray(int *arr, int oldSize, int newSize)
{
	if (oldSize == newSize)
	{
		return arr;
	}
	int *newArr = new int[newSize];
	int size = oldSize < newSize ? oldSize : newSize;
	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	for (int i = size; i < newSize; i++)
	{
		cout << "Enter Element " << i + 1 << " :";
		cin >> newArr[i];
	}
	delete[] arr;
	return newArr;
}
int main()
{
	system("color 04");
	int size;
	cout << "Enter Size of Array: ";
	cin >> size;
	int *arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter Element " << i + 1 << " :";
		cin >> arr[i];
	}

	int choice = -1;
	int newSize;
	while (choice != 4)
	{
		cout << "====Menu====\n";
		cout << "1.Grow Array" << endl;
		cout << "2.Shrink Array" << endl;
		cout << "3.Display Array" << endl;
		cout << "4.Exit" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
		switch (choice)
		{

		case 1:

			cout << "Enter New Size: ";
			cin >> newSize;
			arr = resizeArray(arr, size, newSize);
			break;
		case 2:

			cout << "Enter New Size: ";
			cin >> newSize;
			arr = resizeArray(arr, size, newSize);
			break;

		case 3:
			cout << "ARRAY" << endl;
			if (size == newSize)
			{
				for (int i = 0; i < size; i++)
				{
					cout << arr[i] << " ";
				}
			}
			else
			{
				for (int i = 0; i < newSize; i++)
				{
					cout << arr[i] << " ";
				}
			}
			cout << endl;
			break;
		case 4:
			cout << "Exiting the system....." << endl;
			delete []arr;
			return 0;
			break;
		default:
			cout << "Invalid Choice!" << endl;
		}
	}
}
