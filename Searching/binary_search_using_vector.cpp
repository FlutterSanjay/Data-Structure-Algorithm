// binary search using vector
#include<iostream>
#include<vector>
using namespace std;
int binary(vector<int>&arr,int low,int high,int key){
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]>key){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}
int main(){
    int size,key;
    cout<<"Enter the size of array : ";
    cin>>size;
   
    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cout<<"Enter your Element :";
        cin>>arr[i];
    }
     cout<<"Enter the value to search :";
    cin>>key;
    int result=binary(arr,0,size-1,key);
    if(result==-1){
        cout<<"Data Not Found !..";
    }
    else{
        cout<<"Index no :"<<result<<endl;
    }
    return 0;
    
}