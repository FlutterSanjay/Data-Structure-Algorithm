// adding the node at the end
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* link;

    Node(int data){
        val=data;
        link=NULL;
    }
};
 void insert(Node* &head,int data){
     Node* temp=new Node(data);
     temp->link=head;
     head=temp;
 }
 void insertT(Node* &head,int val){
    Node* temp=new Node(val);
    Node* lnode=head;
    while(lnode->link != NULL){
        lnode=lnode->link;
    }
    lnode->link=temp;
 }
 
 void display(Node* head){
    Node* temp=head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp=temp->link;
    }
 }

 int main(){
    int data;

    Node* head=NULL;
    insert(head,2);
    for(int i=1;i<=5;i++){
        cout<<"Enter your no: ";
        cin>> data;
    insertT(head,data);
    }
    insertT(head,6);
    display(head);
    return 0;
    
 }