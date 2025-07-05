// merge sort
#include<iostream>
using namespace std;
void merge_sort(int arr[],int s,int e){
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int *first=new int[len1];
    int *second=new int[len2];
    int k=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[k++];
    }
    // merge the two array
    int i=0,j=0;
    k=s;
    while(i<len1 && j<len2){
        if(first[i]<second[j]){
            arr[k++]=first[i++];
        }
        else{
            arr[k++]=second[j++];
        }
    }
        while(i<len1){
            arr[k++]=first[i++];
        }
        while(j<len2){
            arr[k++]=second[j++];
        }
        
    
}

void merge(int arr[],int s,int e){
    if(s>=e)
        return ;
        int mid=s+(e-s)/2;
        // left part sorted
        merge(arr,s,mid);
        // right part
        merge(arr,mid+1,e);
        merge_sort(arr,s,e);
    }
int *ptr(int arr[],int n){
    merge(arr,0,n-1);
    return arr;
}
int main(){
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cout<<"Enter the your Element : ";
        cin>>arr[i];
    }
    
    int* result=ptr(arr,size);
     for(int i=0;i<size;i++){
         cout << arr[i] << " ";
    }
    
    
    // for(int i=0;i<size;i++){
    //     cout<<*(result+i)<<" ";
    // }
    return 0;
}    
