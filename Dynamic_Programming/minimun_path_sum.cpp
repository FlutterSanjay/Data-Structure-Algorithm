// Minimum Path Sum
#include <bits/stdc++.h>
using namespace std;

int func(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return arr[i][j];

    if (i < 0 || j < 0)
        return INT_MAX;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = func(i - 1, j, arr, dp);
    int left = func(i, j - 1, arr, dp);
    if (up != INT_MAX)
        up += arr[i][j];
    if (left != INT_MAX)
        left += arr[i][j];

    dp[i][j] = min(left, up);
    return dp[i][j];
}

int main()
{
    vector<vector<int>> ans = {
        {1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int m = ans.size();
    int n = ans[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << func(m - 1, n - 1, ans, dp);

    return 0;
}