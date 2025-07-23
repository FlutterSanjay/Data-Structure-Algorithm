// Starting Point of Loop in Linked List
// Algorithm Type -> Floyd cycle detection

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


int startingPointLoop(Node* &head){
  if(head==NULL){
    cout<<"Linked List is empty";
    return -1;
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
    slow=head;
    break;
    }
  }
  
 while(slow!=fast){
     fast=fast->next;
     slow=slow->next;
 }
 return slow->data;
  
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
  seventh->next = fifth;

  cout<<startingPointLoop(first);
  
  

  return 0;
}