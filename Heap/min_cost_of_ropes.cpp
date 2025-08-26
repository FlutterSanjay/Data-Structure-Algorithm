// find min cost  of ropes
#include <bits/stdc++.h>
using namespace std;

int minCost(vector<int> &arr)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);
    }

    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int sum = a + b;
        ans += sum;
        pq.emplace(sum);
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 3, 2, 6};
    int result = minCost(arr);
    cout << "Minimum Cost : " << result;

    return 0;
}