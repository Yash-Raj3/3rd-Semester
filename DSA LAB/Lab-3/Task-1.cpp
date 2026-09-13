#include <iostream>
using namespace std;
// Shell Sort moves elements over larger distances using gaps, so elements get closer
// to their final positions before the final gap-1 pass.
// This reduces the amount of shifting needed compared with plain Insertion Sort

void print(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void shell_sort(int *arr, int n)
{
	for (int gap = n / 2; gap >= 1; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int j = i - gap;
			int key = arr[i];
			while (j >= 0 && arr[j] > key)
			{
				arr[j + gap] = arr[j];

				j = j - gap;
			}
			arr[j + gap] = key;
		}
		cout << "After Gap " << gap << ":" << endl;
		print(arr, n);
	}
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

int main()
{
	int n;
	cout << "Enter Size of Array: ";
	cin >> n;
	int *arr = EnterArray(n);
	shell_sort(arr, n);
	delete[] arr;
}
