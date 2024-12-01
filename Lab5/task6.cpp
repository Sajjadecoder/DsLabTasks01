#include <iostream>
using namespace std;
bool isSafe(int **board, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j < 4; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}
void print(int **board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}
void maxFlags(int **board, int n, int row,bool &exist)
{
    if (row >= n)
    {
        exist = true;
        cout<<"Possible positions of the flags\n";
        print(board,n);
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;
             maxFlags(board, n, row + 1,exist);
            
            board[row][col] = 0;
        }
    }
    
}
int main()
{   int n = 4;
    int **board = new int*[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n]{0};
    }
    bool exist = false;
    maxFlags(board,n, 0,exist);
    if (exist) {
        cout<<"Total flags that can be placed on the grid: "<<n;
    } else {
        cout << "No solution exists.\n";
    }
    for (int i = 0; i < n; i++)
    {
        delete board[i];
    }
    delete [] board;
    
    return 0;
}