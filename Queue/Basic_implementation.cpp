// Implementation of Queue using Array
#include<iostream>
using namespace std;
class Oueue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    Oueue(int n){
        size=n;
        arr=new int[size];
        front=rear=-1;
    }
    bool push_front(int data){
        if(isFull()){
            return false;
        }
        else if(front==-1){
            front=rear=0;
        }
        else if(front==0 && rear!=size-1){
            front=size-1;
        }
        else{
            front--;
        }
        arr[front]=data;
        return true;
    }
    //push element at the rear
    bool push_rear(int data){
        if(isFull()){
            return false;
        }
        else if(front==-1){
            front=rear=0;
        }
        else if(rear=size-1 && front!=0){
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=data;
        return true;
    }
    int pop_front(){
        if(front==-1){
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else {
            front++;
        }
        return ans;
    }
    // pop Element from the back
    int pop_rear(){
        if(front==-1){
            return -1;
        }
        int ans=arr[rear];
        arr[rear]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if(rear==0){
            rear=size-1;
        }
        else{
            rear--;
        }
        return ans;
    }
    int get_front(){
        if(front==-1){
            return -1;
        }
        return arr[front];
    }
    
    int get_rear(){
        if(front==-1){
            return -1;
        }
        return arr[rear];
    }
    // empty check
    bool isFull(){
        if((front==0 && rear == size-1)||(front!=0 && rear ==(front-1)%(size-1))){
            return true;
        }
        else{
            return false;
        }
    }
    bool isEmpty(){
        if(front==-1){
            return true;
        }
        else{
            return false;
        }
    }
  };
int main(){
    
    int size,data;
    cout<<"Enter the size of Queue : ";
    cin>>size;
    Oueue q(size);
    for(int i=0;i<size;i++){
        if(i==0){
        cout<<"Enter your no : ";
        cin>>data;
        q.push_front(data);
        }
       else{
          cout<<"Enter your no : ";
          cin>>data;
          q.push_rear(data);
      } 
}
cout<<q.pop_front()<<endl;
cout<<q.pop_rear()<<endl;

cout<<q.get_rear()<<endl;
cout<<q.get_front()<<endl;
cout<<q.isFull()<<endl;
cout<<q.isEmpty()<<endl;
return 0;
}