// WildCard Matching
#include <bits/stdc++.h>
using namespace std;

int func(int n, int m, string &pattern, string &text, vector<vector<bool>> &dp)
{

    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        bool flag = true;

        for (int ii = 1; ii <= i; ii++)
        {
            if (pattern[ii - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (pattern[i - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string s = "aa";
    string a = "*";
    int n = s.size();
    int m = a.size();

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    cout << func(m, n, a, s, dp);

    return 0;
}