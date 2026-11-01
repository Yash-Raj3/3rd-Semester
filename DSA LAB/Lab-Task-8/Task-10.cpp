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

int countAll(int board[], int n, int row)
{
    if (row == n)
    {
        return 1;
    }

    int c = 0;
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row] = col;
            c += countAll(board, n, row + 1);
            board[row] = -1;
        }
    }
    return c;
}

int main()
{
    int n = 8;
    int board[8];
    for (int i = 0; i < n; i++)
        board[i] = -1;
    cout << "N = 8 total solutions: " << countAll(board, n, 0) << "\n";
    return 0;
}