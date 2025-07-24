// remove Loop using Singly Linked List
// Agorithm Type: Floyd cycle detection
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


bool isLoop(Node* &head){
  if(head==NULL){
    cout<<"Linked List is empty";
    return false;
  }
  Node* slow=head;
  Node* fast=head;
  while(fast!=NULL){
    fast=fast->next;
    if(fast!=NULL){
      fast=fast->next;
      slow=slow->next;
    }

    if(fast==slow){
      cout<<"Loop is present";
      return true;
    }
  }
  return false;
  
}

void removeLoop(Node* &head){
  if(head==NULL){
    cout<<"Linked List is empty";
    return;
  }
  Node * slow=head;
  Node * fast=head;
  while(fast!=NULL){
    fast=fast->next;
    if(fast!=NULL){
      fast=fast->next;
      slow=slow->next;
    }

    if(slow==fast){
      slow=head;
      break;
    }
  }
  Node* prev=fast;
  while(slow!=fast){
    prev=fast;
    slow=slow->next;
    fast=fast->next;
  }
  prev->next=NULL;
  return;
}

void print(Node* &head){
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}


int main(){
Node* first=new Node(10);
  Node* second=new Node(20);
  Node* third=new Node(30);
  Node* fourth=new Node(40);
  Node* fifth=new Node(50);
  Node* sixth=new Node(60);
  Node* seventh=new Node(70);

  first->next=second;
  second->next=third;
  third->next=fourth;
  fourth->next=fifth;
  fifth->next=sixth;
  sixth->next=seventh;
  seventh->next = fourth;
  removeLoop(first);

  cout<<isLoop(first)<<endl;
  print(first);
  
  

  return 0;
}