/*
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    // base case: first row
    for (int j = 0; j < n; j++) {
        dp[0][j] = matrix[0][j];
    }

    // fill dp table
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {

            int s = matrix[i][j] + dp[i - 1][j]; // straight

            int ld = matrix[i][j];
            if (j - 1 >= 0) ld += dp[i - 1][j - 1];
            else ld += -1e9;

            int rd = matrix[i][j];
            if (j + 1 < n) rd += dp[i - 1][j + 1];
            else rd += -1e9;

            dp[i][j] = max(s, max(ld, rd));
        }
    }

    // find max in last row
    int maxi = dp[m - 1][0];
    for (int j = 1; j < n; j++) {
        maxi = max(maxi, dp[m - 1][j]);
    }
    return maxi;
}

*/
// Maximum path sum in the Matrix.
#include <bits/stdc++.h>
using namespace std;

int maximumPath(vector<vector<int>> &arr, int i, int j, vector<vector<int>> &dp)
{
    int m = arr[0].size();
    if (j < 0 || j >= m)
        return -1e9; // invalid column
    if (i == 0)
        return arr[0][j]; // base case - top row

    if (dp[i][j] != -1)
        return dp[i][j];

    int s = arr[i][j] + maximumPath(arr, i - 1, j, dp);      // straight up
    int ld = arr[i][j] + maximumPath(arr, i - 1, j - 1, dp); // left diagonal
    int rd = arr[i][j] + maximumPath(arr, i - 1, j + 1, dp); // right diagonal

    return dp[i][j] = max(s, max(ld, rd));
}

int main()
{
    vector<vector<int>> arr = {
        {1, 2, 10, 4},
        {100, 3, 2, 1},
        {1, 1, 20, 2},
        {1, 2, 2, 1}};

    int n = arr.size();
    int m = arr[0].size();
    int ans = -1e9;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    // check all possible ending points in last row
    for (int j = 0; j < m; j++)
    {
        ans = max(ans, maximumPath(arr, n - 1, j, dp));
    }

    cout << ans << endl; // ✅ print answer

    return 0;
}
