// Burst Ballon
#include <bits/stdc++.h>
using namespace std;
int func(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    int maxi = INT_MIN;

    for (int ind = i; ind <= j; ind++)
    {
        int cost = arr[i - 1] * arr[ind] * arr[j + 1] + func(i, ind - 1, arr, dp) + func(ind + 1, j, arr, dp);
        maxi = max(maxi, cost);
    }
    return dp[i][j] = maxi;
}
int main()
{
    vector<int> arr = {3, 1, 5, 8}; // ✅ Example input balloons
    int n = arr.size();
    // add boundaries
    arr.push_back(1);
    arr.insert(arr.begin(), 1);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    cout << func(1, n, arr, dp); // ✅ correct range

    return 0;
}