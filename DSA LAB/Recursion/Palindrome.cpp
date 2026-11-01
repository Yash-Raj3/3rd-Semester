#include <iostream>
using namespace std;

bool check(string s, int l, int h)
{

    if (l >= h)
    {
        return true;
    }
    if (s[l] != s[h])
    {
        return false;
    }
    check(s, l + 1, h - 1);
}

int main()
{
    string s;
    cout << "Enter String: ";
    cin >> s;
    if (check(s, 0, s.length() - 1))
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome!" << endl;
    }
}