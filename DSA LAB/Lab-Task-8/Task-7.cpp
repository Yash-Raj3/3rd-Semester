
#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    return x < n && y < n && arr[x][y] == 1;
}

bool ratInMaze(int **arr, int x, int y, int n, int **sol)
{
    if (x == n - 1 && y == n - 1 && arr[x][y] == 1)
    {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(arr, x, y, n))
    {
        sol[x][y] = 1;
        if (ratInMaze(arr, x + 1, y, n, sol))
            return true; // down
        if (ratInMaze(arr, x, y + 1, n, sol))
            return true; // right
        sol[x][y] = 0;
        cout << "  backtrack from (" << x << "," << y << ")\n";
        return false;
    }
    return false;
}

void runMaze(const int *m, int n)
{
    int **arr = new int *[n], **sol = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        sol[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = m[i * n + j];
            sol[i][j] = 0;
        }
    }
    if (ratInMaze(arr, 0, 0, n, sol))
    {
        cout << "Path found:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << sol[i][j] << ' ';
            cout << '\n';
        }
    }
    else
        cout << "No path.\n";
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
        delete[] sol[i];
    }
    delete[] arr;
    delete[] sol;
}

int main()
{
    const int M4[16] = {1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1};
    const int M3[9] = {1, 1, 1, 1, 0, 1, 0, 0, 1};
    cout << "4x4 maze:\n";
    runMaze(M4, 4);
    cout << "\n3x3 maze:\n";
    runMaze(M3, 3);
    return 0;
}
