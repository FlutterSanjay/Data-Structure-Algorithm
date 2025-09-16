// Ninja and it's Friend
#include <bits/stdc++.h>
using namespace std;

int func(int i, int j1, int j2, int m, int r, vector<vector<int>> &arr, vector<vector<vector<int>>> &dp)
{

    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
    {
        return -1e8;
    }

    if (i == r - 1)
    {
        if (j1 == j2)
            return arr[i][j1];
        else
        {
            return arr[i][j1] + arr[i][j2];
        }
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    // Explore all Part
    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value;
            if (j1 == j2)
                value = arr[i][j1] + func(i + 1, j1 + dj1, j2 + dj2, m, r, arr, dp);
            else
            {
                value = arr[i][j1] + arr[i][j2] + func(i + 1, j1 + dj1, j2 + dj2, m, r, arr, dp);
            }
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int main()
{
    vector<vector<int>> arr = {
        {2, 3, 1},
        {5, 10, 5},
        {8, 2, 4}};

    int n = arr.size(), m = arr[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    int result = func(0, 0, m - 1, m, n, arr, dp);

    cout << "Max Chocolates = " << result << endl;

    return 0;
}