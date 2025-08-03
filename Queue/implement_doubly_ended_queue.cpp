// Implement circular Queue
#include<bits/stdc++.h>
using namespace std;
class DQueue{
public:
int * arr;
int front;
int rear;
int size;
DQueue(int n){
  this->size=n;
  arr=new int[n];
  front =-1;
  rear=-1;
}


//push rear ->rear ke taraf push krna hai
void push_rear(int data){
  if((rear+1)%size == front){
    cout<<"Queue is full"<<endl;
    return;
  }else if(front==-1){
    front=0;
    rear=0;
      }
      else{
          rear++;
      }
    arr[rear]=data;
  
}


//push front ->front ke taraf push krte le jana hai (front--)
void push_front(int data){
  if((rear+1)%size ==front){
    cout<<"Queue is full"<<endl;
    return;
  }else if(front==-1){
    front=rear=0;
  }else if(front==0 && rear !=size-1){ // set krna last index pe
    front=size-1;
  }else{
      front--;
  }
    arr[front]=data;
}

//Pop front 
void pop_front(){
  // empty or not 
  if(front==-1){
    cout<<"Queue is empty"<<endl;
    return ;
  }else if(front==rear){
       arr[front]=-1;
    front=-1;
    rear=-1;
  }
  else if(front==size-1){ // sare delete ho gye hai
   arr[front]=-1;
    front=-1;
  }
 else{
     arr[front]=-1;
     front++;
 }

 
}

//pop_rear
void pop_rear(){
  if(front==-1){
    cout<<"Queue is empty"<<endl;
    return ;
  }
 
  else if(front==rear){
       arr[front]=-1;
        front=-1;
    rear=-1;
  }else if(rear==0){
       arr[rear]=-1;
    rear=size-1;
  }else{
      arr[rear]=-1;
      rear--;
  }

}


void print(){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
};


int main(){

  DQueue q(5);  
  q.push_rear(1);
  q.push_rear(2);

 q.push_front(6);
  q.push_front(7);
  q.push_front(8);
   

  q.print();
  cout<<endl;
// q.pop_front();
// q.pop_front();


q.pop_rear(); // rear nhi work kr rha plsss correct it

q.print();

//   cout<<q.pop_front()<<endl;
//   cout<<q.pop_front()<<endl;
    return 0;
}