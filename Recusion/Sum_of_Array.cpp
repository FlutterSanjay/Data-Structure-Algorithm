// Sum of Array value index
#include<iostream>
using namespace std;
int tsum=0;
void sum(int *arr,int size){
    if(size==0){
        cout<<"Sum : "<<tsum;   // base case
        return;
    }
    tsum+=arr[size-1];
    return sum(arr,size-1); //Resursive   Relation
}

int main(){
    int n;
    cout<<"Enter your Array size: ";
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter your no: ";
        cin>>arr[i];
    }
    sum(arr,n);
    return 0;
}