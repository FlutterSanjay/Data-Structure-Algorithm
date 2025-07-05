// Implementing the Circular Queue
#include<iostream>
using namespace std;

class queue{
    
    int *arr;
    int front;
    int back;
    int size;
    public:
    queue(){
        cout<<"Enter the size of Queue :";
        cin>>size;
        arr=new int[size];
        front=back=-1;
    }
    void insert(int data){
        if((front== 0 && back== size-1) || (back==(front-1)%(size-1))){
            cout<<"Queue is Full ..";
        }
        else if(front==-1){
            front=back=0;
            arr[back]=data;
        }
        else if(front!=0 && back== size-1){
            back=0;
            arr[back]=data;
        }
        else {
            back++;
        }
    }
    
    int pop(){
        if(front==-1){
            cout<<"Queue is Empty...";
            return -1;
        }
        int ans=arr[front];
        if(front==back){
            front=back=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else {
            front++;
        }
        return ans;
        }
};
    
    int main(){
        queue q;
        int data,del;
        cout<<"How many you want to insert : ";
        cin>>del;
        for(int i=0;i<del;i++){
            cout<<"Enter your No : ";
            cin>>data;
            q.insert(data);
        }
        int remove=q.pop();
        cout<<"Remove Element : "<<remove<<endl;
        return 0;
    }