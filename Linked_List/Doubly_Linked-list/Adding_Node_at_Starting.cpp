// AdNode*ing Node at Starting 
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
     void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }

    void insert_tail(int val){
        Node* temp=new Node(val);
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }
        temp->next=head;
        head->prev=temp;
        head=temp;
        return;
    }
   
};

int main(){
    doubly aa;
   int data;
   for(int i=0;i<5;i++){
    cout<<"Enter your no : ";
    cin>>data;
    aa.insert_tail(data);
   }    
    aa.display();
    return 0;
}