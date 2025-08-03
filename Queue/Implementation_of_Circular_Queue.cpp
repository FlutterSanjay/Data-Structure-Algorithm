// Implement circular Queue
#include<bits/stdc++.h>
using namespace std;
class CQueue{
public:
int * arr;
int front;
int rear;
int size;
CQueue(int n){
  this->size=n;
  arr=new int[n];
  front =-1;
  rear=-1;
}

// Push
void push(int data){
  // full or not
  if(front==0 && rear==size-1 ){
    cout<<"Queue is full"<<endl;
    return;
  }else{
    if(front==-1){
      front=0;
      rear=0;

      arr[rear++]=data;
    }else if(rear==size -1 && front!=0){
        rear=0;
        arr[rear]=data;
        
    }else{
      arr[rear++]=data;
      }
  }
}
//Pop
int pop(){
  // empty or not 
  if(front==-1){
    cout<<"Queue is empty"<<endl;
    return -1;
  }
  
    int data=arr[front++];
  if(front==rear){
    front=-1;
    rear=-1;
  }
  return data;
}

};

int main(){
  CQueue q(5);
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
      q.push(5);


  cout<<q.pop()<<endl;
  cout<<q.pop()<<endl;
  cout<<q.pop()<<endl;
  cout<<q.pop()<<endl;

      cout<<q.pop()<<endl;


  return 0;
}