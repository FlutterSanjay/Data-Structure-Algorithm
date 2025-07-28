// Sort Stack
#include<bits/stdc++.h>
using namespace std;

void insertedSort(stack<int>&s,int temp){
    if(s.empty()){
        s.push(temp);
        return;
    }

    if(s.top()>= temp){
        s.push(temp);
        return;
    }

    int top = s.top();
    s.pop();

    insertedSort(s, temp);
    s.push(top);
}

void sortStack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();

    sortStack(s);
    insertedSort(s, temp);
}


void stackPrint(stack<int> s){
  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }
}

int main(){
    stack<int> s;
      s.push(10);

    s.push(20);
    s.push(5);
    s.push(1);
    sortStack(s);
    stackPrint(s);
    return 0;
}