// Adding the Linked list at the Starting
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int data){
        val=data;
        next=NULL;
        prev=NULL;
    }
};
class doubly{
    public:
    Node* head;
    Node* tail;
    doubly(){
        head=NULL;
        tail=NULL;
    }

    void insert_end(int data){
        Node* end=new Node(data);

        if(tail==NULL){
            head=end;
            tail=end;
            return;
        }
        tail->next=end;
        end->prev=tail;
        tail=end;
    }

    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }
};

int main(){
    doubly aa;
    int data;
    for(int i=0;i<6;i++){
        cout<<"Enter your no : ";
        cin>> data;
        aa.insert_end(data);
    }
    aa.display();
    return 0;
}