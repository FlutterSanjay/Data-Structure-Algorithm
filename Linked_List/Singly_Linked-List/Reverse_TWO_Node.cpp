#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
void insert(Node* &head,int data){
    Node* temp=new Node(data);
    Node* head1=head;
    while(head1->next!=NULL){
        head1=head1->next;
    }
    head1->next=temp;
}
// Reverse two node at a tiome
Node* reverse(Node* &head){
    Node* head1=head;
    while(head1!=NULL && head1->next!=NULL){
        int temp=head1->data;
        head1->data=head1->next->data;
        head1->next->data=temp;
        head1=head1->next->next;
    }
    return head;
}
void display(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    Node* head=new Node(1);
    insert(head,2);
    insert(head,2);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    insert(head,7);
    
Node* result=reverse(head);
display(result);
return 0;
    
}