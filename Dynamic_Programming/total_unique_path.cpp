// Total Unique path
#include <bits/stdc++.h>
using namespace std;
int func(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;

    if (i < 0 || j < 0)
    {
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = func(i - 1, j, dp);
    int left = func(i, j - 1, dp);
    dp[i][j] = up + left;
    return dp[i][j];
}
int main()
{
    int m = 3;
    int n = 3;
    vector<vector<int>> dp(m, vector<int>(n, -1));

    cout << func(m - 1, n - 1, dp);
    return 0;
}

/*

// total Uniue Path
#include <bits/stdc++.h>
using namespace std;

int func(int m, int n, vector<vector<int>> &dp)
{
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)
                {
                    up = dp[i - 1][j];
                }
                if (j > 0)
                {
                    left = dp[i][j - 1];
                }
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}

int main()
{
    int m = 3;
    int n = 3;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << func(m, n, dp);
    return 0;
}

*/