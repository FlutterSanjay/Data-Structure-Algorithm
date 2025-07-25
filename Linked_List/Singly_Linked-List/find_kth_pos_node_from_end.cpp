// Find Kth Node from the End Of Linked List.
//T.C - O(n) & S.C - O(1)
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
// Revese Liked List
Node* reverseLL(Node* &head){
  if(head==NULL){
    return NULL;
  }
  Node* prev=NULL;
  Node* curr = head;
  while(curr!=NULL){
    Node* forward = curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
  }
  return prev;
}

// find length
int findLength(Node* &head){
  Node* temp=head;
  int len=0;
  while(temp!=NULL){
    len++;
    temp=temp->next;
  }
  return len;
}
// kth Node from end;
Node* kthNode(Node* &head,int pos){
 
  if(head==NULL){
    return NULL;
  }
  int len=findLength(head);
  if(pos>len){
    return NULL;
  }
   Node* temp=reverseLL(head);
  int i=0;
  while(i<pos){
    temp=temp->next;
    i++;
    
  }
  return temp;
}


void print(Node* &head){
  Node* temp=head;
  while(temp!=NULL){
      cout<<temp->data<<" ";    
      temp=temp->next;
  }
}


int main(){
  Node* head1=new Node(1);
  Node* second = new Node(3);
  Node* third = new Node(5);
  Node* fourth = new Node(7);
  Node* fifth = new Node(9);
  Node* sixth = new Node(11);
  Node* seventh = new Node(13);
  Node* eighth = new Node(15);
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
  Node* temp=kthNode(head1,3);
  cout<<temp->data;
  

 


  return 0;
}