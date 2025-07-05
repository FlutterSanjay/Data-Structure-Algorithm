// Binary Search using Recursion 
#include<bits/stdc++.h>
using namespace std;
int BinarySearch(vector<int>& arr,int s,int e,int key){
    int mid=s+(e-s)/2;
    
    // Base Case
    if(s > e) return -1;
    
    //Processing
    if(arr[mid]==key) return mid;
    
    //Recursive Relation
    else if(arr[mid]<key){
       return BinarySearch(arr,s=mid+1,e,key);
    }else{
       return BinarySearch(arr,s,e=mid-1,key);
    }
}

int main(){
    vector<int> arr={2,4,6,8,9,12};
    int key=12;
    int n=arr.size();
    int result=BinarySearch(arr,0,n-1,key);
    cout<<"Index Element : "<<result;
    
    return 0;
}