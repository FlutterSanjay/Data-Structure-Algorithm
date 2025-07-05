// Find the First Occurence using Binary Search
#include<bits/stdc++.h>
using namespace std;

//Hint - first Occurnce always find in Left Part
//Hint - last Occurence always find in Right Part
int binary_Search(vector<int>arr,int target){
    int s = 0;
    int e = arr.size() - 1;
    int storeIndex;
    while(s<=e){
        int mid = s + (e - s) / 2;
        if(arr[mid]==target){
            storeIndex = mid;
            cout << storeIndex << endl;
            e = mid - 1;
        }
        else if(arr[mid]<target){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return storeIndex;
}

int main(){
    vector<int> arr = {1, 2, 3, 3, 3, 4, 5, 6};
    int target = 3;

    int index = binary_Search(arr,target);
    cout << index;

    // cout<<(index == -1 ? "Element Not Found!" : "Element Found at Index : " + to_string(index));
    return 0;
}