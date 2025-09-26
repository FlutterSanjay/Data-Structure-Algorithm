// Longest common sbsequence
#include <bits/stdc++.h>
using namespace std;

int func(int ind1, int ind2, string &str1, string &str2, vector<vector<int>> &dp)
{
    // Base Case
    if (ind1 < 0 || ind2 < 0)
    {
        return 0;
    }

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (str1[ind1] == str2[ind2])
    {
        return dp[ind1][ind2] = 1 + func(ind1 - 1, ind2 - 1, str1, str2, dp);
    }
    return dp[ind1][ind2] = 0 + max(func(ind1 - 1, ind2, str1, str2, dp), func(ind1, ind2 - 1, str1, str2, dp));
}

int main()
{
    string str1 = "adebc";
    string str2 = "dcadb";

    int n1 = str1.length();
    int n2 = str2.length();
    vector<vector<int>> dp(n1, vector<int>(n2 + 1, -1));
    cout << func(n1 - 1, n2 - 1, str1, str2, dp);
    return 0;
}