// Find the square root using the BINARY SEARCH

#include<iostream>
#include<vector>
using namespace std;

int binary(int x){
    int low=0;
    int high=x;
    int ans=-1;
    while(low<=high){
        long long int mid=low+(high-low)/2;
        long long int square=mid*mid;
        if(square==x){
            return mid;
        }
        else if(square<x){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter your no : ";
    cin>>n;
    int v;
    v=n;
    int result=binary(v);
    if(result==-1){
        cout<<"Data Not Found !";
    }
    else{
        cout<<"Square Root: "<<result;
    }
    return 0;
}