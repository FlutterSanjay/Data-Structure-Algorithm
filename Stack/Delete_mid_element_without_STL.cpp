// Delete the Middle Element from Stack
#include<iostream>
using namespace std;
class stack{
    public:
    int *arr;
    int size;
    int top;
    stack(int capacity){
        arr=new int[capacity];
        size=capacity-1;
        top=-1;
    }

    // insert Stack Element
    void push(int data){
        if(top==size) cout<<"Stack is Full...";
        else{
            top++;
            arr[top]=data;
        }
    }
    int pop(){
        if(top==-1) cout<<"Stack is Empty....";
        else{
            int var=arr[top--];
            return var;
        }
    }

    int delete_mid(){
        if(top==-1) cout<<"Stack is Empty...";
        else{
            int cur=0;
            int mid=size/2;
            while(cur!=mid){
                cur++;
                pop();
            }
            int val=arr[top];
            pop();
            return val;
        }
    }
};
int main(){
    stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<"Deleted Middle Element :"<<st.delete_mid();
    return 0;
}