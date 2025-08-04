// Reverse K first element in Queue
#include<bits/stdc++.h>
using namespace std;


void kReverse(queue<int>& q,int k){
    
    if(q.size() < k || k<=0) return;
    stack<int> st;

  int i=0;
  while(i<k){
    st.push(q.front());
    q.pop();
    i++;
  }

  
int t=st.size();
  while(t--){
    q.push(st.top());
    st.pop();
  }

  i=0;
  int n=q.size();
  while(i< n-k){
    q.push(q.front());
    q.pop();
    i++;
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
  q.push(3);
  q.push(6);
  q.push(9);
  q.push(12);
  q.push(15);
  int k=3;
  kReverse(q,k);
  printQueue(q);
  
  return 0;
}