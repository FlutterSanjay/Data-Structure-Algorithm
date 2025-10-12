// implementtation of BFS Traversal algorithm
#include <bits/stdc++.h>
using namespace std;
void preparedAdjList(vector<pair<int, int>> &edges, unordered_map<int, set<int>> &adjList)
{

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(int node, unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans)
{

    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        // Traversal all neighbours of front node

        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    preparedAdjList(edges, adjList);

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(i, adjList, visited, ans);
        }
    }
    return ans;
}

int main()
{
    int vertex = 5;
    vector<pair<int, int>> edges;
    edges.push_back({0, 1});
    edges.push_back({0, 4});
    edges.push_back({1, 2});
    edges.push_back({1, 3});
    edges.push_back({1, 4});
    edges.push_back({2, 3});

    vector<int> ans = BFS(vertex, edges);

    cout << "BFS Traversal is : " << endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
