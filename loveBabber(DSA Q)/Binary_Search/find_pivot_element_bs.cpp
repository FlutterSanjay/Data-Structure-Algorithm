// Find the Pivot Element using Binary Search
#include<bits/stdc++.h>
using namespace std;

int findPivotElement(vector<int>arr){
    int s = 0;
    int e = arr.size() - 1;

    while(s<=e){
        int mid = s + (e - s) / 2;
        // Handle Single Element Array
        if(s==e)
            return s;

        // Handle Decrease Part
        
        //Case -1
        if(mid+1<=e && arr[mid]>arr[mid+1]){
            return mid;
        }

        //Case -2
        if(mid-1>=s && arr[mid-1]>arr[mid]){
            return mid - 1;
        }

        //Line-B
        if(arr[s]>arr[mid]){
            e = mid - 1;
        }
        // Line-A
        else{
            s = mid + 1;
        }

    }
}

int main(){
    vector<int> arr = {4};

    int index = findPivotElement(arr);
    cout << "Pivot Element at Index : " << index;

    return 0;
}