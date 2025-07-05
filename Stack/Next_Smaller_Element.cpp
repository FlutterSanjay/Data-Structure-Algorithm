// find the next smaller Element
// or find the Second Smallest Element
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> small(int arr[],int size){
    stack<int> s;
    s.push(-1);
    vector<int> ans(size);

    for(int i=size-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()>=curr){
            s.pop();
        }
            ans[i]=s.top();
            s.push(curr);
        
    }
     return ans;
}
int main(){
    int size;
    cout<<"Enter the size of Array : ";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cout<<"Enter the your Element : ";
        cin>>arr[i];
    }
   vector<int> result=small(arr,size);

cout<<result[0];
   return 0;
}