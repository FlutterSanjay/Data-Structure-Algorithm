// impementation of stack using array
#include<iostream>
#include<stdbool.h>
using namespace std;
class Stack{
    int *arr;
    int capacity;
    int top;
    public:
    Stack(int c){
        capacity=c;
        top=-1;
        arr=new int[c];
    }
    void push(int data){
        if(top==capacity-1){
            cout<<"Stack is full...";
            return;
        }
        top++;
        arr[top]=data;
    }
    
    int pop(){
        if(top==-1){
            cout<<"Stack is Full ...";
            return 0 ;
        }
        return arr[top--];
    }
    
    void isEmpty(){
        if(top==-1) cout<<"Stack is Empty...";
        else cout<<"Stack is Not Empty...";
    }
     
     void isFull(){
         if(top==capacity-1) cout<<"Stack is Full...";
         else cout<<"Stack is Not Full...";
     }
    int size(){
        return capacity-1;
    }
};

int main(){
    int size,data;
    cout<<"Enter the size of stack : ";
    cin>>size;
    Stack st(size);
    for(int i=0;i<size-2;i++){
        cout<<"Enter your no : ";
        cin>>data;
        st.push(data);
    }
    cout<<"Pop_Element : "<<st.pop()<<endl;
   // cout<<"Empty : "<<st.isEmpty()<<endl;
    //cout<<"Full : "<<st.isFull()<<endl;
    cout<<"size of Stack : "<<st.size()<<endl;
    st.isEmpty();
    cout<<endl;
    st.isFull();
    
    return 0;
}
