#include <iostream>
using namespace std;
bool Sorted = false;
int *bubble_sort(int *arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	Sorted = true;
	return arr;
}
int *insertion_sort(int *arr, int n)
{

	for (int i = 1; i < n; i++)
	{

		bool swapped = false;
		int j = i - 1;
		while (j >= 0 && arr[j] > arr[j + 1])
		{
			int temp = arr[j + 1];
			arr[j + 1] = arr[j];
			arr[j] = temp;
			j--;
			swapped = true;
		}
		if (swapped == false)
		{
			break;
		}
	}
	Sorted = true;
	return arr;
}
int *selection_sort(int *arr, int n)
{

	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
	Sorted = true;
	return arr;
}
int binary_search(int *arr, int n, int target)
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == target)
		{
			return mid;
		}
		else if (arr[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}
int linear_Search(int *arr, int n, int target)
{

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == target)
		{
			return i;
		}
	}
	return -1;
}
int *EnterArray(int n)
{
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter Element " << i << ": ";
		cin >> arr[i];
	}
	return arr;
}
void print(int *arr, int n)
{
	cout << "----Array----\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void display()
{
	cout << "----Menu----\n";
	cout << "1.Sort the Array\n2.Binary Search\n3.Linear Search\n4.Display\n5.Exit\n";
}
void Sortings()
{
	cout << "Available Sorting Algorithms\n";
	cout << "1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n";
}
int main()
{
	int n;
	cout << "Enter Size of Array: ";
	cin >> n;
	int *originalArray = EnterArray(n);
	int choice = 0;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = originalArray[i];
	}

	while (choice != 5)
	{
		display();
		cout << "Enter Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			{
			
			int Schoice;
			Sortings();
			cout << "Enter Choice: ";
			cin >> Schoice;
			if (Schoice == 1)
			{
				arr = bubble_sort(arr, n);
			}
			else if (Schoice == 2)
			{
				arr = selection_sort(arr, n);
			}
			else if (Schoice == 3)
			{
				arr = insertion_sort(arr, n);
			}
			else
			{
				cout << "Invalid Choice!\n";
			}
			break;
		}
		case 2:
			{
			
			if (Sorted)
			{
				int target;
				cout << "Enter Target Element: ";
				cin >> target;
				int idx = binary_search(arr, n, target);
				if (idx != -1)
				{
					cout << "Target " << target << " Element Index: " << idx << endl;
				}
				else
				{
					cout << "Not Found!" << endl;
				}
			}
			else
			{
				cout << "Array is Not Sorted!\n";
			}
			break;
		}
		case 3:
			{
			
			int target;
			cout << "Enter Target Element: ";
			cin >> target;
			int idx = linear_Search(originalArray, n, target);
			if (idx != -1)
			{
				cout << "Target " << target << " Element Index: " << idx << endl;
			}
			else
			{
				cout << "Not Found!" << endl;
			}

			break;
		}
		case 4:
			print(arr, n);
			break;
		case 5:
			cout << "Exiting the System.....\n";
			delete[] originalArray;
			delete[] arr;
			return 0;
		default:
			cout << "Invalid Choice!\n";
		}
	}
}
