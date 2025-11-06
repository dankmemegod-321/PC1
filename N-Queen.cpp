#include <iostream>
using namespace std;

#define MAX 10

char board[MAX][MAX];
int n;

// Function to print the board
void printBoard()
{
    cout << "\nFinal N-Queens Board:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a queen can be placed at board[row][col]

bool isSafe(int row, int col)
{
    int i, j;

    // Check column
    for (i = 0; i < row; i++)
        if (board[i][col] == 'Q')
            return false;

    // Check upper-left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    // Check upper-right diagonal
    for (i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

// Backtracking function to solve N-Queens
bool solveNQueens(int row)
{
    if (row >= n)
        return true;

    for (int col = 0; col < n; col++)
    {
        if (board[row][col] == 'Q')
        {
            // Skip row if queen already placed here
            if (solveNQueens(row + 1))

                return true;
        }
        else if (isSafe(row, col))
        {
            board[row][col] = 'Q';
            if (solveNQueens(row + 1))
                return true;
            board[row][col] = '-'; // Backtrack
        }
    }
    return false;
}

int main()
{
    cout << "Enter size of board (N): ";
    cin >> n;

    // Initialize board with '-'
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = '-';

    int r, c;
    cout << "Enter position of first Queen (row and column starting from 0): ";
    cin >> r >> c;

    // Place first Queen
    board[r][c] = 'Q';

    // Start solving from next row
    if (solveNQueens(0))
        printBoard();

    else
        cout << "No solution exists for given placement.";

    return 0;
}