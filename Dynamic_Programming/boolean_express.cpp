//  Boolean Expression
#include <bits/stdc++.h>
using namespace std;
int mod = 1e9;
int func(int i, int j, bool isTrue, string &arr, vector<vector<vector<int>>> &dp)
{

    if (i > j)
        return 0;

    if (i == j)
    {
        if (isTrue == 1)
            return arr[i] == 'T';
        else
            return arr[i] == 'F';
    }
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    int ways = 0;

    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        int lt = func(i, ind - 1, 1, arr, dp);
        int lf = func(i, ind - 1, 0, arr, dp);
        int rt = func(ind + 1, j, 1, arr, dp);
        int rf = func(ind + 1, j, 0, arr, dp);

        if (arr[ind] == '&')
        {
            if (isTrue)
                ways = (ways + (rt * lt) % mod) % mod;

            else
                ways = (ways + (lt * rf) % mod + (lf * rt) % mod + (lf * rf) % mod) % mod;
        }
        else if (arr[ind] == '|')
        {
            if (isTrue)
            {
                ways = (ways + (lt * rt) % mod + (lt * rf) % mod + (lf * rt) % mod) % mod;
            }
            else
            {
                ways = (ways + (rf * lf) % mod) % mod;
            }
        }
        else
        {
            if (isTrue)
            {
                ways = (ways + (lt * rf) % mod + (lf * rt) % mod) % mod;
            }
            else
            {
                ways = (ways + (lt * rt) % mod + (lf * rf) % mod) % mod;
            }
        }
    }
    return ways;
}
int main()
{
    string arr = "F|T^F";
    int n = arr.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));

    cout << func(0, n - 1, 1, arr, dp);

    return 0;
}