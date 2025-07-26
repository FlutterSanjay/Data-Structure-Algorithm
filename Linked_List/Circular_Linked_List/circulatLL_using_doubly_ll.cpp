// Circular Linked List using Doubly Linked List
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

void insertionOfCircularLinkedList(Node* &head,Node* & tail,int data){
Node* temp=new Node(data);
if(tail==NULL){
    head=temp;
    tail=temp;
    temp->next=temp;
    temp->prev=temp;
    return;
}
    
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    tail->next=head;
    head->prev=tail;
}

void printCircularLinkedList(Node* &head){
    Node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;
    insertionOfCircularLinkedList(head,tail,10);
        insertionOfCircularLinkedList(head,tail,20);
            insertionOfCircularLinkedList(head,tail,30);
                insertionOfCircularLinkedList(head,tail,40);
                    insertionOfCircularLinkedList(head,tail,50);
                    printCircularLinkedList(head);




    
    
    return 0;
}