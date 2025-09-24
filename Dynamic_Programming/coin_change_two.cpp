// Coins Change 2
#include <bits/stdc++.h>
using namespace std;
int func(int ind, int t, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return (t % arr[0] == 0);
    }

    if (dp[ind][t] != -1)
    {
        return dp[ind][t];
    }

    int notTake = func(ind - 1, t, arr, dp);
    int take = 0;
    if (arr[ind] <= t)
    {
        take = func(ind, t - arr[ind], arr, dp);
    }
    return dp[ind][t] = notTake + take;
}
int main()
{
    vector<int> coin = {1, 2, 3};
    int target = 3;
    int n = coin.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    cout << func(n - 1, target, coin, dp);

    return 0;
}