#include <iostream>
using namespace std;

long long calls = 0;

long long fibNaive(int n)
{
    calls++;
    if (n <= 1)
    {
        return n;
    }

    return fibNaive(n - 1) + fibNaive(n - 2);
}

long long fibMemo(int n, long long *memo)
{
    calls++;
    if (n <= 1)
    {
        return n;
    }

    if (memo[n] != -1)
    {
        return memo[n];
    }

    return memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
}

int main()
{
    int n = 40;
    calls = 0;
    long long a = fibNaive(n);
    cout << "fib(40) naive: " << a << "  calls = " << calls << "\n";

    long long *memo = new long long[n + 1];
    for (int i = 0; i <= n; i++)
    {
        memo[i] = -1;
    }

    calls = 0;
    long long b = fibMemo(n, memo);
    cout << "fib(40) memo : " << b << "  calls = " << calls << "\n";
    delete[] memo;
    return 0;
}