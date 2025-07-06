// Different and Best Approach to perform Quick Sort
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr,int s,int e){
    // Base Case
    if(s>=e){
        return;
    }

    int i = s - 1;
    int j = s;
    int pivot = e;

    while(j<pivot){
        if(arr[j]<arr[pivot]){
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[pivot]);

    // Recursive call
    solve(arr, s, i - 1);
    solve(arr, i + 1, e);
}

int main(){
    vector<int> arr ={7,2,1,8,6,3,5,4};
    int s = 0;
    int e = arr.size() - 1;
    solve(arr, s, e);
    for(auto it:arr){
        cout << it << " ";
    }
    return 0;
}