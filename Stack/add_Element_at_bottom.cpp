// Add the Element at the Bottom odf stack...
#include<iostream>
#include<stack>
using namespace std;
void bottom(stack<int> st,int size){
    int data,insert_data;
    stack<int> copy;
 int len=0;
    for(int i=1;i<=size;i++){
        len++;
        copy.push(st.top());
        st.pop();
        if(size==len){
            cout<<"Enter your no to add the element at the Bottom : ";
            cin>>insert_data;
            copy.push(insert_data);

        }
    }
    size++;

    for(int i=0;i<size;i++){
        st.push(copy.top());
        copy.pop();
    }
    for(int i=0;i<size;i++){
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main(){
    stack<int> st;
    int size,data;
    cout<<"Enter the Size of Stack : ";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"Enter your Element : ";
        cin>>data;
        st.push(data);
    }
    bottom(st,size);
   
    return 0;

}