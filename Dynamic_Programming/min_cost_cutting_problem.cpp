#include <bits/stdc++.h>
using namespace std;

int func(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;
    for (int ind = i; ind <= j; ind++) // ✅ fixed loop: start from i not 1
    {
        int cost = arr[j + 1] - arr[i - 1] +
                   func(i, ind - 1, arr, dp) +
                   func(ind + 1, j, arr, dp);

        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}

int main()
{
    vector<int> arr = {1, 3, 4};
    int n = arr.size();
    int c = 5;

    arr.push_back(c);
    arr.insert(arr.begin(), 0);
    sort(arr.begin(), arr.end());

    int m = arr.size();
    vector<vector<int>> dp(m, vector<int>(m, -1));

    cout << func(1, m - 2, arr, dp);
    return 0;
}
