#include <iostream>
using namespace std;
int Power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }

    return x * Power(x, n - 1);
}
int PowerFast(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int half = PowerFast(x, n / 2);
    if (n % 2 == 0)
    {
        return half * half;
    }
    else
    {
        return x * half * half;
    }
}
int main()
{
    int x, n;
    cout << "Enter X^N: ";
    cin >> x >> n;
    cout << "X^n = " << PowerFast(x, n);
}