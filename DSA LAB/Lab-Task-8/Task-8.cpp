#include <iostream>
using namespace std;

bool isSafe(int **arr, int **vis, int x, int y, int n)
{
    return x >= 0 && y >= 0 && x < n && y < n && arr[x][y] == 1 && !vis[x][y];
}

bool ratInMaze(int **arr, int **vis, int x, int y, int n, int **sol)
{
    if (!isSafe(arr, vis, x, y, n))
        return false;
    vis[x][y] = 1;
    sol[x][y] = 1;
    if (x == n - 1 && y == n - 1)
        return true;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    for (int d = 0; d < 4; d++)
        if (ratInMaze(arr, vis, x + dx[d], y + dy[d], n, sol))
            return true;
    sol[x][y] = 0;
    cout << "  backtrack from (" << x << "," << y << ")\n";
    return false;
}

void runMaze(const int *m, int n)
{
    int **arr = new int *[n], **sol = new int *[n], **vis = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        sol[i] = new int[n];
        vis[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = m[i * n + j];
            sol[i][j] = 0;
            vis[i][j] = 0;
        }
    }
    if (ratInMaze(arr, vis, 0, 0, n, sol))
    {
        cout << "Path found:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << sol[i][j] << ' ';
            }

            cout << '\n';
        }
    }
    else
        cout << "No path.\n";
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
        delete[] sol[i];
        delete[] vis[i];
    }
    delete[] arr;
    delete[] sol;
    delete[] vis;
}

int main()
{
    const int M4[16] = {1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1};
    const int M5[25] = {1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1}; // needs up moves
    cout << "4x4 maze:\n";
    runMaze(M4, 4);
    cout << "\n5x5 maze (needs up moves):\n";
    runMaze(M5, 5);
    return 0;
}