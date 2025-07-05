// remove the element from the stack at the bottom
#include<iostream>
#include<stack>
using namespace std;
 void remove_at_bottom(stack<int>& st){
   if (st.size()==1){
    st.pop();
    return ;
   }
   int curr=st.top();
   st.pop();
   remove_at_bottom(st);
   st.push(curr);
    
}
int main(){
    stack<int> st;
    int size,data;
    cout<<"Enter the size of stack : ";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"Enter your no : ";
        cin>>data;
        st.push(data);
    }
    remove_at_bottom(st);
    size--;
    // output
    for(int i=0;i<size;i++){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;

}