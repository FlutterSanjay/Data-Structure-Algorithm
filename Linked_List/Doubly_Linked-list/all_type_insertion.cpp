// Doubly Linked List
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node* next;
Node* prev;
Node(int data){
  this->data=data;
  next=NULL;
  prev=NULL;
}
};

// Insert at Head
void insertAtHead(Node* &head,Node* &tail,int data){
  Node* temp= new Node(data);
  if(head==NULL){
    head=temp;
    tail=temp;
    return ;
  }
  temp->next=head;
  head->prev=temp;
  head=temp;
}

// Insert at Tail
void InsertAtTail(Node* &head,Node* &tail,int data){
  Node* temp = new Node(data);

  if(tail == NULL){
    tail=temp;
    head=temp;
    return;
  }
  tail->next=temp;
  temp->prev=tail;
  tail=temp;
}

int findLen(Node* &head){
  Node * temp=head;
  int len=0;
  while(temp!= NULL){
    len++;
    temp=temp->next;
  }
  return len;
}
// Insert at Specific Position
void InsertAtPosition(Node* &head,Node* &tail,int pos,int data){
  Node* temp=new Node(data);
  if(head==NULL){
    head=temp;
    tail=temp;
    return;
  }
if(pos==1){
  insertAtHead(head,tail,data);
  return;
}

  int len = findLen(head);
  if(pos>=len){
    InsertAtTail(head, tail, data);
    return ;
  }
  Node* back=head;
  int i=1;
  while(i<pos-1){
    back=back->next;
    i++;
  }
  temp->next=back->next;
  back->next=temp;
  temp->prev=back;
  back->next->prev=temp;
  
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
   insertAtHead(head,tail,10);
   insertAtHead(head,tail,20);
   insertAtHead(head,tail,30);
   insertAtHead(head,tail,40);
     printLL(head);
     cout<<endl;
  InsertAtTail(head,tail,50);
  InsertAtTail(head,tail,60);
  InsertAtTail(head,tail,70);
  InsertAtTail(head,tail,80);
    printLL(head);
    cout<<endl;
  InsertAtPosition(head,tail,5,100);
    printLL(head);

  return 0;
}