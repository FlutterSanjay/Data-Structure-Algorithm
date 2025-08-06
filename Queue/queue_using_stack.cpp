// Implement Queue using Stacks
#include<bits/stdc++.h>
using namespace std;


class Queue{
public:
stack<int> s1;
stack<int> s2;
Queue(){}

void push(int x){
  s1.push(x);
}

// pop Operation
int pop(){
  int data=-1;
  if(!s2.empty()){
    data=s2.top();
    s2.pop();
  }else{
    //push all element  from s1 to s2
    while(!s1.empty()){

      s2.push(s1.top());
      s1.pop();
    }
    data=s2.top();
    s2.pop();
  }
  return data;
}

// front Operation
int front(){
  int front=-1;
  if(!s2.empty()){
    front=s2.top();
  }else{
    while(!s1.empty()){
      s2.push(s1.top());
      s1.pop();
    }
      front=s2.top();
  }
  return front;
}


// Empty Operation
bool empty(){
  return (s1.empty() && s2.empty());
}
};
int main(){

  Queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);

  cout<<q.front()<<endl;
  cout<<q.pop()<<endl;
  cout<<q.pop()<<endl;

  cout<<q.front()<<endl;

  cout<<q.empty()<<endl;
  
  return 0;
}