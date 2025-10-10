// Implementation of an adjacency list for a graph in C++
#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {

        // direction == 0  mean undirected graph
        // direction ==  1 mean directed graph

        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    // printint the adjancy List
    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph g;
    int n;
    int m;
    cout << "Enter the number of nodes : ";
    cin >> n;
    cout << "Enter the number of edges : ";
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    // printing the adjacency List
    g.printAdj();

    return 0;
}