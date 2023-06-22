#include <iostream>

using namespace std;

int n = 5;
int m = 6;

int map[5][6] = {
    {1, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0, 1},
    {0, 0, 1, 0, 1, 1}};

bool flag[5][6] = {
    {false, false, false, false, false, false},
    {false, false, false, false, false, false},
    {false, false, false, false, false, false},
    {false, false, false, false, false, false},
    {false, false, false, false, false, false}};

void loang(int i, int j)
{
    flag[i][j] = true;

    if (i - 1 > -1 && map[i - 1][j] == map[i][j] && !flag[i - 1][j])
    {
        loang(i - 1, j);
    }
    if (i + 1 < n && map[i + 1][j] == map[i][j] && !flag[i + 1][j])
    {
        loang(i + 1, j);
    }
    if (j - 1 > -1 && map[i][j - 1] == map[i][j] && !flag[i][j - 1])
    {
        loang(i, j - 1);
    }
    if (j + 1 < m && map[i][j + 1] == map[i][j] && !flag[i][j + 1])
    {
        loang(i, j + 1);
    }
}

int countingArea()
{
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!flag[i][j])
            {
                loang(i, j);
                count++;
            }
    return count;
}

int main(int argc, char const *argv[])
{
    cout << countingArea();
    
    return 0;
}
