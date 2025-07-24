// Check wheather a Linked List is palindrome or not
// TC - O(n) & SC - O(1)


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
// find middle element
Node* middleElement(Node* &head){
  if(head==NULL){
    return NULL;
  }
  if(head->next == NULL){
    return head;
  }
  Node* slow=head;
  Node* fast=head;
  while(fast!=NULL){
    fast=fast->next;
    if(fast!=NULL){
      fast=fast->next;
      slow=slow->next;
    }
  }
  return slow;
}

Node* reverseLL(Node* &head){
  if(head==NULL){
    return NULL;
  };

  Node* prev=NULL;
  Node* curr=head;
  while(curr!=NULL){
    Node* forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
  }
  return prev;
}

bool comparedLL(Node* &temp1,Node* &temp2){
  if(temp1==NULL || temp2==NULL){
    return false;
  };
  while(temp2!=NULL){
    if(temp1->data != temp2->data){
      return false;
    }
    temp1=temp1->next;
    temp2=temp2->next;
  }
  return true;
}


bool isPalindrome(Node* &head){
     Node* mid=middleElement(head);
  cout<<"Mid Element:"<<mid->data<<endl;
  
  mid->next=reverseLL(mid->next); // list join ho gya aadha reverse wala
  
  Node* temp1=mid->next;
  
   Node* temp2=head;
  
    return comparedLL(temp2,temp1);
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
  insertionAtTail(head,tail,3);
  insertionAtTail(head,tail,2);
  insertionAtTail(head,tail,1);
 
  
  print(head);
  cout<<endl;
  
  if(!isPalindrome){
      cout<<"Not Palindrome";
  }else{
      cout<<"Palindrome";
  }
 
  return 0;
}