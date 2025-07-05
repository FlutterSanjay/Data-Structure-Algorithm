// span stock 
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> span_stock(int arr[],int size){
    vector<int>res;
    stack<pair<int,int>> st;
    for(int i=0;i<size;i++){
        int span=1;
        while(!st.empty() && st.top().first<arr[i]){
            span=span+st.top().second;
            st.pop();
        }
        st.push({arr[i],span});
        res.push_back(span);

    }
    return res;
}
int main(){
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cout<<"Enter your no : ";
        cin>>arr[i];
    }
   vector<int> res= span_stock(arr,size);
   for(int i=0;i<size;i++){
    cout<<res[i]<<" ";
   }
   return 0;
}