// Smallest Range in K lists
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    int row;
    int col;
    Node(int d, int r, int c)
    {
        this->data = d;
        this->row = r;
        this->col = c;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

int SmallestRangeKList(vector<vector<int>> &arr, int k)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    for (int i = 0; i < k; i++)
    {
        int element = arr[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Node(element, i, 0));
    }
    int ansStart = mini;
    int ansEnd = maxi;

    // For Min
    while (!minHeap.empty())
    {
        Node *temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        if (maxi - mini < ansEnd - ansStart)
        {
            ansStart = mini;
            ansEnd = maxi;
        }

        if (temp->col + 1 < arr[temp->row].size())
        {
            maxi = max(maxi, arr[temp->row][temp->col + 1]);
            minHeap.push(new Node(arr[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }
        else
        {
            break;
        }
    }
    return (ansEnd - ansStart + 1);
}

int main()
{
    vector<vector<int>> arr = {
        {1, 10, 11},
        {2, 3, 20},
        {5, 6, 12}};

    int k = arr.size();

    int result = SmallestRangeKList(arr, k);
    cout << "The Smallest Range : " << result;
    return 0;
    // printLL(head3);
}