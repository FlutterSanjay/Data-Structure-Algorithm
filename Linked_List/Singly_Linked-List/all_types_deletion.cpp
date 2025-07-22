// Deletion in Linked List
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node * next;
Node(int data){
  this->data=data;
  next=NULL;
}
};

void InsertAtTail(Node* &head,Node* &tail,int data){
  Node* temp=new Node(data);
  if(tail==NULL){
    head=temp;
    tail=temp;
    return;
  }
  tail->next=temp;
  tail=temp;
}

// Deletion at Head
void deleteAtHead(Node* &head,Node* &tail){
  if(head == NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  Node * temp=head;
  head=head->next;
  temp->next=NULL;
  delete temp;
  
}

// Deletion at Tail
void deleteAtTail(Node* &head,Node* &tail){
  if(tail==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  if(head==tail){
      head=head->next;
      tail=head;
      return;
  }
  Node* temp=head;
  while(temp->next->next !=NULL){
    temp=temp->next;
  }
  Node* prev = temp;
  delete temp->next;
  temp->next=NULL;
  tail=prev;
}

// find Lenght of Linked List
int findLenght(Node* &head){
  Node* temp=head;
  int len=0;
  while(temp!=NULL){
    len++;
    temp=temp->next;
  }
  return len;
}
// Delete at Specific Position
void deleteAtPosition(Node* &head,Node* &tail,int pos){
  if(head==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  if(pos==1){
    deleteAtHead(head,tail);
    return;
  }
  int len=findLenght(head);
  if(pos>=len){
    deleteAtTail(head,tail);
    return;
  }
  Node* prev=head;
  int i=1;
  while(i<pos-1){
    prev=prev->next;
    i++;
  }
  Node* curr=prev->next;
  prev->next=curr->next;
  delete curr;
}

void printLL(Node* &head){
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}

int main(){
  Node* head=NULL;
  Node* tail=NULL;
  InsertAtTail(head,tail,10);
  InsertAtTail(head,tail,20);
  InsertAtTail(head,tail,30);
  InsertAtTail(head,tail,40);
   InsertAtTail(head,tail,50);
    InsertAtTail(head,tail,60);
  printLL(head);
  cout<<endl;
 deleteAtTail(head, tail);
  printLL(head);
    cout<<endl;
 deleteAtTail(head, tail);
  printLL(head);
  cout<<endl;
  
  deleteAtPosition(head,tail,1);
  printLL(head);
  



  return 0;
}