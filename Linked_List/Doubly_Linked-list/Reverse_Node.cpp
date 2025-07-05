// Reverse the Node
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
    void insert_tail(int data){
        Node* end=new Node(data);
        if(head==NULL){
            head=end;
            tail=end;
        }
        tail->next=end;
        tail->prev=tail;
        tail=end;
        return ;
    }
   
    
};

void display(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }
 void reverse(Node* &head,Node* &tail){
        Node* curr=head;
        while(curr!=NULL){
            Node* nextptr=curr->next;
            curr->next=curr->prev;
            curr->prev=nextptr;
            curr=nextptr;
        }
        //swapping head and tail pointer
        Node* newHead=tail;
        tail=head;
        head=newHead;
    }


int main(){
    doubly aa;
    int data;
    for(int i=0;i<5;i++){
        cout<<"Enter your no : ";
        cin>>data;
        aa.insert_tail(data);
    }
   //aa.display();
    reverse(aa.head,aa.tail);
    display(aa.head);
    return 0;

}