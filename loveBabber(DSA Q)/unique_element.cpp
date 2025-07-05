// Find the Unique Element from the Array
#include<iostream>
#include<vector>
using namespace std;

int uniqueElement(vector<int> arr){
    int size=arr.size();
    int ans=0;
    for(int i=0;i<size;i++){
        ans^=arr[i];
    }
    return ans;
}
int main(){
    vector<int> arr(5);
    for(int i=0;i<5;i++){
        cout<<"Enter Your Number :";
        cin>>arr[i];
    }
    cout<<"Unique Element : "<<uniqueElement(arr);
    return 0;
}