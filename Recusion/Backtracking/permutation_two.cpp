// Permutaion II

// The Output must contain the unique element
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr,vector<vector<int>>& ans,int start){

    // Base Case
    if(start == arr.size()){
        ans.push_back(arr);
        return;
    }

    unordered_map<int, bool> visited;
    for (int i = start; i < arr.size();i++){
        if(visited.find(arr[i]) != visited.end()){
            continue;
        }
        visited[arr[i]] = true;
        swap(arr[i], arr[start]);
        solve(arr, ans, start + 1);

        // BackTracking
        swap(arr[i], arr[start]);
    }
}


int main(){
    vector<int> arr ={1,1,2};
    vector<vector<int>> ans;
    int index = 0;
    solve(arr, ans, index);

    for(auto i:ans){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}