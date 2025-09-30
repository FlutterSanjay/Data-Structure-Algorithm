// Buy and Sell Stock- II
#include <bits/stdc++.h>
using namespace std;

int func(int ind, int buy, vector<int> &arr, vector<vector<int>> &dp, int n)
{
    if (ind == n)
        return 0;

    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    int profit = 0;
    if (buy)
    {
        profit = max(-arr[ind] + func(ind + 1, 0, arr, dp, n), 0 + func(ind + 1, 1, arr, dp, n));
    }
    else
    {
        profit = max(arr[ind] + func(ind + 1, 1, arr, dp, n), 0 + func(ind + 1, 0, arr, dp, n));
    }
    return dp[ind][buy] = profit;
}
int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << func(0, 1, arr, dp, n);

    return 0;
}