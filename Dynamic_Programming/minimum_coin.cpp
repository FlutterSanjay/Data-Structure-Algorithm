// Minimum of coins
#include <bits/stdc++.h>
using namespace std;

int func(int ind, int t, vector<int> &arr, vector<vector<int>> &dp)
{
    // Base case
    if (ind == 0)
    {
        if (t % arr[0] == 0)
            return t / arr[0];
        else
            return 1e9;
    }

    if (dp[ind][t] != -1)
        return dp[ind][t];

    int notTake = 0 + func(ind - 1, t, arr, dp);

    int take = 1e9;
    if (arr[ind] <= t)
    {
        take = 1 + func(ind, t - arr[ind], arr, dp);
    }
    return dp[ind][t] = min(take, notTake);
}
int main()
{
    // Example coins and target
    vector<int> coins = {1, 2, 5}; // available coin denominations
    int target = 11;

    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    int ans = func(n - 1, target, coins, dp);

    if (ans >= 1e9)
        cout << "Not possible to form target " << target << endl;
    else
        cout << "Minimum coins required to form " << target << " = " << ans << endl;

    return 0;
}