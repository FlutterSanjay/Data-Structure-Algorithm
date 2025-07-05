// merge sort using recursion
#include<iostream>
using namespace std;

void merge(int *arr,int low,int high){
    int mid=low+(high-low)/2;
    int len1=mid-low+1;
    int len2=high-mid;

    int *first=new int[len1];
    int *second=new int[len2];
     
     int k=low;
     for(int i=0;i<len1;i++){
        first[i]=arr[k++];
     }
     k=mid+1;
     for(int  i=0;i<len2;i++){
        second[i]=arr[k++];
     }

     int index1=0;
     int index2=0;
     k=low;
     while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[k++]=first[index1++];
        }
        else {
            arr[k++]=second[index2++];
        }
     }

     while(index1<len1){
        arr[k++]=first[index1++];
     }
     while(index2<len2){
        arr[k++]=second[index2++];
     }
}



void mergesort(int *arr,int low,int high){
    if(low>=high) return ;
    int mid=low+(high-low)/2;

    // left sort
    mergesort(arr,low,mid);

    // right sort
    mergesort(arr,mid+1,high);

    merge(arr,low,high);

}
int main(){
    int arr[5]={2,4,1,0,5};
    mergesort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

