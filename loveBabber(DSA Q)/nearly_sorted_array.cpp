// Apply binary search on nearly sorted array
#include<iostream>
#include<vector>
using namespace std;

int nearlySorted(vector<int> arr,int target){
    int s=0;
    int e=arr.size();
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(mid-1>=s && arr[mid-1]==target){
            return mid-1;
        }
        if(mid+1<=e && arr[mid+1]==target){
            return mid+1;
        }
        else if(arr[mid]>target){
            e=mid-2;
        }else{
            s=mid+2;
        }
    }
    return -1;
}
int main(){
    vector<int> arr{10,3,40,20,50,80,70};
    cout<<nearlySorted(arr,700);
    return 0;
}