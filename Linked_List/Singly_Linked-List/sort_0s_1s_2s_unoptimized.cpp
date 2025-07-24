// Sort 0s,1s,2s
// Bruth Force Method hai Optimized Code nhi hai
// TC - O(n) SC - O(1)
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
void sortLL(Node* &head){
  if(head==NULL){
    return ;
  }
Node* count=head;
  int zeroCount=0;
  int oneCount=0;
  int twoCount=0;

  while(count!=NULL){
    if(count->data==0){
      zeroCount++;
     
    }else if(count->data==1){
      oneCount++;
      
    }else{
      twoCount++;
     
    }
     count=count->next;
  }
  Node* temp=head;
  int i=0;
  while(i<zeroCount){
    temp->data=0;
    temp=temp->next;
    i++;
  }
  i=0;
  while(i<oneCount){
    temp->data=1;
    temp=temp->next;
    i++;
  }
  i=0;
  while(i<twoCount){
    temp->data=2;
    temp=temp->next;
    i++;
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
  insertionAtTail(head,tail,0);
  insertionAtTail(head,tail,0);
  insertionAtTail(head,tail,0);

  print(head);
  cout<<endl;
  sortLL(head);
  print(head);
 

  return 0;
}