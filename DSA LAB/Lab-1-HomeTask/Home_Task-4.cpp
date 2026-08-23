#include <iostream>

using namespace std;

/*
1. The program used shollow copy which shared the same memory for objects
 and caused issues like unintended modifications and double deletion. So when we tried to delete b1 and b2 it
  caused double deletion because both obj shared the same memory. The missing function was deep copy
  constructor or copy assignment operator.

2.Yes, the corruption was visible before the program ends.
 Since b1 and b2 shared the same memory due to the shallow copy. when we ran the display() after setvalue()
 both objects displayed the same values, which was not intended.

*/
class Buffer
{
private:
    int *data;
    int length;

public:
    Buffer(int len)
    {
        length = len;
        data = new int[length];
        for (int i = 0; i < length; i++)
        {
            data[i] = 0;
        }
        cout << "Default Constructor" << endl;
    }
    Buffer(const Buffer &other)
    {
        length = other.length;
        data = new int[length];

        for (int i = 0; i < length; i++)
        {
            data[i] = other.data[i];
        }
        cout << "Copy Constructor" << endl;
    }
    Buffer &operator=(const Buffer &other)
    {
        if (this != &other)
        {
            delete[] data;
            length = other.length;
            data = new int[length];
            for (int i = 0; i < length; i++)
            {
                data[i] = other.data[i];
            }
        }
        cout << "Copy Assignment Operator " << endl;
        return *this;
    }

    void setValue(int index, int value)
    {
        if (index >= 0 && index < length)
        {

            data[index] = value;
        }
    }

    void display() const
    {
        for (int i = 0; i < length; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    ~Buffer()
    {
        delete[] data;
    }
};

int main()
{
    Buffer b1(5);
    b1.setValue(0, 5);
    Buffer b2 = b1;
    b2.setValue(1, 20);
    Buffer b3(3);
    b3 = b1;
    b3.setValue(2, 100);
    cout << "Buffer 1" << endl;
    b1.display();
    cout << "Buffer 2" << endl;
    b2.display();
    cout << "Buffer 3" << endl;
    b3.display();

    return 0; // all objects are destroyed here, and their destructors are called, releasing the allocated memory.
}
