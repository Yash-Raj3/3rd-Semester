#include <iostream>
using namespace std;

class DynamicSafeArray
{
    int initialCapacity;
    int count;
    int *arr;

public:
    DynamicSafeArray(int ic)
    {
        initialCapacity = ic;
        count = 0;
        arr = new int[initialCapacity];
    }
    void pushBack(int val)
    {
        if (count == initialCapacity)
        {
            int *newArr = new int[initialCapacity * 2];
            for (int i = 0; i < count; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            initialCapacity *= 2;
        }
        arr[count++] = val;
    }
    void set(int pos, int val)
    {
        if (pos < 0 || pos >= count)
        {
            cout << "Position out of bounds" << endl;
            return;
        }
        arr[pos] = val;
    }
    int get(int pos)
    {
        if (pos < 0 || pos >= count)
        {
            cout << "Position out of bounds" << endl;
            return -1;
        }
        return arr[pos];
    }
    bool removeAt(int pos)
    {
        if (pos < 0 || pos >= count)
        {
            cout << "Position out of bounds" << endl;
            return false;
        }
        for (int i = pos; i < count - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        count--;
        return true;
    }
    void display()
    {
        cout << "----Array elements----\n";
        for (int i = 0; i < count; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~DynamicSafeArray()
    {
        delete[] arr;
    }
};

int main()
{
    DynamicSafeArray DSA(2);
    DSA.pushBack(10);
    DSA.pushBack(20);
    DSA.pushBack(30);
    DSA.pushBack(40);
    DSA.pushBack(50);
    DSA.pushBack(60);
    cout << "Initial Array\n";
    DSA.display();
    DSA.removeAt(2);
    cout << "After removing element at position 2\n";
    DSA.display();
    cout << "Invalid Positions\n";
    DSA.get(6);
    DSA.set(7, 100);
}