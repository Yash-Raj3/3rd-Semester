#include <iostream>
using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}
void Permutation(int *arr, int n, int i)
{
    if (i == n)
    {
        print(arr, n);
        return;
    }

    for (int j = i; j < n; j++)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        Permutation(arr, n, i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
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
    Permutation(arr, n, 0);

    delete[] arr;
}