#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void reverse(stack<int> &st){
    stack<int> copy;
    for(int i=0;!st.empty();i++){
        copy.push(st.top());
        st.pop();
    }
    vector<int> arr;
    for(int i=0;!copy.empty();i++){
        arr.push_back(copy.top());
        copy.pop();
    }
    int si=arr.size();
    for(int i=0;i<si;i++){
        st.push(arr[(si-1)-i]);
    }
    cout<<"Reverse of Stack : ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    reverse(st);
    return 0;
}