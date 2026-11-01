#include <iostream>
using namespace std;

void print(int *result, int n)
{
    cout << "{";
    for (int i = 0; i < n; i++)
    {
        cout << result[i];
    }
    cout << "}" << " ";
}
void subset(int *arr, int n, int i, int *result, int j)
{
    if (i == n)
    {
        print(result, j);
        return;
    }

    result[j] = arr[i];
    subset(arr, n, i + 1, result, j + 1);
    subset(arr, n, i + 1, result, j);
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

    int *result = new int[n];
    subset(arr, n, 0, result, 0);

    delete[] arr;
    delete[] result;
}