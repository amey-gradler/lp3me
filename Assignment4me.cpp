#include <bits/stdc++.h>
#define N 4
using namespace std;

void display(vector<vector<string>> &ans)
{
    int sz = ans.size();
    for (int i = 0; i < sz; i++)
    {
        vector<string> aa = ans[i];
        int szn = aa.size();
        cout << "Solution No : " << i + 1 << endl;
        for (int j = 0; j < szn; j++)
        {
            cout << aa[j] << endl;
        }
    }
}

bool isSafe(int row, int col, vector<string> &board, int n)
{
    int dupRow = row;
    int dupCol = col;

    // check upper diag
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    row = dupRow;
    col = dupCol;
    // check row
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    row = dupRow;
    col = dupCol;
    // check lower diag
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
}

void solve(int col, vector<string> &board, int n, vector<vector<string>> &ans)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, n, ans);
            board[row][col] = '.';
        }
    }
    return;
}

int solveNQueens(int n)
{

    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    solve(0, board, n, ans);
    // display(ans);
    return ans.size();
}

int main()
{
    cout << "No of solutions: " << endl;
    cout << solveNQueens(5);
    return 0;
}