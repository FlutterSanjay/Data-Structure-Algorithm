// House Robber II
#include <bits/stdc++.h>
using namespace std;

int sumFunction(vector<int> &arr)
{
    int n = arr.size();
    int prev = arr[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if (i > 1)
        {
            pick += prev2;
        }
        int nonPick = 0 + prev;
        int curr = max(pick, nonPick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int findSum(vector<int> &nums)
{
    int n = nums.size();

    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            temp1.push_back(nums[i]);
        }
        if (i != n - 1)
        {
            temp2.push_back(nums[i]);
        }
    }
    int ans1 = sumFunction(temp1);
    int ans2 = sumFunction(temp2);
    return max(ans1, ans2);
}
int main()
{

    vector<int> nums = {2, 3, 2};
    cout << findSum(nums);
    return 0;
}