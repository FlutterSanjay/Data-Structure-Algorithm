// Beautiful Arrangement
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&arr,int n,int& ans,int currNum){

    // BaseCase
    if(currNum == n + 1){
        for (int i = 1; i <= n;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        ans++;
        return;
    }

    for (int i = 1; i <= n; i++){
        if(arr[i] == 0 && (currNum % i == 0 || i % currNum == 0)){
            arr[i] = currNum;
            solve(arr, n,ans, currNum + 1);

            // Backtracking
            arr[i] = 0;
        }
    }
}

int main(){
    int n = 3;
    vector<int> arr(n + 1);
    int ans = 0;
    solve(arr, n, ans, 1);
    cout << "Total Count : " << ans;
    return 0;
}