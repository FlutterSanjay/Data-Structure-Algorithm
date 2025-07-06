// Combination Sum

#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& arr,int index,int target,vector<vector<int>>&ans){
    static vector<int> v;

    // Base Case
    if(target == 0){
        ans.push_back(v);
        return;
    }

    if(target < 0){
        return; 
    }

    for (int i = index;i<arr.size();i++){
        v.push_back(arr[i]);
        solve(arr, i, target - arr[i], ans);

        //BackTracking
        v.pop_back();
    }

}
int main(){
    vector<int> arr = {2, 3, 6, 7};
    int index = 0;
    int target = 7;
    vector<vector<int>> ans;
    solve(arr, index,target, ans);
    for(auto i:ans){
        for(auto j:i){
            cout << j << " ";
        }
    }
    return 0;
}