#include <iostream>
using namespace std;
class Sorting
{
    int *arr;
    int n;

public:
    Sorting(int n)
    {
        this->n = n;
        arr = new int[n];
    }
    void enter()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Enter Element " << i << ": ";
            cin >> arr[i];
        }
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void bubble_sort()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    void selection_sort()
    {
        for (int i = 0; i < n - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[min])
                {
                    min = j;
                }
                int temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }
        }
    }
    void insertion_sort()
    {
        for (int i = 0; i < n; i++)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    void shell_sort()
    {
        for (int gap = n / 2; gap >= 1; gap /= 2)
        {
            for (int i = gap; i < n; i++)
            {
                int key = arr[i];
                int j = i - gap;
                while (j >= 0 && arr[j] > key)
                {
                    arr[j + gap] = arr[j];
                    j -= gap;
                }
                arr[j + gap] = key;
            }
        }
    }
    void comb_sort()
    {
        int gap = n;
        bool swapped = true;
        while (swapped || gap != 1)
        {
            gap = int(gap / 1.3);
            swapped = false;
            if (gap < 1)
            {
                gap = 1;
            }
            for (int i = 0; i < n - gap; i++)
            {
                if (arr[i] > arr[i + gap])
                {
                    int temp = arr[i];
                    arr[i] = arr[i + gap];
                    arr[i + gap] = temp;
                    swapped = true;
                }
            }
        }
    }
    int linear_search(int key)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == key)
            {
                return i;
            }
        }
        return -1;
    }
    int binarySearch(int key)
    {
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == key)
            {
                return mid;
            }
            if (arr[mid] < key)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
    int interPolation_search(int key)
    {
        int left = 0;
        int right = n - 1;
        while (left <= right && arr[left] <= key && arr[right] >= key)
        {
            int pos = left + (right - left) * (key - arr[left]) / (arr[right] - arr[left]);
            if (arr[pos] == key)
            {
                return pos;
            }
            if (arr[pos] < key)
            {
                left = pos + 1;
            }
            else
            {
                right = pos - 1;
            }
        }
        return -1;
    }
    ~Sorting()
    {
        delete[] arr;
    }
};
int main()
{
    Sorting s(5);
    s.enter();
    s.print();
    s.comb_sort();
    s.print();
    cout << "Key Postion: " << s.interPolation_search(10);
}