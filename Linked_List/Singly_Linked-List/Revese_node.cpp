// Reverse the Node
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
// reverse the node 
Node* reverse_Node(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    // recursive call
    Node* new_head=reverse_Node(head->next);
    head->next->next=head;
    head->next=NULL;
    return new_head;
}

void display(Node* head){
 Node* temp=head;
 while(temp != NULL){
    cout<<temp->val<<" ";
    temp=temp->next;
 }
}

int main(){
    Node* head=NULL;
    insert(head,2);
    insert(head,4);
    insert(head,6);
    insert(head,8);
    insert(head,10);
    display(head);
    cout<<endl;
    Node* temp=reverse_Node(head);
    display(temp);
    return 0;
}