// sum of minimum and maximum elements of all subarrays of size K
#include<iostream>
#include<limits.h>
using namespace std;
int sum_Sub_Array(int arr[],int N,int k){
    int sum=0;
    for(int i=0;i<N;i++){
        int length=0;
        for(int j=i;j<N;j++){
            length++;
        
        if(length==k){
            int maxi=INT_MIN;
            int mini=INT_MAX;

            for(int m=i;m<=j;m++){
                maxi=max(maxi,arr[m]);
                mini=min(mini,arr[m]);
            }
            sum+=maxi+mini;
        }
    }
}
return sum;
}

int main(){
    int size,k;
    cout<<"Enter the size of Array : ";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cout<<"Enter your number : ";
        cin>>arr[i];
    }
    cout<<"Enter the size of sub_Array : ";
    cin>>k;
    int ans=sum_Sub_Array(arr,size,k);
    cout<<ans;
    return 0;

}