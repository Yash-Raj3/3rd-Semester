#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the Number of Elements in the array: ";
    cin >> n;
    double *arr = new double[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Element " << i + 1 << ":";
        cin >> arr[i];
    }
    double max = arr[0];
    double min = arr[0];
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << "Sum: " << sum << endl;
    cout << "Average: " << (sum / n) << endl;
    cout << "Maximum: " << max << endl;
    cout << "Minimum: " << min << endl;

    delete[] arr;
}
