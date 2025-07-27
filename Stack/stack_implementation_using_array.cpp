// Stack Implementation using Array

#include<bits/stdc++.h>
using namespace std;


class Stack{
public:
int top;
int *arr;
int size;

Stack(int size){
  this->size=size;
  this->arr=new int[size];
  this->top=-1;
}

// Stack Operation

void push(int data){
  // Check size Available or not
  if(size-top>1){
    top++;
    arr[top]=data;
  }else{
    cout<<"Stack Overflow"<<endl;
  }
}

//Pop Operation
void pop(){
  // Check Empty or not
  if(top==-1){
    cout<<"Stack Underflow"<<endl;
  }else{
    top--;
  }
}

// Top Element on Stack
int getTop(){
  if(top==-1){
    return -1;
  }else{
    return arr[top];
  }
}

// Size of Stack
int getSize(){
  return top+1;
}

// Empty Operation
bool isEmpty(){
  if(top==-1){
    return true;
  }else{
    return false;
  }
}
};
int main(){
  Stack s(5);
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.pop();
  cout<<s.getTop()<<endl;
  cout<<s.getSize()<<endl;
  cout<<s.isEmpty()<<endl;
  return 0;
}