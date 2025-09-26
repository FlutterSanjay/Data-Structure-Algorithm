// Rod Cutting problem
#include <bits/stdc++.h>
using namespace std;

int func(int ind, int N, vector<int> &price, vector<vector<int>> &dp)
{

    if (ind == 0)
        return (N * price[0]);

    if (dp[ind][N] != -1)
        return dp[ind][N];

    int notTake = 0 + func(ind - 1, N, price, dp);
    int take = INT_MIN;
    int rodLength = ind + 1;
    if (rodLength <= N)
        take = price[ind] + func(ind, N - rodLength, price, dp);

    return dp[ind][N] = max(take, notTake);
}
int main()
{
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    cout << func(n - 1, n, price, dp);

    return 0;
}