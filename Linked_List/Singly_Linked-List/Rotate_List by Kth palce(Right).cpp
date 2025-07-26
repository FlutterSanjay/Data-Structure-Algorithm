// Rotate the Linked List by Kth Times
// SC- O(n) & TC - O(n)

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

// find Length of Linked List
int findLength(Node* &head){
  Node* temp=head;
  int len=0;
  while(temp!=NULL){
    len++;
    temp=temp->next;
  }
  return len;
}

Node* rotateList(Node* &head,int k){
  if(head==NULL|| head->next==NULL){
    return head;
  }
  int len = findLength(head);
  int k1=k%len;
  
  if(k1==0){
    return head;
  }

  // find the actual position whose next will be null
  int pos=len-k1-1;
  Node* temp=head;
  int i=0;
  while(i<pos){
    temp=temp->next;
    i++;
  }
  Node* newHead=temp->next;
  temp->next=NULL;
  Node* temp2=newHead;
  while(temp2->next!=NULL){
    temp2=temp2->next;
  }
  temp2->next=head;
  return newHead;
  
}

int main(){
  Node* head1=new Node(1);
  Node* second = new Node(2);
  Node* third = new Node(3);
  Node* fourth = new Node(4);
  Node* fifth = new Node(5);
 
  head1->next=second;
  second->next=third;
  third->next=fourth;
  fourth->next=fifth;
  fifth->next=NULL;

  print(head1);
  cout<<endl;

  Node* newHead=rotateList(head1,2);
  print(newHead);

 


  return 0;
}