// M-Coloring Problem
#include <bits/stdc++.h>
using namespace std;

class GraphColoring {
public:
    bool isSafe(int i, int j, vector<vector<bool>>graph, int V, vector<int>& color) {
        for (int k = 0; k < V; k++) {
            // Check if there is an edge and if the adjacent vertex has the same color
            if (graph[i][k] == 1 && color[k] == j) {
                return false;  // Unsafe to color this vertex with j
            }
        }
        return true;  // Safe to color this vertex with j
    }

    bool fnc(vector<vector<bool>>graph, int m, int V, int i, vector<int>& color) {
        if (i == V) {  // All vertices are assigned a color
            return true;
        }

        for (int j = 0; j < m; j++) {  // Try all colors
            if (isSafe(i, j + 1, graph, V, color)) {  // Use j+1 to match color numbering from 1 to m
                color[i] = j + 1;  // Assign color (1 to m)
                if (fnc(graph, m, V, i + 1, color))  // Recur to assign colors to the next vertex
                    return true;
                color[i] = -1;  // Backtrack
            }
        }
        return false;  // No color can be assigned
    }

    bool graphColoring(vector<vector<bool>>graph, int m, int V) {
        vector<int> color(V, -1);  // Initialize all vertices to -1 (no color assigned)
        return fnc(graph, m, V, 0, color);  // Start coloring from vertex 0
    }
};

int main() {
    int V = 4;
    vector<vector<bool>>graph = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };

    // Number of colors
    int m = 3;

    // Function call
    GraphColoring g;
    cout << (g.graphColoring(graph, m, V) ? "Solution exists" : "Solution does not exist") << endl;
    return 0;
}
