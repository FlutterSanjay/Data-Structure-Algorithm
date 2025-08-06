// Implement kQueue in an Array
#include<bits/stdc++.h>
using namespace std;


class KQueue{
public:
int n,k,freespot;
int *front;
int *rear;
int *arr;
int *next;
KQueue(int n,int k){
    this->n=n;
    this->freespot=0;
  front=new int[k];
  rear=new int[k];
  arr=new int[n];
  next=new int[n];


  // initialize the fornt & rear
  for(int i=0;i<k;i++){
    front[i]=-1;
    rear[i]=-1;
  }

  // initialize the next
  for(int i=0;i<n;i++){
    next[i]=i+1;
  }
  next[n-1]=-1;
}


bool push(int data,int q){
  // Overflow
  if(freespot==-1){
    cout<<"No Empty Space"<<endl;
    return false;
  }
  //find first free spot
  int index=freespot;

  // update freespot
  freespot=next[index];

  // if first element of qth
  if(front[q]==-1){
    front[q]=index;
  }else{
    //link new element to that Q's nearest element
    next[rear[q]]=index;
  }

  //update next
  next[index]=-1;

  //update rear
  rear[q]=index;
  arr[index]=data;
  return true;
}

int pop(int q){
  // 1. underflow
  if(front[q]==-1){
    return -1;
  }

  // find index to pop
  int index=front[q];

  // front ko update
  front[q]=next[index];

  //Manage free spot
  next[index]=freespot;
  freespot=index;
  
  return arr[index];
}
};


int main(){

  KQueue q(10,3);
  q.push(10,0);
  q.push(15,0);
  q.push(20,1);
  q.push(25,1);
  q.push(30,2);
  q.push(35,2);
  q.push(40,2);

  cout<<q.pop(0)<<endl;
  cout<<q.pop(1)<<endl;
  cout<<q.pop(2)<<endl;
  cout<<q.pop(0)<<endl;
  

  return 0;
}