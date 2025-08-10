//Flip Square Submatrix Vertically” problem in a LeetCode

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> flipSubmatrix(vector<vector<int>>& matrix, int x, int y, int k) {
    // Flip the k x k submatrix vertically
    for (int i = 0; i < k / 2; i++) {
        for (int j = 0; j < k; j++) {
            swap(matrix[x + i][y + j], matrix[x + k - 1 - i][y + j]);
        }
    }
    return matrix;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int x = 1, y = 0, k = 3;

    vector<vector<int>> result = flipSubmatrix(matrix, x, y, k);

    // Print updated matrix
    for (auto &row : result) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
