// Loop Present in Linked list or Not
//Algorithm Type - Floyd cycle Detection

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
      cout<<"Loop is present"<<endl;
      return true;
    }
  }
  cout<<"Loop is not Present"<<endl;
  return false;
  
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
  seventh->next = NULL;

  cout<<isLoop(first);
  
  

  return 0;
}