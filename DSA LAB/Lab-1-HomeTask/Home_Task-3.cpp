#include <iostream>

using namespace std;

class DynamicArray
{

private:
    int *arr;
    int size;
    int capacity;

public:
    DynamicArray()
    {
        capacity = 2;
        arr = new int[capacity];
        size = 0;
        cout << "Default constructor" << endl;
    }
    DynamicArray(const DynamicArray &other)
    {

        capacity = other.capacity;
        size = other.size;
        arr = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }

        cout << "Copy Constructor" << endl;
    }
    DynamicArray &operator=(const DynamicArray &other)
    {
        if (this != &other)
        {
            delete[] arr;
            capacity = other.capacity;
            size = other.size;
            arr = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                arr[i] = other.arr[i];
            }
        }

        cout << "Copy assignment operator" << endl;
        return *this;
    }
    int &operator[](int index)
    {
        if (index >= 0 && index < size)
        {
            return arr[index];
        }
        else
        {
            cout << "Index is out of bounds" << endl;
            exit(1);
        }
    }
    void pushBack(int value)
    {
        if (size == capacity)
        {
            int *temp = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;

            arr = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                arr[i] = temp[i];
            }
            delete[] temp;
        }

        arr[size++] = value;
    }
    void print() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }
    ~DynamicArray()
    {
        delete[] arr;
    }
};

int main()
{
    DynamicArray arr1;
    arr1.pushBack(100);
    arr1.pushBack(211);
    arr1.pushBack(300);
    arr1.pushBack(412);
    arr1.pushBack(592);
    arr1.pushBack(433);
    cout << "Array 1" << endl;
    arr1.print();
    cout << arr1[1] << endl;

    DynamicArray arr2 = arr1;
    cout << "Array 2" << endl;
    arr2.print();

    DynamicArray arr3;
    arr3 = arr1;
    cout << "Array 3" << endl;
    arr3.print();
    arr2.pushBack(1200);
    arr3.pushBack(112);

    cout << "Array 2 after pushBack" << endl;
    arr2.print();
    cout << "Array 3 after pushBack" << endl;
    arr3.print();
    // After changing arr2 and arr3, we can clearly see that they are independent.
}
