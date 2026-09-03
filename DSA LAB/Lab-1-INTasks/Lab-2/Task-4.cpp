#include <iostream>
using namespace std;

class SafeArray
{
    int *arr;
    int size;

public:
    SafeArray(int s)
    {
        size = s;
        arr = new int[size];
    }
    void set(int pos, int val)
    {
        if (pos < 0 || pos >= size)
        {
            cout << "Boundary Error!" << endl;
            exit(1);
        }
        else
        {
            arr[pos] = val;
        }
    }
    int get(int pos)
    {
        if (pos < 0 || pos >= size)
        {
            cout << "Boundary Error!" << endl;
            return -1;
        }
        else
        {
            return arr[pos];
        }
    }
    void display()
    {
        cout << "----ARRAY----\n";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~SafeArray()
    {
        delete[] arr;
    }
};
int main()
{
    SafeArray sf(5);
    sf.set(0, 4);
    sf.set(3, 2);
    sf.set(1, 3);
    sf.set(2, 4);
    sf.set(4, 10);

    cout << "Getting Element From Position 2: " << sf.get(2) << endl;
    cout << "Getting Element From Position 0: " << sf.get(0) << endl;
    cout << "Getting Element From Position 1: " << sf.get(1) << endl;
    cout << "Getting Element From Position 3: " << sf.get(3) << endl;
    cout << "Getting Element From Position 4: " << sf.get(4) << endl;

    cout << "Getting Element From Position -1: " << sf.get(-1) << endl;
    cout << "Getting Element From Position 10: " << sf.get(10) << endl;
    // We will get a Error Message and -1 as value
}
