#include <bits/stdc++.h>
using namespace std;

int func(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j]; // corrected from 'return -1;' to 'return dp[i][j];'

    int mini = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int steps = (arr[i - 1] * arr[k] * arr[j]) + func(i, k, arr, dp) + func(k + 1, j, arr, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}

int main()
{
    vector<int> arr = {4, 5, 3, 2};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    int result = func(1, n - 1, arr, dp);

    cout << "Minimum number of multiplications: " << result << endl;
    return 0;
}
