#include <iostream>
using namespace std;
int partition(int *arr, int l, int r)
{
    int pivot = arr[r];
    int idx = l - 1;

    for (int i = l; i < r; i++)
    {
        if (arr[i] <= pivot)
        {
            idx++;
            int temp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = temp;
        }
    }
    idx++;
    int temp = arr[r];
    arr[r] = arr[idx];
    arr[idx] = temp;
    return idx;
}
void QuickSort(int *arr, int l, int r)
{

    if (l < r)
    {
        int j = partition(arr, l, r);
        QuickSort(arr, l, j - 1);
        QuickSort(arr, j + 1, r);
    }
}

int main()
{
    int n;
    cout << "enter n: ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter e " << i << ": ";
        cin >> arr[i];
    }
    QuickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}