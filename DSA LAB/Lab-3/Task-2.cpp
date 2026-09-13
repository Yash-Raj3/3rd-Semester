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
void bubble_sort(int *arr, int n)
{
	int swaps = 0;
	int comp = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			comp++;

			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swaps++;
			}
		}
	}
	cout << "Bubble Sort\n";
	cout << "Number Of Comparsion: " << comp << endl;
	cout << "Number of Swaps: " << swaps << endl;
}
void comb_sort(int *arr, int n)
{
	int gap = n;
	bool swapped = true;
	int comp = 0;
	int swaps = 0;
	while (gap != 1 || swapped)
	{
		gap /= 1.3;
		swapped = false;
		if (gap < 1)
		{
			gap = 1;
		}
		for (int i = 0; i < n - gap; i++)
		{
			comp++;
			if (arr[i] > arr[i + gap])
			{
				int temp = arr[i];
				arr[i] = arr[i + gap];
				arr[i + gap] = temp;
				swapped = true;
				swaps++;
			}
		}
	}
	cout << "Comb Sort\n";
	cout << "Number Of Comparsion: " << comp << endl;
	cout << "Number of Swaps: " << swaps << endl;
}

int *EnterArray(int n)
{

	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{

		arr[i] = n - i;
	}
	return arr;
}

int main()
{
	int n = 20;

	int *arr = EnterArray(n);
	int *arr2 = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr2[i] = arr[i];
	}
	bubble_sort(arr2, n);
	cout << "After Bubble Sort\n";
	print(arr2, n);
	comb_sort(arr, n);
	cout << "After Comb Sorting\n";
	print(arr, n);
	delete[] arr;
	delete[] arr2;
}
