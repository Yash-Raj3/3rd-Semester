#include <iostream>
using namespace std;
bool isSafe(int **board, int row, int col, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}
void print(int **board, int n)
{

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                cout << "Q ";
            }

            if (board[i][j] == 0)
            {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
void PlaceQueens(int **board, int row, int n)
{
    if (row == n)
    {
        print(board, n);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, row, i, n))
        {
            board[row][i] = 1;
            PlaceQueens(board, row + 1, n);
            board[row][i] = 0;
        }
    }
}

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;
    if (n < 1)
    {
        return 0;
    }
    int **board = new int *[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    PlaceQueens(board, 0, n);

    for (int i = 0; i < n; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}