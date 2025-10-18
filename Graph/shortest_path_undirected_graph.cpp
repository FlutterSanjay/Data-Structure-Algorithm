// Shortest Path in Undirected Graph
#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> &edges, int n, int m, int s, int t)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // do bfs
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    parent[s] = -1;
    visited[s] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // neighbour element find

        for (auto i : adj[front])
        {
            if (!visited[i])
            {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    // prepared the shortest path
    vector<int> ans;
    int currNode = t;
    ans.push_back(t);
    while (currNode != s)
    {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    // Example Graph:
    // 1 -- 2
    // |    |
    // 4 -- 3
    //  \ 
    //   5
    //
    // Find shortest path from 1 to 5

    int n = 5; // number of nodes
    int m = 5; // number of edges
    vector<pair<int, int>> edges = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 1},
        {4, 5}};

    int source = 1;
    int destination = 5;

    vector<int> path = shortestPath(edges, n, m, source, destination);

    cout << "Shortest Path from " << source << " to " << destination << ": ";
    for (auto node : path)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}