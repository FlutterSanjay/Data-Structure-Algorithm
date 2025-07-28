// insert at Bootom
#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int>& s,int target){
  if(s.empty()){
    s.push(target);
    return ;
  }
  int temp=s.top();
  s.pop();

  //recursive call
  insertAtBottom(s,target);
  s.push(temp);
}
void printStack(stack<int>& s){
     while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }
 
}
void solveStack(stack<int>& s){
    if(s.empty()){
        cout<<"Stack is Empty!"<<endl;
        return;
    }
    int target=s.top();
  s.pop();
  insertAtBottom(s,target);
  printStack(s);
    
}

int main(){
stack<int> s;
  s.push(5);
  s.push(15);  
  s.push(27);
  s.push(32);
  s.push(11);
  
  solveStack(s);
  

  return 0;
}