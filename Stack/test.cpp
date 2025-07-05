// add element at the bottom
#include<iostream>
using namespace std;
class stack{
int *arr;
int *brr;
int size;
int top;
int top1;
public:
    stack(int capacity){
    size=capacity-1;
    arr=new int[capacity-1];
    brr=new int[capacity-1];
    top=-1;
    top1=-1;
    }
    void insert(int data){
    if(top==size) cout<<"stack is full";
    else{
        top++;
        arr[top]=data;
    }
    }
    void pop(){
    if(top==-1){
        cout<<"Stack is empty!";
        return ;
    }
    for(int i=0;i<size;i++){
          int val=arr[top--];
          top1++;
          brr[top1]= val;
         }
       }

void add_element_bottom(int data){
    if(top1<size){
         brr[++top1]=data;
        }
    for(int i=0;i<size;i++){
            top++;
            arr[top]=brr[top1--];
         }
    }
void output(){
for(int i=0;i<size;i++){
    cout<<arr[i] ;
}
}

};
int main(){
    int size;
    cin>>size;
    stack st(size);
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(4);
    st.pop();
    st.add_element_bottom(5);
    st.output();
    return 0;
}
