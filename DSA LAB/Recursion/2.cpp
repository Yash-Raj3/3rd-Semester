#include <iostream>
using namespace std;
void stars(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << "*";
    stars(n - 1);
}
void space(int i)
{
    if (i == 0)
    {
        return;
    }
    cout << " ";
    space(i - 1);
}
void printStars(int n, int i)
{
    if (n == 0)
    {
        return;
    }
    stars(i);
    cout << endl;

    printStars(n - 1, i + 1);
}
void printStarsR(int n, int i)
{
    if (n == 0)
    {
        return;
    }
    stars(i);
    cout << endl;

    printStarsR(n - 1, i - 1);
}

void diamond(int n, int i, int j)
{
    if (n == 0)
    {
        return;
    }
    space(i);
    stars(j);
    cout << endl;
    diamond(n - 1, i - 1, j + 2);
}

int main()
{
    int n;
    cout << "Enter Rows: ";
    cin >> n;
    diamond(n, n, 1);
}