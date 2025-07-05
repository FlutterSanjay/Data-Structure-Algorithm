#include <bits/stdc++.h>
using namespace std;

void extremePrint(int arr[],int size){
    for(int i=0,j=size-1;i<=j;i++,j--){
        if(i==j){
            cout<<arr[i];
        }else{
        cout<<arr[i]<<" ";
        cout<<arr[j]<<" ";
    }
    }
}


int main() {
    int arr[6]={9,8,0,1,4,2};
    extremePrint(arr,6);
    // recursivePrint(arr,0,6);
    return 0;
    }
	// your code goes here


