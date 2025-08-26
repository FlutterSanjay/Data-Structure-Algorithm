// Merge K Sortest Array
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    int row;
    int col;
    Node(int d, int row, int col)
    {
        this->data = d;
        this->row = row;
        this->col = col;
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
vector<int> MergeKArray(vector<vector<int>> &arr, int k)
{
    priority_queue<Node *, vector<Node *>, compare> pq;

    for (int i = 0; i < k; i++)
    {
        Node *tmp = new Node(arr[i][0], i, 0);
        pq.emplace(tmp);
    }

    vector<int> ans;
    while (pq.size() > 0)
    {
        Node *temp = pq.top();
        ans.push_back(temp->data);

        pq.pop();

        int i = temp->row;
        int j = temp->col;

        if (j + 1 < arr[i].size())
        {
            Node *temp = new Node(arr[i][j + 1], i, j + 1);
            pq.push(temp);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4}, {2, 2, 3, 4}, {5, 5, 6, 6}, {7, 8, 9, 9}};
    int k = 4;

    vector<int> result = MergeKArray(arr, k);
    for (auto i : result)
    {
        cout << i << " ";
    }

    return 0;
}