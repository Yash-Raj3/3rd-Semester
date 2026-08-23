#include <iostream>
#include <string.h>

using namespace std;

class DynamicString
{
private:
    char *data;

public:
    DynamicString()
    {
        data = new char[1];
        data[0] = '\0';
        cout << "Default constructor" << endl;
    }
    DynamicString(const char *text)
    {
        data = new char[strlen(text) + 1];
        strcpy(data, text);
        cout << "Parameterized constructor" << endl;
    }
    DynamicString(const DynamicString &other)
    {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        cout << "Copy constructor" << endl;
    }
    DynamicString &operator=(const DynamicString &other)
    {
        if (this != &other)
        {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        cout << "Copy assignment operator" << endl;
        return *this;
    }
    void setChar(int index, char c)
    {
        if (index >= 0 && index < length())
        {
            data[index] = c;
        }
    }

    int length() const
    {
        return strlen(data);
    }
    void print() const
    {
        cout << data << endl;
    }

    ~DynamicString()
    {
        cout << "Destructor" << endl;
        delete[] data;
    }
};
int main()
{
    DynamicString ds1("Yash");
    DynamicString ds2(ds1);
    cout << "String 1: ";
    ds1.print();
    cout << "String 2: ";
    ds2.print();
    cout << endl;
    DynamicString ds3;
    ds3 = ds1;
    cout << "String 3: ";
    ds3.print();

    ds2.setChar(2, 'A');
    ds3.setChar(3, 'B');
    cout << "After modifying ds2 and ds3" << endl;
    cout << "String 1: ";
    ds1.print();
    cout << "String 2: ";
    ds2.print();
    cout << "String 3: ";
    ds3.print();
}