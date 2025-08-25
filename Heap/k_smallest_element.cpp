// k-smallest element
#include <bits/stdc++.h>
using namespace std;

int KSmallest(int arr[], int n, int k)
{
    if (k > n)
    {
        return -1;
    }
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main()
{
    int arr[5] = {7, 10, 4, 20, 15};
    int n = 5;
    int k = 6;
    cout << KSmallest(arr, n, k);

    return 0;
}