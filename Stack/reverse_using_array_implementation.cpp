// reverse Element using array implementation of stack
#include<iostream>
using namespace std;
class Stack{
    int *arr;
    int *brr;
    int capacity;
    int top;
    public:
    Stack(int c){
        arr=new int[c];
        brr=new int[c];
        capacity=c;
        top=-1;
    }
    void push(int data){
        if(top==capacity-1){
            cout<<"Stack is Full ...";
            return ;
    }
    top++;
    arr[top]=data;
}
void copy(){
    for(int i=0;top<0;i++){
        brr[i]=arr[i];
        top--;
    }
    top=capacity-1;
    for(int i=0;top<0;i++){
        arr[i]=brr[i];
        top--;
    }
    for(int i=0;i<capacity-1;i++){
        cout<<arr[i]<<" ";
    }
}
};
int main(){
    int size,data;
    cout<<"Enter the size of Stack : ";
    cin>>size;
    Stack st(size);
    for(int i=0;i<size-1;i++){
        cout<<"Enter your Element : ";
        cin>>data;
        st.push(data);
    }
    st.copy();
   return 0;
}