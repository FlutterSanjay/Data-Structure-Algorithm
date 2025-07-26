// Reverse Linked List
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node* next;
Node(int data){
  this->data=data;
  next=NULL;
}
};

void insertionAtTail(Node* &head,Node* &tail,int data){
  Node* temp=new Node(data);
  if(tail==NULL){
    head=temp;
    tail=temp;
    temp->next=temp;
    return;
  }
  tail->next=temp;
  tail=temp;
  tail->next=head;
}


bool findCircularList(Node* &head){
  if(head==NULL){
    return false;
  }
  Node* temp=head;
  do{
    temp=temp->next;
    if(temp==head){
        return true;
    }
  }while(temp!=head);
  return false;
}
// print linkedList
void print(Node* &head){
  Node* temp=head;
 do{
     cout<<temp->data<<" ";
     temp=temp->next;
 }while(temp!=head);
 
}
int main(){
  Node* head=NULL;
  Node* tail=NULL;
  insertionAtTail(head,tail,1);
  insertionAtTail(head,tail,2);
  insertionAtTail(head,tail,3);
  insertionAtTail(head,tail,4);
  insertionAtTail(head,tail,5);
  insertionAtTail(head,tail,6);
  print(head);
  cout<<endl;
  cout<<findCircularList(head);


  return 0;
}