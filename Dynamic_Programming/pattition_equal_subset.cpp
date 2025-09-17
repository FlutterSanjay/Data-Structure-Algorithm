#include <bits/stdc++.h>
using namespace std;

int func(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;

    if (ind == 0)
        return (arr[0] == target);

    if (dp[ind][target] != -1)
        return dp[ind][target];
    bool notTake = func(ind - 1, target, arr, dp);

    bool take = false;

    if (target >= arr[ind])
        take = func(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = take || notTake;
}
int main()
{
    vector<int> arr = {1, 5, 11, 5};
    int TotalSum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
        TotalSum += arr[i];

    if (TotalSum % 2)
        return false;

    int target = TotalSum / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    cout << func(n - 1, target, arr, dp);
    return 0;
}