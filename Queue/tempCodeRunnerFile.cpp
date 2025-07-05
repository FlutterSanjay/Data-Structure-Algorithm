// implementing the stack using queue
#include<iostream>
#include<queue>
#include<stdbool.h>
using namespace std;
class Queue{
    public:
    int size;
       
    queue<int> q1,q2;
    void push(int data){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(data);
        while(!q2.empty()){
            q1.push(q2.front());
            q1.pop();
        }
    }
    int pop(){
        int ans=q1.front();
        q1.pop();
        return ans;
    }
    int peek(){
        return q1.front();
    }
    bool aempty(){
        return q1.empty();
    }
};

int main(){
    Queue q;
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(8);
    q.push(12);
    q.push(14);
    q.push(61);
    q.push(18);
    
    cout<<q.pop()<<" ";
    cout<<q.pop()<<" "<<endl;
    
    
    cout<<"peek Element : "<<q.peek()<<endl;
    cout<<"Empty - "<<q.aempty();
    return 0;
}