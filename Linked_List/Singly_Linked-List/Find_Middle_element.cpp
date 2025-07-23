// find the Middle Element  
// Algorithm Type -Tortoise T.C - O(n)

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node* next;
Node(int data){
  this->data=data;
  next=NULL;
}
};

void insetionAtTail(Node* &head,Node* &tail,int data){
  Node* temp=new Node(data);
  if(tail==NULL){
    head=temp;
    tail=temp;
    return;
  }
  tail->next=temp;
  tail=temp;
}

// find Middle of Linked List
int findMiddle(Node* &head){
   
    
    if(head==NULL){
        return -1;
    }
    
    if(head->next==NULL){
        return head->data;
    }
    Node* slow=head;
    Node* fast=head->next;
    
    while(fast!=NULL && slow !=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow->data;
}


// print linkedList
void print(Node* &head){
  Node* temp=head;
 while(temp!=NULL){
      cout<<temp->data<<" ";
    temp=temp->next;
 }
}
int main(){
  Node* head=NULL;
  Node* tail=NULL;
  insetionAtTail(head,tail,1);
  insetionAtTail(head,tail,2);
  insetionAtTail(head,tail,3);
  insetionAtTail(head,tail,4);
  insetionAtTail(head,tail,5);
//   insetionAtTail(head,tail,6);
  print(head);
  cout<<endl;
  cout<<findMiddle(head);

  return 0;
}