// Detect the Cycle in Directed Graph
// Cycle Detection in Directed Graph
#include <bits/stdc++.h>
using namespace std;
bool checkCycleDfs(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour : adj[node])
    {

        if (!visited[neighbour])
        {
            bool cycleDetected = checkCycleDfs(neighbour, visited, dfsVisited, adj);

            if (cycleDetected)
            {
                return true;
            }
        }
        else if (dfsVisited[neighbour])
            return true;
    }

    dfsVisited[node] = false;
    return false;
}

int detectCycle(int n, vector<pair<int, int>> &edges)
{

    unordered_map<int, list<int>> adj;
    // create the Directed Graph
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // call dfs for all components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool cycleFound = checkCycleDfs(i, visited, dfsVisited, adj);

            if (cycleFound)
                return true;
        }
    }
    return false;
}

int main()
{

    int n = 4; // number of nodes
    vector<pair<int, int>> edges = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 2} // this edge creates a cycle
    };

    if (detectCycle(n, edges))
        cout << "Cycle detected in the graph." << endl;
    else
        cout << "No cycle detected in the graph." << endl;

    return 0;
}