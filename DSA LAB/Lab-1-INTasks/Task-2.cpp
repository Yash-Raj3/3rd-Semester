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
    ~Rectangle()
    {
        delete width;
        delete height;
        cout << "Rectangle Destroyed" << endl;
    }
};
int main()
{
    Rectangle r(4, 8);
    r.display();
}