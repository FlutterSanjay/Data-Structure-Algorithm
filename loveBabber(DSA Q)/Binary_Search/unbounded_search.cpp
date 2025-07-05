// Find the search the element in Infinity array of element
//Approach - Exponenetial Search -> all Condition should be Same

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

int findUnboundedElement(vector<int> arr,int target){
    if(arr[0] ==  target)
        return 0;

    int i = 0;
    int j = 1;

    while(arr[j]<target){ // Take Lower part side because the element is less eg.2^3 take rather than 2^4
        i = j;
        j = j * 2;
    }

    return bs(arr, i, j, target);
}

int main(){
    vector<int> arr = {3,4,5,6,7,8,11,13,14,15,20,22};// it's must carry infinite element
    int target = 22;

    int index = findUnboundedElement(arr, target);
    cout << "The Element Found at Index : " << index;
    return 0;
}