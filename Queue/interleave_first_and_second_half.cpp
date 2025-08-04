// interleave first and second half of queue
#include<bits/stdc++.h>
using namespace std;

void Interleave(queue<int> &q){
  if(q.empty()) return;
 // requirement
  int n=q.size();
  queue<int> q1;
  queue<int> q2;
  int t=0;

    t=q.size()/2;
 

  // split queue
  for(int i=0;i<t;i++){
    q1.push(q.front());
    q.pop();
  }

  for(int i=0;i<n-t;i++){
    q2.push(q.front());
    q.pop();
  }

  // interleave
  while(!q1.empty() && !q2.empty()){
    q.push(q1.front());
    q1.pop();

    q.push(q2.front());
    q2.pop();
  }

  while(!q1.empty()){
    q.push(q1.front());
    q1.pop();
  }

  while(!q2.empty()){
    q.push(q2.front());
    q2.pop();
  }
}

void printQueue(queue<int> &q){
    int i=0;
    while(!q.empty()){
        cout<<q.front() <<" ";
        q.pop();
    }
}
int main(){
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  q.push(6);
  q.push(7);
  q.push(8);
    q.push(9);

  Interleave(q);
  printQueue(q);
  


  return 0;
}