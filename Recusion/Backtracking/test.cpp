// Count Inversion
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr,int n,int i,int j){

    static int count = 0;

    // Base Case
    if(i>= n -1){
        cout << " Count Inversion : " << count;
        return;
    }

    // for J Pointer
    if(j>=n){
       return solve(arr, n, i + 1, i + 2);
    }
    if(arr[i]> arr[j]){
        count++;
    }
   return solve(arr, n, i, j + 1);
}

int main(){
    vector<int> arr = {8, 4, 2, 1};
    int n = arr.size();
    int i = 0;
    int j = i + 1;
    solve(arr, n, i, j);
    return 0;
}