// copy the content one stack to another in same order
#include<iostream>
#include<stack>
using namespace std;
void copy(stack<int>st,int size ){
    stack<int> one,final;  //intialisation of stack
  
    for(int i=0;i<size;i++){
        one.push(st.top());    // copy one stack with another
        st.pop();
    }
    for(int i=0;i<size;i++){
        final.push(one.top());  // copy second stack to final stack
        one.pop();
    }
    for(int i=0;i<size;i++){  
        cout<<final.top()<<" ";
        final.pop();
    }
}

int main(){
    stack<int> st;
      int data,size;
      cout<<"Enter the size of stack : ";
      cin>>size;
    for(int i=0;i<size;i++){
        cout<<"Enter your Element :";
        cin>>data;
        st.push(data);
    }
    copy(st,size);
    return 0;

}
