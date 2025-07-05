// Stack Implementation using Doubly linked list...

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
class stack{
    public:
    Node* head;
    Node* tail;
    int top;
    int size;
    stack(int capacity){
        head=tail=NULL;
        top=-1;
        size=capacity-1;
    }
    void push(int data){
        if(top==size){
            cout<<"Stack is Full...";
            return;
        }
        Node* temp=new Node(data);
        if(tail==NULL){
            head=temp;
            tail=temp;
            top++;
        }
        else{
            top++;
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
    }
    // pop implementation
    int pop(){
        if(top==-1){
            cout<<"Stack is Empty...";
            return 0;
        }
        else{
            top--;
            Node* temp=tail;
            tail=tail->prev;
            tail->next=NULL;
            int val= temp->data;
            free(temp);
            return val;
        }
    }
    
    // for output
    void output(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};
int main(){
    stack aa(5);
    aa.push(1);
    aa.push(2);
    aa.push(3);
    aa.push(4);
    aa.push(5);
    aa.push(6);
    cout<<"\nPOP Element : "<<aa.pop()<<endl;
    cout<<"POP ELement : "<<aa.pop()<<endl;
    aa.output();
    return 0;
}
