//Selection sort
#include<iostream>
#include<vector>
using namespace std;

void sort(vector<int>&arr,int size){
    int min_index;
    for(int i=0;i<size-1;i++){
        min_index=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min_index]){
            min_index=j;
            }
        }
        swap(arr[min_index],arr[i]);
    }
}
int main(){
    int size;
    cout<<"Enter your Size : ";
    cin>>size;
    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cout<<"Enter your Element : ";
        cin>>arr[i];
    }
    sort(arr,size);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}