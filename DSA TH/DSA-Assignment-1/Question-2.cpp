#include <iostream>
using namespace std;

void print(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void insertion_sort(int *arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
int *EnterArray(int n)
{
	int *array = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the Shelf " << i + 1 << " Size: ";
		cin >> array[i];
	}
	return array;
}
void update(int *&arr, int &n, int pos)
{
	int cap;
	cout << "Enter New Shelf Capacity: ";
	cin >> cap;
	int *newShelves = new int[n + 1];
	for (int i = 0; i < pos; i++)
	{
		newShelves[i] = arr[i];
	}
	newShelves[pos] = cap;
	for (int i = pos; i < n; i++)
	{
		newShelves[i + 1] = arr[i];
	}
	delete[] arr;
	arr = newShelves;
	n++;
}
int main()
{
	int n;
	cout << "Enter Number Shelves: ";
	cin >> n;
	int *shelves = EnterArray(n);

	cout << "Original Shelves Capacity: ";
	print(shelves, n);
	int pos;
	cout << "Enter Postion of New Shelf (0 to " << n << "): ";
	cin >> pos;
	if (pos > n || pos < 0)
	{
		cout << "Invalid Positon!\n";
		return 1;
	}

	update(shelves, n, pos);
	cout << "Shelves After Adding New Shelf: ";
	print(shelves, n);
	insertion_sort(shelves, n);
	cout << "Shelves After Sorting: ";
	print(shelves, n);

	delete[] shelves;
}
