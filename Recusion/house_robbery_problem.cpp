// House Robbery Problem

#include<bits/stdc++.h>
using namespace std;

// T.C -> 2^n
// S.C -> O(n)

int rob(vector<int>&arr,int i){

    // Base Case
    if(i >= arr.size()){
        return 0;
    }

    // Processing and Recursive Relation
    int robAmt1 = arr[i] + rob(arr, i + 2);
    int robAmt2 = 0 + rob(arr, i + 1);
    return max(robAmt1, robAmt2);
}
int main(){
    vector<int> arr = {1, 2, 3, 1};
    int result = rob(arr, 0);
    cout << "Max Profit : " << result;
    return 0;
}