#include <iostream>
using namespace std;

void towerOfhanoi(int n, char src, char aux, char dest)
{
    if (n == 1)
    {
        cout << "Move disk from " << src << " to " << dest << endl;
        return;
    }

    towerOfhanoi(n - 1, src, dest, aux);
    cout << "Move disk from " << src << " to " << dest << endl;
    towerOfhanoi(n - 1, aux, src, dest);
}

int main()
{
    int disk;
    cout << "Enter Number of Disks: ";
    cin >> disk;
    towerOfhanoi(disk, 'A', 'B', 'C');
}