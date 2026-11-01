#include <iostream>
using namespace std;
bool CheckPalindrome(string s, int st, int e)
{

    if (st >= e)
    {
        return true;
    }

    if (s[st] != s[e])
    {
        return false;
    }
    else
    {
        return CheckPalindrome(s, st + 1, e - 1);
    }
}
int main()
{
    string s;
    cout << "Enter string to check Palindrome: ";
    cin >> s;

    if (CheckPalindrome(s, 0, s.length() - 1))
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not a Palindrome!" << endl;
    }
}