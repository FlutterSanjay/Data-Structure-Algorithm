// check the Palindrome using single Array
#include<iostream>
using namespace std;

int palin(int *arr, int size){
    int count=0;
    for(int i=0;i<=size/2 && size !=0;i++){ // 
        if(arr[i]!=arr[size-i-1]){ // check from back side and start
            count++;/*
            arr[i]!=arr
            */
            break;
        }
    }
    return count;
}

int main(){
    int size;
    cout<<"Enter the size :";
    cin>>size;
    int *arr=new int[size];
    for(int i=0;i<size;i++){
        cout<<"Enter your no :";
        cin>>arr[i];
    }
    int result=palin(arr,size);
    if(result) cout<< "Not Palindrome ";
    else cout<< "palindrome..";
    return 0;
}