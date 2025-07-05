// find the sum of 5 no using dynamic Memory Allocation
#include<iostream>
using namespace std;
int sum(int arr[],int n){//  arr[]==*arr
    int tsum=0;
    for(int i=0;i<n;i++){
        tsum+=arr[i];
    }
    return tsum;                           // arr[i]==i[arr]=*(arr+i)
}
int main(){
    int n;
    cout<<"Enter the size of List: ";
    cin>>n;
    // accessing the memory of heap 
    int *arr=new int[n];

    for(int i=0;i<n;i++){
        cout<<"Enter your no: ";
        cin>>arr[i];                 //  *(arr + i)==arr[i]
    }
   int result=sum(arr,n);
   cout<<"Total sum : "<<result;

   return 0;
}