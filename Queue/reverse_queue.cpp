// Reverse queue
#include<bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int> &q){
    if(q.size() == 0){
        return;
    }
    int t=q.front();
    q.pop();
    
    reverseQueue(q);
    
    q.push(t);
}

void printQueue(queue<int> &q){
    int i=0;
    while(i<q.size()){
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
    
    reverseQueue(q);
    printQueue(q);
  
    return 0;
}