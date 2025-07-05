// Find the element in Nearly sorted array using Binary search
#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr,int target){
    int s = 0;
    int e = arr.size() - 1;

    while(s<=e){
        int mid = (s + e) / 2;

// Element Found Case
        if(arr[mid]==target)
            return mid;
        
        if(arr[mid-1]==target)
            return mid - 1;

        if(arr[mid+1]==target)
            return mid + 1;
        

        //Right Search Case
        if(arr[mid]<target){
            s = mid + 2;
        }
        // Left Search Case
        else{
            e = mid - 2;
        }
    }
    return -1;
}

int main(){
    int num;

    vector<int> arr={10,3,40,20,50,80,70};

    int target = 50;

    int result = binarySearch(arr, target);
    cout << (result == -1 ? "ELement Not Found!" :"Element Found at Index : "+ to_string(result));
    return 0;
}