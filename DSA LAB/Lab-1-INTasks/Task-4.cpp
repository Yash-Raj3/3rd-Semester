#include <iostream>
using namespace std;

class Rectangle
{
    int *width, *height;

public:
    Rectangle(int w, int h)
    {
        width = new int(w);
        height = new int(h);
    }
    Rectangle(const Rectangle &other)
    {
        width = new int(*other.width);
        height = new int(*other.height);
    }
    int area() const
    {
        return (*width) * (*height);
    }
    void display() const
    {
        cout << "Width: " << (*width) << endl;
        cout << "Height: " << (*height) << endl;
        cout << "Area: " << area() << endl;
    }
    int getwidth() const
    {
        return *width;
    }
    int *getwidthAddress() const
    {
        return width;
    }
    void setwidth(int w)
    {
        *width = w;
    }
    ~Rectangle()
    {
        delete width;
        delete height;
        cout << "Rectangle Destroyed" << endl;
    }
};
int main()
{
    Rectangle r1(4, 5);
    Rectangle r2 = r1;
    cout << "Width of r1: " << r1.getwidthAddress() << endl;
    cout << "Width of r2: " << r2.getwidthAddress() << endl;
    r2.setwidth(10);
    cout << "New width of r2: " << r2.getwidth() << endl;
    cout << "R1 Values: " << endl;
    r1.display();
    /* when r1 and r2 go out of scope, their destructors will be called.
    This time program will run without any crash because r1 and r2 have separate memory and
     so there will be no problem of double deletion and both will be destroyed safely*/
}
