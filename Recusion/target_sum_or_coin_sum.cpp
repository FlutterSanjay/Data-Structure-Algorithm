// Target Sum and Coin Change problem using minimum coin or element
#include<bits/stdc++.h>
using namespace std;

int TargetSum(vector<int> &arr,int target){
    int mini = INT_MAX;

    // Base Case
    if(target == 0)
        return 0;

    if(target < 0 )  // for Invalid case
        return INT_MAX;

        // Processing
    for (int i = 0; i < arr.size();i++){
        int ans = TargetSum(arr, target - arr[i]);
        
        if(ans != INT_MAX) { // check the invalid case or not
            mini = min(ans + 1, mini);
        }
    }
    return mini;
}

int main(){

    int target = 5;
    vector<int> arr = {1, 2};

    int result = TargetSum(arr, target);
    cout << "Answer : " << result;
    return 0;
}