#include<bits/stdc++.h>
using namespace std;

class ExponentialSearch{
    protected:
    vector<int> arr;
    public:
    ExponentialSearch(vector<int> arr):arr(arr){}
    
    int binarySearch(int s,int e,int x){
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]==x) return mid;
            else if(arr[mid]>x){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return -1;
    }
    
    int exponentialSearch(int x,int n){
        
        if(arr[0]==x) return 0;
        int i=1;
        while(i<n && arr[i]<=x){
            i=i*2;
        }
        return binarySearch(i/2,min(i,n-1),x);
    }
};
int main(){
    int n=5;
    int x=13;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cout<<"Enter your Number :";
        cin>>arr[i];
    }
    ExponentialSearch s(arr);
    cout<<"Index No :"<<s.exponentialSearch(x,n);
    return 0;
}