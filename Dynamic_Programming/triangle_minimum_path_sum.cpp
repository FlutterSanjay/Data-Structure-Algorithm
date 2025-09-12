// Triangle Minimum Path Sum
#include <bits/stdc++.h>
using namespace std;

int func(vector<vector<int>> &arr, int n, int i, int j)
{
    if (i == n - 1)
        return arr[n - 1][j];

    int down = arr[i][j] + func(arr, n, i + 1, j);
    int diagonal = arr[i][j] + func(arr, n, i + 1, j + 1);
    return min(down, diagonal);
}
int main()
{
    vector<vector<int>> arr = {
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 1}};
    int n = arr.size();

    cout << func(arr, n, 0, 0);

    return 0;
}