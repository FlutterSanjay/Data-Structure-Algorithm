// In Place Merge Sort
//T.C - O(nlogn) && S.C - O(1)

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr,int s,int e){
    int n = arr.size();
    int gap = ceil(n / 2);

    while(gap>0){
        int i = s;
        int j = s + gap;
        while(j<=e){
            if(arr[i]>arr[j]){
                swap(arr[i], arr[j]);
            }
            i++;
            j++;
        }
        if(gap <= 1) break;
        gap = ceil(gap / 2);
    }
}

int main(){
    vector<int> arr =  {1, 2, 8, 9, 12, 3, 4, 7, 10, 13};
    int s = 0;
    int e = arr.size() - 1;
    solve(arr,s,e);

    for(auto i:arr){
        cout << i << " ";
    }


    return 0;
}