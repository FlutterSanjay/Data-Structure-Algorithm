// Distinct Subsequence
#include <bits/stdc++.h>
using namespace std;

int func(int n, int m, string &s, string &t, vector<vector<int>> &dp)
{
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int j = 1; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string s = "rabbbit";
    string t = "rabbit";
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    cout << func(n, m, s, t, dp);

    return 0;
}
