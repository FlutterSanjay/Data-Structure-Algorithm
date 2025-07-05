// Check Palindrome or Not
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;

    Node(int data){
        val=data;
        next=NULL;
    }
};

void insert(Node* &head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}
void insert_tail(Node* &head,int data){
    Node* temp=new Node(data);
    Node* lnode=head;
    while(lnode->next != NULL){
        lnode=lnode->next;
    }
    lnode->next=temp;
}

bool palin(Node* &head){
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* temp=slow->next;
    Node* prev=slow;
    slow->next=NULL;

    // reverse the second half node
    while(temp!=NULL){
        Node* next_node=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next_node;
    }
    // compare two linked list
    Node* head1=head;
    Node* head2=prev;
    while(head2!=NULL){
        if(head1->val!=head2->val){
         return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}
void display(Node* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}
int main(){
    Node* head=NULL;
    insert(head,2);
    int data;
    for(int i=0;i<5;i++){
        cout<<"Enter your no:";
        cin>> data;
        insert_tail(head,data);
    }
    display(head);
    cout<<endl;
    cout<<palin(head);    // 1- true,0-false;
    return 0;
}