// Remove the Duplicate Element from UnSorted Linked List
// TC - O(n2) SC- O(1)


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


// Remove the Duplicate from unsorted Linked List
void removeDuplicate(Node* &head){
  if(head==NULL){
    return;
  }
  if(head->next==NULL){
    return;
  }
  Node* prev=head;
 
  while(prev!=NULL){
       Node* curr=prev;
    while(curr!=NULL && curr->next !=NULL){
      if(prev->data==curr->next->data){
        Node* temp=curr->next;
        curr->next=curr->next->next;
        delete temp;
      }else{
      curr=curr->next; // is se bagal wala bhi check karega
      // Or jaha else part use nhi kiya tho koi node same bagal mai hoga tho usko skip kr dega 
      }
    }
    prev=prev->next;
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
  insertionAtTail(head,tail,4);
  insertionAtTail(head,tail,2);
  insertionAtTail(head,tail,1);
  insertionAtTail(head,tail,4);
  insertionAtTail(head,tail,4);
    insertionAtTail(head,tail,7);
  print(head);
  cout<<endl;
  removeDuplicate(head);
  print(head);


  return 0;
}