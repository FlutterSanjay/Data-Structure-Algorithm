// Binary search using Recursion
#include<iostream>
using namespace std;

int binary(int *arr,int key,int low,int high){
    if(low>high) return -1;
    int mid=low+(high-low)/2;
    if(arr[mid]==key) return mid;
    else if(arr[mid]>key){
        return binary(arr,key,low,mid-1);
    }
    else{
        return binary(arr,key,mid+1,high);
    }
}
int main(){
    int size,key;
    cout<<"Enter the size of array : ";
    cin>>size;
    cout<<"Enter the key value to search : ";
    cin>>key;
    int *arr=new int[size];
    for(int i=0;i<size;i++){
        cout<<"Enter your no : ";
        cin>>arr[i];
    }
    int result=binary(arr,key,0,size-1);
    if(result!=-1){
        cout<<"Data Found...."<<endl<<"Index no : "<<result;

    }
    else{
        cout<<"Data Not Found...!";
    }
    return 0;
}