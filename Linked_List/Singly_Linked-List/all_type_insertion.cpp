// insertion in linked list
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

// Insert at Head
void InsertAtHead(Node* &head,Node* & tail,int data){
  Node* temp =new Node(data);
  if(head==NULL){
    head=temp;
      tail=temp;
    return;
  }
  temp->next=head;
  head=temp;
}

// Insert At Tail
void InsertAtTail(Node* &head,Node* &tail,int data){
  Node* temp = new Node(data);
  if(tail==NULL){
    head=temp;
      tail=temp;
    return;
  }
  tail->next=temp;
  tail=temp;
}

// find Lenght
int findLen(Node* &head){

  Node* temp=head;
  int len=0;
  while(temp!=NULL){
    len++;
    temp=temp->next;
  }
  return len;
}

// Insert at Position
void InsertAtPosition(Node* &head,Node* &tail,int data,int pos){
  Node* temp=new Node(data);
  if(head==NULL){
    head=temp;
    tail=temp;
    return;
  }
  if(pos==1){
    InsertAtHead(head, tail,data);
    return;
  }

  int len=findLen(head);
  if(pos>=len){
    InsertAtTail(head,tail,data);
    return;
  }

  // prev & curr
  Node* prev = head;
  int i=1;
  while(i<pos - 1){
    prev=prev->next;
    i++;
  }
  Node* curr=prev->next;
  temp->next=curr;
  prev->next=temp;
}

void printLL(Node* head){
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}
int main(){
Node* head=NULL;
  Node* tail=NULL;
  InsertAtHead(head,tail,10);
  InsertAtHead(head,tail,20);
  InsertAtTail(head,tail,30);
  InsertAtTail(head,tail,40);
  printLL(head);
  InsertAtPosition(head,tail,100,3);
  cout<<endl;
  printLL(head);
  
  return 0;
}