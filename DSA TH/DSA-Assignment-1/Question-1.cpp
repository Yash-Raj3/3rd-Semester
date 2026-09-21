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
		cout << "After Iteration " << i << endl;
		print(arr, n);
	}
}
int *EnterArray(int n)
{
	int *array = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the length of Cabel " << i + 1 << ": ";
		cin >> array[i];
	}
	return array;
}

int main()
{
	int n;
	cout << "Enter Size of Array: ";
	cin >> n;
	int *array = EnterArray(n);
	cout << "Original Array\n";
	print(array, n);
	insertion_sort(array, n);
	cout << "After Sorting\n";
	print(array, n);

	delete[] array;
}
