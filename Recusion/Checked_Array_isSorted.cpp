// check sorted array or not
#include<bits/stdc++.h>
using namespace std;
bool sortedArray(vector<int>& arr,int n){
    static bool ans=true;
    // Base Case
    if(n==-1) return ans;
    
    // Processing
    if(arr[n] < arr[n-1]) ans=false;
    
    // Recursive Relation
    
    return sortedArray(arr,n-1);
}
int main(){
    vector<int> arr ={2,4,6,8,9};
    int n=arr.size()-1;
    bool result=sortedArray(arr,n);
    cout<<(result?"Sorted Array":"Unsorted Array");
    return 0;
}