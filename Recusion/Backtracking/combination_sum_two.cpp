// Combination Sum II
/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.
*/
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr,int index,int target,vector<vector<int>>& ans){
    static vector<int> v;

    // Base Case
    if(target == 0){
        ans.push_back(v);
        return;
    }

    if(target < 0){
        return;
    }

    for (int i = index; i < arr.size();i++){
        // To Remove Duplicate
        if(i>index && arr[i] == arr[i-1]){
            continue;
        }
        v.push_back(arr[i]);
        solve(arr, i + 1, target - arr[i], ans);

        // Backtracking
        v.pop_back();
    }
}


int main(){
    vector<int> arr = {10,1,2,7,6,1,5};
    sort(arr.begin(), arr.end());
    int target = 8;
    int index = 0;
    vector<vector<int>> ans;
    solve(arr, index, target,ans);
    
    for(auto i:ans){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
