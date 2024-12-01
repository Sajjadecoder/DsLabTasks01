#include <iostream>
using namespace std;
bool isSafe(int x, int y, int maze[4][4], int n)
{
    if (x < n && x >= 0 && y < n && y >= 0)
    {
        if (maze[x][y] == 1)
        {
            return true;
        }
    }
    return false;
}
void print(int arr[4][4], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool findPaths(int maze[4][4], int solutionArr[4][4], int x, int y, int n, bool &exist)
{
    if (x == n - 1 && y == n - 1)
    {
        solutionArr[x][y] = 1;
        cout<<"Possible route\n";
        print(solutionArr, n);
        solutionArr[x][y] = 0;
        exist = true;
        return false;
    }
    if (isSafe(x, y, maze, n))
    {
        solutionArr[x][y] = 1;
        findPaths(maze, solutionArr, x + 1, y, n, exist);
        findPaths(maze, solutionArr, x, y + 1, n, exist);
        solutionArr[x][y] = 0;
    }
    return false;
}

int main()
{
    int maze[4][4] = {{1, 1, 1, 1},
                      {1, 0, 1, 0},
                      {1, 1, 1, 0},
                      {0, 1, 1, 1}};
    int solutionArr[4][4]{{0}};
    bool exist = false;
    cout<<"Original maze\n";
    print(maze,4);
    findPaths(maze, solutionArr, 0, 0, 4, exist);
    if (!exist)
    {
        cout << "No path found" << endl;
    }
    return 0;
}