// Count Inversion mean how many swap operation required to sort an array

#include<bits/stdc++.h>
using namespace std;

void mergeSort(vector<int>& arr,int mid,int s,int e,int& count){

    int l1 = mid - s + 1;
    int l2 = e - mid;

    vector<int> a(l1);
    vector<int> b(l2);

    int k = s;
    for (int i = 0; i < l1;i++){
        a[i] = arr[k++];
    }

    k = mid + 1;
    
    for (int j = 0; j < l2;j++){
        b[j] = arr[k++];
    }

    int i = 0;
    int j = 0;
    k = s;

    while(i< l1 && j< l2){
        if(a[i]<=b[j]){
            arr[k++] = a[i++];
        }
        else{
            arr[k++] = b[j++];
            count +=(l1);
        }
    }

    //for a[i]
    while(i<l1){
        arr[k++] = a[i++];
    }

    while(j<l2){
        arr[k++] = b[j++];
    }
}

void solve(vector<int>&arr,int s,int e,int& count){

    // Base Case
    if(s>=e)
        return;

    int mid = (e - s) / 2 + s;

    // Left Part
    solve(arr, s, mid, count);

    //Right Part
    solve(arr, mid + 1, e, count);

    mergeSort(arr, mid, s, e, count);
}
int main(){

    vector<int> arr = {1, 2, 3, 4, 5};
    int s = 0;
    int e = arr.size() -1 ;
    int count = 0;
    solve(arr, s, e, count);
    cout << "Total Inversion Count :" << count;
    return 0;
}