// Maximum Sum of Non-Adjacent Elements using Tabulation Approach
#include <bits/stdc++.h>
using namespace std;
int maxSum(vector<int> &arr, int n)
{
    vector<int> dp(n, -1);
    dp[0] = arr[0];
    int neg = 0;
    for (int i = 1; i < n; i++)
    {
        int pick = arr[n];
        if (i > 1)
        {
            pick += dp[i - 2];
        }
        int nonPick = 0 + dp[i - 1];
        dp[i] = max(pick, nonPick);
    }
    return dp[n - 1];
}

int main()
{
    vector<int> arr = {2, 1, 4, 9};
    int n = arr.size();
    cout << maxSum(arr, n - 1);

    return 0;
}