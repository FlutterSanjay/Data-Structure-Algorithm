//find the key in  Search In Rotated Sorted Array
#include<iostream>
#include<vector>
using namespace std;

// find pivot Element
int pivotf(vector<int> &arr,int n){
    int low=0;
    int high=n-1;
    while(low<high){
        int mid=low+(high-low)/2;
        if(arr[mid]>=arr[0]){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    return low;
}

// find the key element in an Array
int binarySearch(vector<int> &arr,int l,int h,int key){
    int low=l;
    int high=h;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
            
     }
        return -1;
  }
    
    
    int main(){
        int n,key;
        cout<<"Enter your list size:";
        cin>>n;
        cout<<"Enter your Key value: ";
        cin>>key;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cout<<"Enter your no: ";
            cin>>v[i];
        }
        
        // condition  of two Parts
        int pivot= pivotf(v,n);
        
        // Second part of Array
        if(v[pivot]<=key && key<v[n-1]){
            int result=binarySearch(v,pivot,n-1,key);
            if(result==-1){
                cout<<"Data Not Found !";
            }
            else{
                     cout<<"Index no: "<< result;
            }
        }
        // First part of Array
        else{
             int result=binarySearch(v,0,pivot-1,key);
               if(result==-1){
                cout<<"Data Not Found !";
               }
               else{
                     cout<<"Index no: "<< result;
            }
        }
        return 0;
        
    }
