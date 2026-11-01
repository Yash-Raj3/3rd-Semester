#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (a == b)
    {
        return a;
    }
    if (a > b)
    {
        return gcd(a - b, b);
    }
    if (a < b)
    {
        return gcd(a, b - a);
    }
}
int gcda(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcda(b, a % b);
}

int main()
{
    int a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;
    cout << "GCD: " << gcda(a, b);
}