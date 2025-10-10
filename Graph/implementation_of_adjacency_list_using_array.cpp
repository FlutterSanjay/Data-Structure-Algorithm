#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
    vector<int> ans[n];

    // Build adjacency list (undirected)
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    // ✅ FIX: initialize adj with size n
    vector<vector<int>> adj(n);

    // Add nodes and their connections
    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(i); // first element is the node
        for (int j = 0; j < ans[i].size(); j++)
        {
            adj[i].push_back(ans[i][j]);
        }
    }

    return adj;
}

int main()
{
    int n = 5; // number of nodes
    int m = 6; // number of edges

    vector<vector<int>> edges = {
        {0, 1},
        {0, 4},
        {1, 2},
        {1, 3},
        {1, 4},
        {2, 3}};

    vector<vector<int>> adj = printAdjacency(n, m, edges);

    cout << "Adjacency List:\n";
    for (int i = 0; i < n; i++)
    {
        cout << adj[i][0] << " -> ";
        for (int j = 1; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
