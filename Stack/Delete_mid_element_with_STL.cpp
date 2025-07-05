// Delete Middle Element uding STL
#include<iostream>
#include<stack>
using namespace std;
int delete_mid(stack<int> &st){
    int mid=st.size()/2;
    int cur=0;
    while(cur!=mid){
        cur++;
        st.pop();
    }
    int var=st.top();
    st.pop();
    return var;
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<"Delete Middle : "<<delete_mid(st)<<endl;
    return 0;
}