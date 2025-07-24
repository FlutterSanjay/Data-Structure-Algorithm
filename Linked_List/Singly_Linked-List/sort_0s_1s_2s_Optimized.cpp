// Optimized Sort 0s,1s,2s
// Pyaari Approach
// TC -O(n) & SC - O(1)
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


// sort 0s,1s,2s
Node* sortLL(Node* &head){
  Node* zeroHead=new Node(-1);
  Node* zeroTail=zeroHead;

  Node* oneHead=new Node(-1);
  Node* oneTail=oneHead;
  
  Node* twoHead=new Node(-1);
  Node* twoTail=twoHead;


  Node* curr=head;

  while(curr!=NULL){
      Node* temp=curr;
    if(curr->data==0){
      zeroTail->next=temp;
      zeroTail=temp;
     
      
    }else if(curr->data == 1){
      oneTail->next=temp;
        oneTail=temp;
      
      
    }else if(curr->data == 2){
        twoTail->next=temp;
        twoTail=temp;
       
      
    }
    curr=curr->next;
  }
  Node *zero = zeroHead;
  zeroHead = zeroHead->next;
  zero->next = NULL;
  delete zero;

   Node *one = oneHead;
   oneHead = oneHead->next;
   one->next = NULL;
   delete one;

     Node *two = twoHead;
   twoHead = twoHead->next;
   two->next = NULL;
   delete two;

   
   zeroTail->next = oneHead;
   oneTail->next = twoHead;
   twoTail->next = NULL;

   return zeroHead;
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
  insertionAtTail(head,tail,0);
  insertionAtTail(head,tail,0);
  insertionAtTail(head,tail,0);
  print(head);
  cout<<endl;
  Node* result=sortLL(head);
  print(result);
 

  return 0;
}