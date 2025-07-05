//658. Find K Closest Elements
#include<bits/stdc++.h>
using namespace std;

vector<int> findKClosestElement(vector<int> arr,int k,int x){
    int l = 0;
    int h = arr.size() - 1;

    while(h-l>=k){
        if(abs(arr[l]-x) > abs(arr[h]-x)){
            l++;
        }else{
            h--; // it also handle the == case when both 13=13
        }
    }
    return vector<int>(arr.begin() + l, arr.begin() + h+1); //n-1 +1=n=h
}

int main(){
    vector<int> arr = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int k = 4;
    int x = 35;

    vector<int> result = findKClosestElement(arr,k,x);

// Range-based For Loop
    for(auto num:result){
        cout << num << " ";
    }

    return 0;
}