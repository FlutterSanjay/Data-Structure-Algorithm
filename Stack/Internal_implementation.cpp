// All Basic Implementation using internal stack 
#include<iostream>
#include<stack>  // for calling stack function
using namespace std;

int main(){
    stack<int> st;
    int data;
    for(int i=0;i<5;i++){
        cout<<"Enter your Element : ";
        cin>>data;
        st.push(data);
    }
    cout<<"Enter your no to delete the element from stack : ";
    cin>>data;
    for(int i=0;i<data;i++){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}