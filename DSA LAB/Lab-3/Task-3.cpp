#include <iostream>
using namespace std;
// For uniformly distributed data, the estimated position is usually very close to the target,
// allowing the search range to shrink extremely quickly, giving an average complexity of
// O(log log n). With non-uniform data, the estimated position can be poor and
// the algorithm may examine many positions, degrading toward O(n) in the worst case.
int interpolation_search(int *arr, int n, int target, int &count)
{
	int low = 0;
	int high = n - 1;

	if (arr[low] == arr[high])
	{
		if (arr[low] == target)
			return low;
		else
			return -1;
	}

	while (low <= high && arr[low] <= target && arr[high] >= target)
	{
		count++;
		int pos = low + ((high - low) * (target - arr[low]) / (arr[high] - arr[low]));
		if (arr[pos] == target)
		{
			return pos;
		}
		else if (arr[pos] < target)
		{
			low = pos + 1;
		}
		else
		{
			high = pos - 1;
		}
	}

	return -1;
}
int binarySearch(int *arr, int n, int target, int &count)
{
	int low = 0;
	int high = n - 1;

	while (low <= high)
	{
		count++;

		int mid = low + (high - low) / 2;

		if (arr[mid] == target)
		{
			return mid;
		}

		if (arr[mid] < target)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	return -1;
}

int *EnterArray(int n)
{
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = (i + 1) * 5;
	}

	return arr;
}
int main()
{
	int n = 10;
	int Icount = 0;
	int Bcount = 0;
	int *arr = EnterArray(n);
	cout << "Uniform Interpolation Search\n";
	int idx = interpolation_search(arr, n, 20, Icount);
	cout << "Target Element Index: " << idx << endl;
	cout << "Iteration: " << Icount << endl;
	cout << endl;
	cout << " Uniform Binary Search\n";
	int idx2 = binarySearch(arr, n, 20, Bcount);
	cout << "Target Element Index: " << idx2 << endl;
	cout << "Iteration: " << Bcount << endl;
	cout << endl;
	cout << endl;
	int arr2[] = {1, 2, 3, 4, 5, 1000};
	int n2 = 6;
	Icount = 0, Bcount = 0;
	cout << "Non-Uniform Interpolation Search\n";
	idx = interpolation_search(arr2, n2, 1000, Icount);
	cout << "Target Element Index: " << idx << endl;
	cout << "Iteration: " << Icount << endl;
	cout << endl;
	cout << "Non-Uniform Binary Search\n";
	idx2 = binarySearch(arr2, n2, 1000, Bcount);
	cout << "Target Element Index: " << idx2 << endl;
	cout << "Iteration: " << Bcount << endl;

	delete[] arr;
}
