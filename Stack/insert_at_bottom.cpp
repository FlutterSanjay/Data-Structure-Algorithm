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


int main(){
stack<int> s;
  s.push(5);
  s.push(15);  
  s.push(27);
  s.push(32);
  s.push(11);
  int target=s.top();
  s.pop();
  insertAtBottom(s,target);
  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }

  return 0;
}