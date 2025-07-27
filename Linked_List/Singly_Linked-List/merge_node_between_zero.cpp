// Merge Nodes in Between Zeros
// TC -O(n) SC - O(n)
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

Node* mergeNode(Node* &head){
  if(head==NULL){
    return NULL;
  }

  // RequireMent
  Node* temp=head->next;
  Node* ansHead=NULL;
  Node* ansTail=NULL;
  int sum=0;

  while(temp!=NULL){
    if(temp->data==0){
      Node* ans=new Node(sum);
      if(ansHead==NULL){
        ansHead=ans;
        ansTail=ans;
      }else{
        ansTail->next=ans;
        ansTail=ans;
      }
      sum=0;
    }else{
      sum+=temp->data;
    }
    temp=temp->next;
    
  }
  return ansHead;
}

  


int main(){
  Node* head1=new Node(0);
  Node* second = new Node(1);
  Node* third = new Node(0);
  Node* fourth = new Node(3);
  Node* fifth = new Node(0);
  Node* sixth = new Node(2);
  Node* seventh = new Node(2);
  Node* eighth = new Node(0);
 
  head1->next=second;
  second->next=third;
  third->next=fourth;
  fourth->next=fifth;
  fifth->next=sixth;
  sixth->next=seventh;
  seventh->next=eighth;
  eighth->next=NULL;

  print(head1);
  cout<<endl;
  Node* ans=mergeNode(head1);
  print(ans);

 

 


  return 0;
}