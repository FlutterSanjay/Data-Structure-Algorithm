// Stack using linked list representation
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class stack{
    public:
    Node* head;
    int size;
    int top;
    stack(int capacity){
        size=capacity-1;
        top=-1;
        head=NULL;
    }
    void push(int data){
        if(top==size){
            cout<<"Stack is Full...";
        }
        else{
            top++;
            Node* temp=new Node(data);
            temp->next=head;
            head=temp;
        }
    }
    int pop(){
        if(top==-1){
            cout<<"Stack is Empty...";
            return 0;
        }
        else{
            Node* temp=head;
            head=head->next;
            int val=temp->data;
            delete(temp);
            return val;
    }
}

void isFull(){
    if(top==size) cout<<"Stack is Full...";
}

void isEmpty(){
    if(top==1)
        cout << "Stack is Empty...";
}
};
int main(){
    stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    st.isFull();
    st.isEmpty();
    return 0;
}