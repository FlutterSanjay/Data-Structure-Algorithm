// Add Two Linked List
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

Node* reverseLL(Node* &head){
  if(head == NULL){
    return NULL;
  }
  if(head->next == NULL){
    return head;
  }

  Node* prev=NULL;
  Node* curr=head;
  while(curr!=NULL){
    Node* forward = curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
  }
  return prev;
}


// Add two linked list
Node* AddTwoLL(Node* &head1,Node* &head2){
  if(head1==NULL){
    return head2;
  }
  if(head2==NULL){
    return head1;
  }

  // Step 1: Reverse both the LL
head1=reverseLL(head1);
head2=reverseLL(head2);


  // Step 2: Add both the LL
  Node* ansHead=NULL;
  Node* ansTail=NULL;
  int carry=0;
  while(head1!=NULL && head2!=NULL){
    int sum = carry +head1->data +head2->data;
    int digit = sum % 10;
    carry=sum/10;
    Node* newNode = new Node(digit);
    if(ansHead==NULL){
      ansHead=newNode;
      ansTail=newNode;
    }else{
      ansTail->next=newNode;
      ansTail=newNode;
    }
    head1=head1->next;
    head2=head2->next;
  }

  // ho skta hai ki first LL Null na huaa ho
  while(head1!=NULL){
    int sum=carry+head1->data;
    int digit = sum % 10;
    carry = sum /10;
    Node* newNode = new Node(digit);
    ansTail->next=newNode;
    ansTail=newNode;
    head1=head1->next;
  }

  // ho skta hai ki second LL Null na huaa ho
  while(head2!=NULL){
    int sum=carry+head2->data;
    int digit = sum % 10;
    carry = sum /10;
    Node* newNode = new Node(digit);
    ansTail->next=newNode;
    ansTail=newNode;
    head2=head2->next;
  }


  // carry bacha huaa ho
  while(carry!=0){
    int sum=carry;
    int digit = sum % 10;
    carry = sum /10;
    Node* newNode = new Node(digit);
    ansTail->next=newNode;
    ansTail=newNode;
  }

  // Step 3: Reverse the ans LL
  ansHead=reverseLL(ansHead);
  return ansHead;
  
  
}

void print(Node* &head){
  Node* temp=head;
  while(temp!=NULL){
      cout<<temp->data<<" ";    
      temp=temp->next;
  }
}


int main(){
  Node* head1=new Node(9);
  Node* second = new Node(9);
  Node* third = new Node(9);
  head1->next=second;
  second->next=third;
  third->next=NULL;
  print(head1);
  cout<<endl;

  Node* head2=new Node(9);
  Node* second1 = new Node(9);
  head2->next=second1;
  second1->next=NULL;
  print(head2);
  cout<<endl;
  Node* ans=AddTwoLL(head1,head2);
  print(ans);

  return 0;
}