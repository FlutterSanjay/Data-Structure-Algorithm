// Queue Implementation
#include<bits/stdc++.h>
using namespace std;

class Queue{
public:
int * arr;
int size;
int front;
int rear;
Queue(int s){
  this->size=s;
  arr=new int[s];
  front=0;
  rear=0;
}

void push(int data){
  if(size==rear){
    cout<<"Queue is full"<<endl;
  }else{
    arr[rear]=data;
    rear++;
  }
}

int pop(){
  if(front==rear){
    cout<<"Queue is empty1"<<endl;
  }
    int data= arr[front];
    front++;
    if(front==rear){
        front=0;
        rear=0;
    }
    return data;
}
  


int frontElement(){
  if(front==rear){
    cout<<"Queue is empty1"<<endl;
  }
    return arr[front];
 
}

bool isEmpty(){
  if(front==rear){
    return true;
  }
  return false;
}
 int isSize(){
   return rear-front;
 }
};
int main(){
  Queue q(5);
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  cout<<q.frontElement()<<endl;
  cout<<q.pop()<<endl;
  cout<<q.pop()<<endl;
   cout<<q.isSize()<<endl;
  cout<<q.isEmpty()<<endl;
  return 0;
}

