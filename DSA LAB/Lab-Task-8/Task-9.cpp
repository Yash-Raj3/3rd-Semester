#include <iostream>
using namespace std;

int myAbs(int a) { return a < 0 ? -a : a; }

bool isSafe(int board[], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col || myAbs(board[i] - col) == myAbs(i - row))
        {
            return false;
        }
    }

    return true;
}

bool solveNQueens(int board[], int n, int row = 0)
{
    if (row == n)
    {
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row] = col;
            if (solveNQueens(board, n, row + 1))
                return true;
            board[row] = -1;
        }
    }
    return false;
}

int main()
{
    int sizes[6] = {2, 3, 4, 5, 6, 8};
    for (int k = 0; k < 6; k++)
    {
        int n = sizes[k];
        int *b = new int[n];
        for (int i = 0; i < n; i++)
        {
            b[i] = -1;
        }

        cout << "\nN = " << n << ": ";
        if (solveNQueens(b, n))
        {
            cout << "solution\n";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    cout << (b[i] == j ? "Q " : ". ");
                cout << '\n';
            }
        }
        else
            cout << "no solution exists\n";
        delete[] b;
    }
    return 0;
}