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
void comb_sort(int *arr, int n)
{
	int gap = n;
	bool swapped = true;
	while (swapped || gap != 1)
	{
		gap = (int)(gap / 1.3);
		swapped = false;
		if (gap < 1)
		{
			gap = 1;
		}
		cout << "Gap Value " << gap << ": ";

		for (int i = 0; i < n - gap; i++)
		{
			if (arr[i] > arr[i + gap])
			{
				int temp = arr[i];
				arr[i] = arr[i + gap];
				arr[i + gap] = temp;
				swapped = true;
			}
		}
		print(arr, n);
	}
}
int *EnterArray(int n)
{
	int *array = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter Package " << i + 1 << " Weight: ";
		cin >> array[i];
	}
	return array;
}
int main()
{
	int n;
	cout << "Enter Number of Package Weights: ";
	cin >> n;
	int *array = EnterArray(n);
	cout << "Original Array: ";
	print(array, n);
	cout << endl
		 << endl;
	comb_sort(array, n);
	cout << endl
		 << endl;
	cout << "After Sorting: ";
	print(array, n);

	delete[] array;
}
