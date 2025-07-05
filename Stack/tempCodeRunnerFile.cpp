// reverse the stack 
#include<iostream>
#include<stack>
using namespace std;

void reverse(stack<int>&st){
    stack<int>t1;

    while(not st.empty()){
        int curr=st.top();
        st.pop();
        t1.push(curr);
    }
    while(not t1.empty()){
        int curr=t1.top();
        t1.pop();
        cout<<curr<<" ";
    }
    
}
int main(){
    stack<int> st;
    int size,data;
    cout<<"Enter your Stack size : ";
    cin>>size;
    for(int i=0;i<size;i++){
     cout<<"Enter your Element : ";
     cin>>data;
     st.push(data);
    }
    reverse(st);
    for(int i=0;i<size;i++){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}