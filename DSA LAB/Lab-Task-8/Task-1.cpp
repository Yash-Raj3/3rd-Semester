#include <iostream>
using namespace std;
int Sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return (n % 10) + Sum(n / 10);
}
int main()
{
    int n;
    cout << "Enter number to find sum: ";
    cin >> n;
    int sum = Sum(n);
    cout << "Sum of " << n << " : " << sum << endl;
}