// pop the Element from stack
// implementation of stack using node.........
#include<iostream>
#include<stdbool.h>
using namespace std;
class stack{
    int capacity;
    int *arr;
    int top;
    public:
    stack(int data){
        this->capacity=data;
        arr=new int[data];
        this->top=-1;
    }
    // insert the Element in stack
    void push(int data){
        if(top==capacity-1){
            cout<<"OVERFLOW !"<<endl;
        }
        top++;
        arr[top]=data;
    }

    // show the top element
      void peek(){
        if(top==-1){
            cout<<"Stack is Empty !"<<endl;
        }
        else{
            cout<<arr[top]<<" ";
        }
    }
// pop the element from stack
    void popp(int data){
       for(int i=0;i<data;i++){
         if(top==-1){
            cout<<"UNDERFLOW!"<<endl;
        }
        else {
        cout<<arr[i]<<" ";
        top--;
    }
       }
    }
    //output of stack Element
  
    void display(){
        for(int i=0;i<capacity;i++){
            cout<<arr[i]<<" ";
        }
    }

    // check the stack is Empty or Not 
    bool full(){
        if(top>=capacity){
            return 1;
        }
        else{
            return 0;
        }
    }
};
int main(){
    int size,data;
    cout<<"Enter the size of stack :";
    cin>>size;
    stack aa(size);
    for(int i=0;i<size;i++){
        cout<<"Enter your Value : ";
        cin>>data;
        aa.push(data);
    }
    aa.display( );
    cout<<endl;
  aa.peek();
    cout<<endl;
    aa.display();
    cout<<endl;
    aa.popp(3);
    cout<<endl;
    cout<<aa.full();
    return 0;

}