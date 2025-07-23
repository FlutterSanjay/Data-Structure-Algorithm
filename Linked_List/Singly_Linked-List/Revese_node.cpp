// Reverse Linked List
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node* next;
Node(int data){
  this->data=data;
  this->next=NULL;
}
};

void insetionAtTail(Node* &head,Node* &tail,int data){
  Node* temp=new Node(data);
  if(tail==NULL){
    head=temp;
    tail=temp;
    return;
  }
  tail->next=temp;
  tail=temp;
}

// Reverse Linked List
Node* reverseLinkedList(Node* &prev,Node* &curr){
  if(curr==NULL){
    return prev;
  }
  while(curr!=NULL){
    Node* forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
  }
  return prev;
}


// print linkedList
void print(Node* &head){
  Node* temp=head;
  while(temp!=NULL){
      cout<<temp->data<<" ";
      temp=temp->next;
  }
}
int main(){
  Node* head=NULL;
  Node* tail=NULL;
  insetionAtTail(head,tail,1);
  insetionAtTail(head,tail,2);
  insetionAtTail(head,tail,3);
  insetionAtTail(head,tail,4);
  insetionAtTail(head,tail,5);
  print(head);
  Node* prev=NULL;
  Node* curr=head;
  Node* newHead=reverseLinkedList(prev,curr);
  cout<<endl;
  print(newHead);

  return 0;
}