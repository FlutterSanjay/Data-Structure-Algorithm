// Reverse Stack
#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int>&s,int target){
    if(s.empty()){
        s.push(target);
        return;
    }

    int temp = s.top();
    s.pop();

    insertAtBottom(s, target);

    s.push(temp);
}

void reverseStack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int target = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, target);
}
int main(){

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverseStack(st);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}