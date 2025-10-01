// Best Time TO Buy and Sell Stock
#include <bits/stdc++.h>
using namespace std;
int func(int ind, int buy, int cap, vector<int> &price, vector<vector<vector<int>>> &dp)
{
    // Base case
    if (ind == price.size())
        return 0;

    if (cap == 0)
        return 0;

    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];

    int profit = 0;
    if (buy)
    {
        profit = max(-price[ind] + func(ind + 1, 0, cap, price, dp), 0 + func(ind + 1, 1, cap, price, dp));
    }
    else
    {
        profit = max(price[ind] + func(ind + 1, 1, cap - 1, price, dp), 0 + func(ind + 1, 0, cap, price, dp));
    }
    return dp[ind][buy][cap] = profit;
}
int main()
{
    vector<int> price = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = price.size();
    int cap = 2;

    // DP table: dp[ind][buy][cap]
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(cap + 1, -1)));

    cout << func(0, 1, cap, price, dp);

    return 0;
}