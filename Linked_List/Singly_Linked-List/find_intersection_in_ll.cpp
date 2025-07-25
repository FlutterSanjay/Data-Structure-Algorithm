// Find the Intersection b/w two Linked List
// TC -O(n) SC- O(1)
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
// Insertection Of LL
Node* intersection(Node* &head1,Node* &head2){
  Node* temp1=head1;
  Node* temp2=head2;
  int lenA=0;
  int lenB=0;

 

  // for temp1
  while(temp1!=NULL){
    temp1=temp1->next;
    lenA++;
  }

  // for temp2
  while(temp2!=NULL){
    temp2=temp2->next;
    lenB++;
  }
int diff=abs(lenA-lenB);
  // checking which is greater
  if(lenA>lenB){
    while(diff--){
      head1=head1->next;
    }
  }else{
    while(diff--){
      head2=head2->next;
    }
  }

  while(head1!= head2){
    head1=head1->next;
    head2=head2->next;
  }
  if( head1==head2){
      return head1;
  }else{
   return NULL;   
  }
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
  Node* second = new Node(9);
  Node* third = new Node(1);
  Node* fourth = new Node(2);
  Node* fifth = new Node(4);
 
  head1->next=second;
  second->next=third;
  third->next=fourth;
  fourth->next=fifth;
  fifth->next=NULL;

  Node* head2=new Node(3);
 

  head2->next=fourth;
 
  
  
  
  print(head1);
  cout<<endl;
  print(head2);
  cout<<endl;
  Node* ans=intersection(head1,head2);
  cout<<ans->data;

 


  return 0;
}