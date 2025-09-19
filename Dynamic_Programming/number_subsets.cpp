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