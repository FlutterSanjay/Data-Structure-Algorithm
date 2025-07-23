// Reverse K Group TC-O(n)

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


//find Length
int findLength(Node* &head){
    Node *temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

Node* reverseKGroup(Node* &head,int k){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        return head;
    }
    int len = findLength(head);
    if(k>len){
        return head;
    }

    // Step:1
    Node *prev = NULL;
    Node *curr = head;
    int i = 0;
    while(i<k){
        Node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        i++;
    }

    //Step:2

    if(curr!=NULL){
        head->next = reverseKGroup(curr, k);
    }
    //Step:3
    return prev;
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
  insetionAtTail(head,tail,6);
  print(head);
  cout<<endl;
  head=reverseKGroup(head,2);
  print(head);


  return 0;
}