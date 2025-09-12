// Ninja trainig using Tabulation Approch
#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp, int n)
{
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][0], points[0][1]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last <= 3; last++)
        {
            dp[day][last] = 0;

            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n - 1][3];
}

int main()
{

    vector<vector<int>> arr = {
        {10, 40, 70}, // Day 1
        {20, 50, 80}, // Day 2
        {30, 60, 90}  // Day 3
    };
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    cout << ninjaTraining(n - 1, 3, arr, dp, n);
    return 0;
}