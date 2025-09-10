// Frog Jump problem k steps
#include <bits/stdc++.h>
using namespace std;
int fromJumpK(vector<int> &heights, int n, int k, vector<int> &dp)
{

    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int minSteps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {

        if ((n - j) >= 0)
        {
            int jump = fromJumpK(heights, n - j, k, dp) + abs(heights[n] - heights[n - j]);
            minSteps = min(minSteps, jump);
        }
    }
    return dp[n] = minSteps;
}

int main()
{
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    int n = heights.size();
    int k = 3;
    vector<int> dp(n, -1);
    cout << fromJumpK(heights, n - 1, k, dp);
    return 0;
}
/*
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
*/