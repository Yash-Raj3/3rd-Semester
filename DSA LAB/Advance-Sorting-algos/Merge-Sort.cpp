#include <iostream>
using namespace std;
void merge(int *arr, int l, int mid, int h)
{
    int *temp = new int[h - l + 1];
    int i = l;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= h)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= h)
    {
        temp[k++] = arr[j++];
    }

    for (int idx = 0; idx < k; idx++)
    {
        arr[idx + l] = temp[idx];
    }
    delete[] temp;
}
void mergeSort(int *arr, int l, int h)
{
    if (l < h)
    {
        int mid = l + (h - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
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
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
}