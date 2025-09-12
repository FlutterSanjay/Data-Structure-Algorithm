// Maze Obstacles
#include <bits/stdc++.h>
using namespace std;

int func(int i, int j, vector<vector<int>> &ans, vector<vector<int>> &dp)
{

    if (i >= 0 && j >= 0 && ans[i][j] == -1)
        return 0;
    if (i == 0 && j == 0)
        return 1;

    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = func(i - 1, j, ans, dp);
    int left = func(i, j - 1, ans, dp);
    return dp[i][j] = up + left;
}

int main()
{
    vector<vector<int>> ans = {
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}

    };
    int m = ans.size();
    int n = ans[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    cout << func(m - 1, n - 1, ans, dp);
    return 0;
}