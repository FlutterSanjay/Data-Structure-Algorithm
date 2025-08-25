// Merge two Max-Heap
#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr, int n, int i)
{
    int index = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    int largest = index;

    if (leftChild <= n && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }
    if (rightChild <= n && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }
    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        index = largest;
        heapify(arr, n, index);
    }
}

void heapifyBuild(vector<int> &arr, int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
vector<int> MergeTwo(vector<int> &arr, vector<int> &brr)
{
    int m = arr.size();
    int n = brr.size();
    vector<int> c;

    for (int i = 0; i < m; i++)
    {
        c.push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        c.push_back(brr[i]);
    }
    int size = c.size();

    heapifyBuild(c, size);
    return c;
}

int main()
{
    vector<int> arr = {10, 5, 6, 2};
    vector<int> brr = {12, 7, 9};
    vector<int> result = MergeTwo(arr, brr);
    for (auto i : result)
    {
        cout << i << " ";
    }
    return 0;
}