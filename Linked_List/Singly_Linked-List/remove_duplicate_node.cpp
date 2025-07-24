// Remove the Duplicate Node from the Given Linked List

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
void insertionAtTail(Node* &head,Node* &tail,int data){
  Node* temp=new Node(data);
  if(tail==NULL){
    head=temp;
    tail=temp;
    return;
  }
  tail->next=temp;
  tail=temp;
  tail->next=NULL;
}


// Remove Duplicated Element from sorted Linked List
void removeDuplicate(Node* &head){
  if(head==NULL){
    return;
  }

  if(head->next==NULL){
    return;
  }

  Node* curr = head;

  while(curr!=NULL && curr->next!=NULL){
    if(curr->data == curr->next->data){
      Node* del=curr->next;
      curr->next = curr->next->next;
      delete del;
    }
    curr=curr->next;
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
  Node* head=NULL;
  Node* tail=NULL;
  insertionAtTail(head,tail,1);
  insertionAtTail(head,tail,2);
  insertionAtTail(head,tail,2);
  insertionAtTail(head,tail,3);
  insertionAtTail(head,tail,4);
   insertionAtTail(head,tail,4);
  print(head);
  cout<<endl;
  removeDuplicate(head);
  print(head);
  


  return 0;
}