// Implementation of Singly Link List
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* link;

    Node(int data){
        val=data;
        link=NULL;
    }

};
void insert(Node* &head,int data){
    Node* temp=new Node(data);
    temp->link=head;
    head=temp;
}

void display(Node* head){
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->val<<" ";
    temp=temp->link;
  }
}
int main(){
    Node* head=NULL;
    insert(head,2);
    insert(head,4);
    display(head);
    return 0;
}
