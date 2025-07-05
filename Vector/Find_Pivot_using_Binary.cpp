// find the pivot element using the binary search
// pivot= min value in an array..
#include<iostream>
#include<vector>
using namespace std;

int pivotf(vector<int> &arr,int n){
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<high){
        int mid=low+(high-low)/2;
    if(arr[mid]>=arr[0]){
        low=mid+1;
        ans=low;
    }
    else{
        high=mid;
    }
}
return ans;
}

int main(){
    int n;
    cout<<"Enter the size of List: ";
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cout<<"Enter your no:";
        cin>>v[i];
    }
    int result=pivotf(v,n);
    if(result==-1){
        cout<<"Data Not Found !";
    }
    else{
        cout<<"Index no Of Pivot Element :"<<result<<endl<<"Value :"<<v[result];
    }
    return 0;
}