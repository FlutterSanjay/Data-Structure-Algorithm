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


// Delete at head
void deleteAtHead(Node* &head,Node* &tail){
  if(head==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  Node* temp=head;
  head=head->next;
  head->prev=NULL;
  temp->next=NULL;
  delete temp;
}

// Delete at Tail
void deleteAtTail(Node* &head,Node* &tail){
  
  if(tail ==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  Node* temp=head;
  while(temp->next->next !=NULL){
    temp=temp->next;
  }
  Node* del=temp->next;
  del->prev=NULL;
  temp->next=NULL;
  tail=temp;
  delete del;
}

// Find Length
int findLength(Node* &head){
  Node * temp=head;
  int len=0;
  while(temp!=NULL){
  temp=temp->next;
    len++;
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
int len = findLength(head);
  if(pos>=len){
    deleteAtTail(head,tail);
    return;
  }
  Node* temp=head;
  int i=1;
  while(i<pos-1){
    temp=temp->next;
    i++;
  }
  Node* del=temp->next;
  temp->next=temp->next->next;
  temp->next->next->prev=temp;
  del->prev = NULL;
  del->next = NULL;
  delete del;
  
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
    printLL(head);
    cout<<endl;
    deleteAtHead(head,tail);
    printLL(head);

    cout<<endl;
    deleteAtTail(head,tail);
    printLL(head);
    cout<<endl;
    deleteAtPosition(head,tail,5);
    printLL(head);
    
    

  return 0;
}