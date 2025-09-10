// Frog Jump Problem
#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &dp, vector<int> &height)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
    {
        return dp[n];
    }
    int left = frogJump(n - 1, dp, height) + abs(height[n] - height[n - 1]);
    int right = INT_MAX;
    if (n > 1)
        right = frogJump(n - 2, dp, height) + abs(height[n] - height[n - 2]);
    return dp[n] = min(left, right);
}
int main()
{
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    int n = heights.size();
    vector<int> dp(n + 1, -1);
    cout << frogJump(n - 1, dp, heights);
    return 0;
}

/*
//  Frog Jump (Tabulation Method)
#include <bits/stdc++.h>
using namespace std;
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    int left = 0;
    int right = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        if (i > 1)
        {
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp[i] = min(left, right);
    }
    return dp[n - 1];
    // Write your code here.
}
int main()
{

    vector<int> height = {30, 10, 60, 10, 60, 50};
    int n = height.size();
    cout << frogJump(n, height);
    return 0;
}
    */