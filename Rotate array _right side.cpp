#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    for(int i=0;i<n;i++){
        cout<<arr[k%n]<<" ";
        k++;
    }

    return 0;
}