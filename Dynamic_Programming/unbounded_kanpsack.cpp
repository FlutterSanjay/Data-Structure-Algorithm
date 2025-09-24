// Unbounded Kanpsack
#include <bits/stdc++.h>
using namespace std;

int func(int ind, int w, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return (w / wt[0]) * val[0];
    }
    if (dp[ind][w] != -1)
        return dp[ind][w];

    int notTake = 0 + func(ind - 1, w, wt, val, dp);
    int take = INT_MIN;
    if (wt[ind] <= w)
    {
        take = val[ind] + func(ind, w - wt[ind], wt, val, dp);
    }
    return dp[ind][w] = max(take, notTake);
}
int main()
{
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int n = 3;
    int W = 10;
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << func(n - 1, W, wt, val, dp);
    return 0;
}