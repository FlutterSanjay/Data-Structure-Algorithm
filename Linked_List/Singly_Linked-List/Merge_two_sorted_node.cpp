// Merge Two Sorted List
/*✅ List 1:

1 -> 3 -> 5 -> 7 -> 9 -> 11 -> 13 -> 15
✅ List 2:

2 -> 3 -> 4 -> 6 -> 8 -> 10

🧠 Expected Output:

1 2 3 3 4 5 6 7 8 9 10 11 13 15
*/
#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int data;
Node* next;
Node(int data){
  this->data=data;
  this->next=NULL;
}
};

Node* mergeSortedLL(Node* &head1,Node* &head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    // Step:1 create dummy Node
    Node* ansHead=NULL;
    Node* ansTail=NULL;

    //Step2: merge Two LL

    while(head1!=NULL && head2!=NULL){
        if(head1->data <= head2->data){
            Node* newNode = new Node(head1->data);
            if(ansHead==NULL){
                ansHead=newNode;
                ansTail=newNode;
            }else{
                ansTail->next=newNode;
                ansTail=newNode;
            }
            head1=head1->next;
        }else{
            Node* newNode=new Node(head2->data);
            ansTail->next = newNode;
            ansTail=newNode;
            head2=head2->next;
        }
    }

    // Ho skta hai ki First LL Null na huaa ho
    while(head1!=NULL){
        Node* newNode=new Node(head1->data);
            ansTail->next = newNode;
            ansTail=newNode;
            head1=head1->next;
    }

     // Ho skta hai ki Second LL Null na huaa ho
    while(head2!=NULL){
        Node* newNode=new Node(head2->data);
            ansTail->next = newNode;
            ansTail=newNode;
            head2=head2->next;
    }

    return ansHead;
}



void print(Node* &head){
  Node* temp=head;
  while(temp!=NULL){
      cout<<temp->data<<" ";    
      temp=temp->next;
  }
}


int main(){
  Node* head1=new Node(1);
  Node* second = new Node(3);
  Node* third = new Node(5);
  Node* fourth = new Node(7);
  Node* fifth = new Node(9);
  Node* sixth = new Node(11);
  Node* seventh = new Node(13);
  Node* eighth = new Node(15);
  head1->next=second;
  second->next=third;
  third->next=fourth;
  fourth->next=fifth;
  fifth->next=sixth;
  sixth->next=seventh;
  seventh->next=eighth;
  eighth->next=NULL;
  
  print(head1);
  cout<<endl;

  Node* head2=new Node(2);
  Node* second1 = new Node(3);
  Node* third1 = new Node(4);
  Node* fourth1 = new Node(6);
  Node* fifth1 = new Node(8);
  Node* sixth1 = new Node(10);
  head2->next=second1;
  second1->next=third1;
  third1->next=fourth1;
  fourth1->next=fifth1;
  fifth1->next=sixth1;
  sixth1->next=NULL;
  
  print(head2);
  cout<<endl;
  Node* result = mergeSortedLL(head1,head2);
  print(result);


  return 0;
}