// K -Largest sum SubArray
#include <bits/stdc++.h>
using namespace std;
int KLargestSubArray(vector<int> &arr, int &k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (pq.size() < k)
            {
                pq.emplace(sum);
            }
            else
            {
                if (sum > pq.top())
                {
                    pq.pop();
                    pq.emplace(sum);
                }
            }
        }
    }
    return pq.top();
}

int main()
{
    vector<int> arr = {10, -10, 20, -40};
    int k = 6;

    cout << "Kth Largest Sub-Array :" << KLargestSubArray(arr, k);
    return 0;
}