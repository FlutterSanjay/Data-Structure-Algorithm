#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9      // Representing infinity as a large number

class AllPairSP {
private:
    int V;         //vertices
    vector<vector<int>> dist;

public:
                      // Constructor
    AllPairSP(int vertices) {
        V = vertices;
        dist = vector<vector<int>>(V, vector<int>(V, INF));
        for (int i = 0; i < V; ++i) {
            dist[i][i] = 0;    // Distance from any node to itself is 0
        }
    }

    // Function to add edges to the graph
    void addEdge(int u, int v, int weight) {
        dist[u][v] = weight;
    }


    void shortestpath() {
        for (int k = 0; k < V; ++k) {
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                                     // Update the distance if a shorter path is found through vertex k
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }

    // to print the shortest distance matrix
    void printShortestPaths() const {
        cout << "Shortest distances between every pair of vertices:\n";
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][j] == INF) {
                    cout << "INF ";
                } else {
                    cout << dist[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    AllPairSP graph(V);

    cout << "Enter the edges (s d weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    graph.shortestpath();
    graph.printShortestPaths();

    return 0;
}