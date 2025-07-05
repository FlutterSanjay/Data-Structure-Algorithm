#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define a class to represent an edge
class Edge {
public:
    int u, v, weight;

    Edge(int u, int v, int w) : u(u), v(v), weight(w) {}

    // Overload the < operator for sorting edges by weight
    bool operator<(Edge& e) {
        return weight < e.weight;
    }
};

// Define a class to represent the Disjoint Set (Union-Find)
class DisjointSet {
private:
    vector<int> parent, rank;

public:
    // Constructor
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find with path compression
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    // Union by rank
    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            // Union by rank
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// Kruskal's Algorithm implementation
class Kruskal {
public:
    static vector<Edge> findMST(int n, vector<Edge>& edges) {
        // Sort edges based on their weight
        sort(edges.begin(), edges.end());

        DisjointSet ds(n);
        vector<Edge> mst;

        for (Edge& edge : edges) {
            int rootSrc = ds.find(edge.u);
            int rootDest = ds.find(edge.v);

            if (rootSrc != rootDest) {
                // Include this edge in the MST
                mst.push_back(edge);
                ds.unionSets(rootSrc, rootDest);
            }
        }

        return mst;
    }
};

int main() {
    int n = 4; // Number of vertices
    vector<Edge> edges = {
        Edge(0, 1, 10),
        Edge(0, 2, 6),
        Edge(0, 3, 5),
        Edge(1, 3, 15),
        Edge(2, 3, 4)
    };

    vector<Edge> mst = Kruskal::findMST(n, edges);

    cout << "Edges in the MST:\n";
    int totalWeight = 0;
    for (Edge& edge : mst) {
        cout << edge.u << " -- " << edge.v << " == " << edge.weight << "\n";
        totalWeight += edge.weight;
    }

    cout << "Total weight of the MST: " << totalWeight << "\n";

    return 0;
}
