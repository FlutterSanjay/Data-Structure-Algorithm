//  Count of Subsets with given Difference
#include <bits/stdc++.h>
using namespace std;
int mod = (int)(1e9 + 7);
int findWays(vector<int> &nums, int tar)
{
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    if (nums[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (nums[0] != 0 && nums[0] <= tar)
        dp[0][nums[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int notTake = dp[ind - 1][sum];
            int take = 0;

            if (nums[ind] <= sum)
                take = dp[ind - 1][sum - nums[ind]];

            dp[ind][sum] = (take + notTake) % mod;
        }
    }
    return dp[n - 1][tar];
}
int CountPartition(int n, int d, vector<int> &arr)
{

    int totalSum = 0;
    for (auto &it : arr)
        totalSum += it;

    if (totalSum - d < 0 || (totalSum - d) % 2)
        return false;

    return findWays(arr, (totalSum - d) / 2);
}

int main()
{
    vector<int> arr = {5, 2, 6, 4};
    int n = arr.size();
    int d = 3;
    cout << CountPartition(n, d, arr);

    return 0;
}