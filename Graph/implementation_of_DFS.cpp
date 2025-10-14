#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &compoment)
{

    compoment.push_back(node);
    visited[node] = true;

    // Remaining node ke liye
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, compoment);
        }
    }
}

vector<vector<int>> DFS(int v, int e, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            vector<int> compoment;
            dfs(i, visited, adj, compoment);
            ans.push_back(compoment);
        }
    }
    return ans;
}

int main()
{
    int v = 5; // total vertices
    int e = 3; // total edges
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {3, 4}};

    vector<vector<int>> components = DFS(v, e, edges);

    cout << "Connected Components in the Graph:\n";
    for (int i = 0; i < components.size(); i++)
    {
        cout << "Component " << i + 1 << ": ";
        for (auto node : components[i])
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}