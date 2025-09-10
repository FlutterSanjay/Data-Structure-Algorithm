// Frog Jump problem k steps
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    int n = heights.size();
    int k = 3;
    vector<int> dp(n, -1);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int mSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if ((i - j) >= 0)
            {
                int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                mSteps = min(mSteps, jump);
            }
        }
        dp[i] = mSteps;
    }
    cout << dp[n - 1];
    return 0;
}