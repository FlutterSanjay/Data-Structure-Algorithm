//  K-diff Pairs in an Array using Binary Search
#include<bits/stdc++.h>
using namespace std;
bool binarySearch(vector<int> arr,int start,int target){
    int s = start;
    int e = arr.size() - 1;

    while(s<=e){
        int mid = s + (e - s) / 2;

        if(arr[mid]==target){
            return true;
        }else if(arr[mid]<target){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
        }
        return false;
    }



int findKDiffPair(vector<int> arr,int k){
    int i = 0;
    int j = arr.size()-1;

     set<pair<int, int>> distinctPair;

    while(i<=j){
        int value = k + arr[i];

        bool result = binarySearch(arr,i+1, value);
        if(result){
            distinctPair.insert({arr[i], value});
        }
        i++;

    }
    return distinctPair.size();
}

int main(){
    vector<int> arr = {1,3,1,5,4};
    int k = 0;
    sort(arr.begin(), arr.end());
    int result = findKDiffPair(arr,k);
    cout << "The No of K-Difference Pair :" << result;
    return 0;
}