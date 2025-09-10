// Count ways to reach the nth stair (Tabulation Approach)
#include <bits/stdc++.h>
using namespace std;
int climbStairs(int n)
{
    if (n == 1)
        return 1;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    int left = 0;
    int right = 0;
    for (int i = 2; i <= n; i++)
    {
        left = dp[i - 1];
        right = dp[i - 2];
        dp[i] = left + right;
    }
    return left + right;
}
int main()
{
    cout << "Enter the value of n: ";
    int n;
    cin >> n;
    cout << climbStairs(n);
    return 0;
}

/*
// Count Stairs to Reach the Nth Stair (Memoization Approach)
#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n, vector<int> &dp)
{
    // base case
    if (n <= 1)
        return 1;

    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = climbStairs(n - 1, dp) + climbStairs(n - 2, dp);
}

int main()
{
    cout << "Enter the value of n: ";
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << climbStairs(n, dp);
    return 0;
}

*/

/*
// Optimized Space
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int prev2 = 1;
    int prev1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    cout << prev1;
    return 0;
}
    */