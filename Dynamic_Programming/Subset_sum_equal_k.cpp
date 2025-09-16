// Subset Sum Equal to K
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
    vector<int> arr = {4, 3, 2, 1};
    int target = 5;
    int n = arr.size();

    // dp array with n rows and target+1 columns
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    if (func(n - 1, target, arr, dp))
        cout << "Subset with sum " << target << " exists" << endl;
    else
        cout << "Subset with sum " << target << " does not exist" << endl;

    return 0;
}
