// Search the Element using Rotated Sorted Array
#include<bits/stdc++.h>
using namespace std;

int findPivot(vector<int> arr){
    int s = 0;
    int e = arr.size() - 1;
    while(s<=e){
        int mid = s + (e - s) / 2;
        if(s==e){
            return s;
        }

        //Handle -1
        if(mid+1<=e && arr[mid]>arr[mid+1]){
            return mid;
        }

        if(arr[mid-1]>arr[mid]){
            return mid - 1;
        }

        //Handle -2
        if(arr[s]>arr[mid]){
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
}

int binarySearch(vector<int> arr,int s ,int e,int target){

        while(s<=e){
            int mid = s + (e - s) / 2;
            if(arr[mid]==target){
                return mid;
            }else if(arr[mid]>target){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return -1;
    }
    

int searchElement(vector<int>arr,int target,int pivot){


//Line -A
    if(target>=arr[0] && target<=arr[pivot]){
        return binarySearch(arr, 0, pivot,target);
    }
    //Line - B
    else{
        return binarySearch(arr, pivot + 1, arr.size() - 1,target);
    }
}

int main(){
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 2;

    int pivot = findPivot(arr);
    

    int result = searchElement(arr, target, pivot);
    cout << result << endl;

    return 0;
}