// sort the ELement using Quick sort
#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr,int low,int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    do{
        while(pivot>= arr[i]){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }

    }
    while(i<j);
    swap(arr[low],arr[j]);
    return j;
}

void quick(vector<int> &arr,int low,int high){
    int partition_index;
    if(low<high){
        int partition_index=partition(arr,low,high);
        quick(arr,low,partition_index-1);
        quick(arr,partition_index+1,high);
    }
}
int main(){
    int size;
    cout<<"Enter your size :";
    cin>>size;

    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cout<<"Enter your Element : ";
        cin>>arr[i];
    }
 quick(arr,0,size-1);
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
 return 0;
}
