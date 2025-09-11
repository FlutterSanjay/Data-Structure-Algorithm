// Maximum Sum of Non-Adjacent Elements
#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int> &arr, int n, vector<int> &dp)
{
    if (n == 0)
        return arr[n];

    if (n < 0)
        return 0;

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int pick = arr[n] + maxSum(arr, n - 2, dp);
    int notPick = 0 + maxSum(arr, n - 1, dp);
    dp[n] = max(pick, notPick);
    return dp[n];
}

int maxFunction(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    return maxSum(arr, n - 1, dp);
}
int main()
{
    vector<int> arr = {2, 1, 4, 9};
    cout << maxFunction(arr);
    return 0;
}