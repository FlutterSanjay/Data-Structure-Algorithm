// Delete n nodes after skiping m nodes
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


void print(Node* &head){
  Node* temp=head;
  while(temp!=NULL){
      cout<<temp->data<<" ";    
      temp=temp->next;
  }
}


Node* deleteNode(Node* &head,int S,int D){
  if(head==NULL || D==0){
    return head;
  }
  Node* temp=head;

  //skip Part

  if(S==0){
    int i=0;
    while(i<D && temp!=NULL){
      Node* del=temp;
      del->next=NULL;
      temp=temp->next;
      i++;
      delete del;
      head=temp;
    }
    return head;
  }
  while(temp!=NULL){
  int i=0;
  
  while(i<S-1 && temp!=NULL){
    temp=temp->next;
    i++;
  }
  if(temp==NULL || temp->next==NULL){
    return head;
  }
  //delete Part
  Node* curr=temp->next;
  i=0;
  while(i<D && curr!=NULL){
    Node* del=curr;
  
    curr=curr->next;
    del->next=NULL;
    delete del;
     i++;
  }
  
  temp->next=curr;
  temp=curr;
  }
  return head;
  
  
}

int main(){
  Node* head1=new Node(1);
  Node* second = new Node(2);
  Node* third = new Node(3);
  Node* fourth = new Node(4);
  Node* fifth = new Node(5);
   Node* sixth = new Node(6);
   Node* seven = new Node(7);
 
  head1->next=second;
  second->next=third;
  third->next=fourth;
  fourth->next=fifth;
  fifth->next=sixth;
  sixth->next=seven;
  seven->next=NULL;

  print(head1);
  cout<<endl;
  int S=1;
  int D=2;
  head1=deleteNode(head1,S,D);
  print(head1);

 


  return 0;
}