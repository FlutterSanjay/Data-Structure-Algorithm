// Sort LL using Merge Sort
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

Node* mergeLL(Node* &head1,Node* &head2){
  if(head1==NULL){

    return head2;
  }
  if(head2==NULL){
    return head1;
  }

  Node* temp1=head1;
  Node* temp2=head2;
  // dummy Node
  Node* ansHead=NULL;
  Node* ansTail=NULL;

  //Merge two list
  while(temp1!=NULL && temp2 !=NULL){
    if(temp1->data<= temp2->data){
      Node* newNode=new Node(temp1->data);
      if(ansHead==NULL){
        ansHead=newNode;
        ansTail=newNode;
      }else{
        ansTail->next=newNode;
        ansTail=newNode;
      }
      temp1=temp1->next;
    }else{
     Node* newNode=new Node(temp2->data);
      if(ansHead==NULL){
        ansHead=newNode;
        ansTail=newNode;
      }else{
        ansTail->next=newNode;
        ansTail=newNode;
      }
      temp2=temp2->next;
    }
  }

  // add remaining list
  while(temp1!=NULL){
    Node* newNode=new Node(temp1->data);
    ansTail->next=newNode;
    ansTail=newNode;
    temp1=temp1->next;
  }

  while(temp2!=NULL){
    Node* newNode=new Node(temp2->data);
    ansTail->next=newNode;
    ansTail=newNode;
    temp2=temp2->next;
  }
  return ansHead;
  
}
// find Mid of the list
Node* findMid(Node* &head){
  Node* slow=head;
  Node* fast=head->next;
  while(fast!=NULL){
    fast=fast->next;
    if(fast!=NULL){
      fast=fast->next;
      slow=slow->next;
    }
  }
  return slow;
}

// Sort List using Merge Sort
Node* sortLL(Node* &head){
  Node* temp=head;
  if(head == NULL || head->next==NULL){
    return head;
  }
  //find Mid
  Node* mid = findMid(temp);

  // Seperate left and right list
  Node* left=head;
  Node* right=mid->next;
  mid->next=NULL;

  // sort left and right list
  left=sortLL(left);
  right=sortLL(right);

  // merge left and right list
  Node* result= mergeLL(left,right);
  return result;

}


void print(Node* &head){
  Node* temp=head;
  while(temp!=NULL){
      cout<<temp->data<<" ";    
      temp=temp->next;
  }
}


int main(){
  Node* head1=new Node(4);
  Node* second = new Node(1);
  Node* third = new Node(8);
  Node* fourth = new Node(4);
  Node* fifth = new Node(5);
   Node* sixth = new Node(6);
 
  head1->next=second;
  second->next=third;
  third->next=fourth;
  fourth->next=fifth;
  fifth->next=sixth;
  sixth->next = NULL;

  print(head1);
  cout<<endl;

  Node* ans=sortLL(head1);
  print(ans);

 


  return 0;
}