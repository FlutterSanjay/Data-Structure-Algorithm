// Maximum SubArray Sum

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr,int s,int e){

    // Base Case
    if(s==e)
        return arr[s];

    int maxBLeftSum = INT_MIN;
    int maxBRightSum = INT_MIN;
    int mid = s + (e - s) / 2;
    int maxLeftSum = solve(arr, s, mid);
    int maxRightSum = solve(arr, mid + 1, e);

    int leftSum = 0;
    int rightSum =0;

    // Left Part
    for (int i = mid; i >= s;i--){
        leftSum += arr[i];
        if(leftSum>maxBLeftSum) {
            maxBLeftSum = leftSum;
        }
    }

    for (int i = mid + 1; i <= e;i++){
        rightSum += arr[i];
        if(rightSum>maxBRightSum){
            maxBRightSum = rightSum;
        }
    }

    // Cross Border Sum
    int cbs = maxBLeftSum + maxBRightSum;
    return max(cbs, max(maxLeftSum, maxRightSum));
}
int main(){
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int s = 0;
    int e = arr.size() - 1;
    int result = solve(arr, s, e);
    cout << "Max Sub Array Sum : " << result;
    return 0;
}