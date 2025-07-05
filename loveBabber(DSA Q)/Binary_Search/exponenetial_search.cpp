// Exponential search/Doubling search/Galloping Search/Strarik Search

// It's take less time Complexity  and more optimized than Binary Search

// It's basically used in Large array to find element and Array must be Sorted

#include<bits/stdc++.h>
using namespace std;
int bs(vector<int>arr,int s,int e,int target){
    while(s<=e){
        int mid = s + (e - s) / 2;
        if(arr[mid]==target){
            return mid;
        }else if(arr[mid]<target){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
        }
        return -1;
    }


int exponentialSearch(vector<int>arr,int target){
    if(arr[0]==target)
        return 0;

    int i = 1;
    int e = arr.size() - 1;

    while(i<=e && arr[i]<=target){
        i *= 2;
    }
    return bs(arr, i / 2, min(e, i), target);
}

int main(){
    vector<int> arr = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int target = 13;

    int index = exponentialSearch(arr, target);
    cout << "Found at Index :" << index << endl;
    return 0;
}
