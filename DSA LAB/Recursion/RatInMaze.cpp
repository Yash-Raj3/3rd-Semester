#include <iostream>
using namespace std;

void rat(int (&m)[4][4], int n, int r, int c, string path)
{
    if (r < 0 || c < 0 || r >= n || c >= n || m[r][c] == 0 || m[r][c] == -1)
    {
        return;
    }
    if (r == n - 1 && c == n - 1)
    {
        cout << path << endl;
        return;
    }
    m[r][c] = -1;
    rat(m, n, r + 1, c, path + "D");
    rat(m, n, r - 1, c, path + "U");
    rat(m, n, r, c + 1, path + "R");
    rat(m, n, r, c - 1, path + "L");
    m[r][c] = 1;
}

int main()
{
    int n = 4;
    int maze[4][4] = {
        {1, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {0, 0, 1, 1}};
    string s = "";
    rat(maze, n, 0, 0, s);
}