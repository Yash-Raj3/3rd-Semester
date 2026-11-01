#include <iostream>
using namespace std;
int fact(int n, int fac)
{
    if (n == 0)
    {
        return fac;
    }

    return fact(n - 1, n * fac);
}
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Factorial of " << n << ": " << fact(n, 1) << endl;
}