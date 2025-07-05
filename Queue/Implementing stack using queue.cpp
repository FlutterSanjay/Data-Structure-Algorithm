// implementation of stack using queue;
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

class queue{
    public:
    int front;
    int rear;
    Node* head;
    Node* tail;
    int size;
    queue(int capacity){
        size=capacity-1;
        head=NULL;
        tail=NULL;
        front=-1;
        rear=-1;
    }
    void push(int data){
        if(rear==size){
            cout<<"Stack is Full...";
        }
        else if(front==-1 && rear==-1){
            front++;
            rear++;
            Node* temp=new Node(data);
            if(head==NULL){
                head=temp;
                tail=temp;
                return ;
            }
        }
        else{ 
             Node* temp=new Node(data);
                rear++;
                tail->next=temp;
                temp->prev=tail;
                tail=temp;
            }
        
    }
    int pop(){
        if(front==rear) {
            cout<<"Queue is Empty...";
            return 0;
        }
        else{
            Node* temp=tail;
            tail=tail->prev;
            tail->next=NULL;
            int val=temp->data;
            free(temp);
            return val;
        }
    }
};
int main(){
    queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5); 
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    return 0;
}