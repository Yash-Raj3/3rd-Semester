#include <iostream>
using namespace std;
int get_max(int *arr, int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int get_min(int *arr, int n)
{
    int min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
void count_sort(int *arr, int n)
{
    int min = get_min(arr, n);
    int max = get_max(arr, n);
    int size = max - min + 1;
    int *count = new int[size];
    for (int i = 0; i < size; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[arr[i] - min]++;
    }
    int j = 0, i = 0;
    while (i < size)
    {
        if (count[i] > 0)
        {
            arr[j++] = i + min;
            count[i]--;
        }
        else
        {
            i++;
        }
    }
    delete[] count;
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
    count_sort(arr, n);
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}