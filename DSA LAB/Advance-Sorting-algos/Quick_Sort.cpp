#include <iostream>
using namespace std;

int partition(int *arr, int l, int h)
{
    int pivot = arr[h];
    int idx = l - 1;
    for (int j = l; j < h; j++)
    {
        if (arr[j] <= pivot)
        {
            idx++;
            int temp = arr[j];
            arr[j] = arr[idx];
            arr[idx] = temp;
        }
    }
    idx++;
    int temp = arr[h];
    arr[h] = arr[idx];
    arr[idx] = temp;
    return idx;
}
void quicksort(int *arr, int l, int h)
{
    if (l < h)
    {
        int j = partition(arr, l, h);

        quicksort(arr, l, j - 1);
        quicksort(arr, j + 1, h);
    }
}
int main()
{
    int n;

    cout << "Enter Size of Array: ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Element " << i << ": ";
        cin >> arr[i];
    }
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
}