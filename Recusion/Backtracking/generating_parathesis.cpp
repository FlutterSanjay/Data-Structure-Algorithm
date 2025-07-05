#include<bits/stdc++.h>
using namespace std;

void solve(vector<string>& ans, int open, int close, string output) {
    if (open == 0 && close == 0) {
        ans.push_back(output);
        return;
    }

    if (open > 0) {
        output.push_back('(');
        solve(ans, open - 1, close, output);
        output.pop_back(); // backtrack
    }

    if (close > open) {
        output.push_back(')');
        solve(ans, open, close - 1, output);
        output.pop_back(); // backtrack
    }
}

int main() {
    int n = 4;
    vector<string> ans;
    solve(ans, n, n, "");

    for (auto i : ans) {
        cout << i << endl;
    }

    return 0;
}
