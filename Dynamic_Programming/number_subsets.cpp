// Number of subsets
#include <bits/stdc++.h>
using namespace std;

int func(int ind, int s, vector<int> &arr, vector<vector<int>> &dp)
{
    if (s == 0)
        return 1;

    if (ind == 0)
        return (arr[ind] == s);

    if (dp[ind][s] != -1)
        return dp[ind][s];

    int notPick = func(ind - 1, s, arr, dp);
    int pick = 0;
    if (arr[ind] <= s)
        pick = func(ind - 1, s - arr[ind], arr, dp);

    return dp[ind][s] = pick + notPick;
}

int main()
{
    vector<int> arr = {1, 2, 2, 3};
    int s = 4;
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(s + 1, -1));
    cout << func(n - 1, s, arr, dp);

    return 0;
}

/*
Tabulation form

// Number of subsets
#include <bits/stdc++.h>
using namespace std;

int func(int ind, int s, vector<int> &arr, vector<vector<int>> &dp)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    if (arr[0] <= s)
        dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= s; j++)
        {

            int notPick = dp[i - 1][j];
            int pick = 0;
            if (arr[i] <= j)
                pick = dp[i - 1][j - arr[i]];

            dp[i][j] = pick + notPick;
        }
    }

    return dp[n - 1][s];
}

int main()
{
    vector<int> arr = {1, 2, 2, 3};
    int s = 3;
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(s + 1, 0));
    cout << func(n - 1, s, arr, dp);

    return 0;
}
 */