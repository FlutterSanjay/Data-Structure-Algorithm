// Remove Stones to Minimize Total
#include <bits/stdc++.h>
using namespace std;

int RemoveStones(vector<int> &arr, int n, int k)
{
    priority_queue<int> maxHeap;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int element = arr[i];
        maxHeap.push(element);
        sum += element;
    }

    for (int i = 0; i < k; i++)
    {
        int element = maxHeap.top();
        maxHeap.pop();
        int remove = floor(element / 2);
        element -= remove;
        maxHeap.push(element);
        sum -= remove;
    }
    return sum;
}
int main()
{
    vector<int> arr = {5, 4, 9};
    int n = arr.size();
    int k = 2;
    int result = RemoveStones(arr, n, k);
    cout << " Total : " << result;
    return 0;
}
