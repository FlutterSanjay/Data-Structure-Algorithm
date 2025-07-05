// Find The maximum & minimum Number in Given Array using Recursion

#include<bits/stdc++.h>
using namespace std;
int maxNum(vector<int> arr,int n){
   static int max=INT_MIN;
    // base case
    if( n == -1) return max;
    
    if(arr[n]>max){
        max=arr[n];
    }
    return maxNum(arr,n-1);
}

int minNum(vector<int> arr,int n){
    static int min=INT_MAX;
    
    // Base Case
    if( n == -1) return min;
    
    // Recursive Relation
    if( arr[n]<min){
        min=arr[n];
    }
    return minNum(arr,n-1);
}
int main(){
    vector<int> arr ={9,5,0,2,-1};
    int n=arr.size() - 1;
    int result=maxNum(arr,n);
    cout<<"Max Number : "<<result<<endl;
    
    result=minNum(arr,n);
    cout<<"Min Number : "<<result;
    
    return 0;
}