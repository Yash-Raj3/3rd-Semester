#include <iostream>
#include <string>
using namespace std;
void swap(char &s, char &d)
{
    char temp = s;
    s = d;
    d = temp;
}
void reverse(string &s, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    swap(s[left], s[right]);
    reverse(s, left + 1, right - 1);
}
int main()
{
    string s;
    cout << "Enter string to Reverse: ";
    // cin.ignore();
    getline(cin, s);
    reverse(s, 0, s.length() - 1);
    cout << "Reversed: " << s << endl;
}