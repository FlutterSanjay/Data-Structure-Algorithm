// adding the node at starting
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

class circular{
    public:
    Node* head;
    circular(){
        head=NULL;
    }
};

void insert(Node* &head,int data){
    Node* new_node=new Node(data);
    if(head==NULL){
        head=new_node;
        head->next=head;
        return ;
    }
    Node* tail=head;
    while(tail->next!=head){
        tail=tail->next;
    }
    tail->next=new_node;
    new_node->next=head;
    head=new_node;
}

void display(Node* head){
    Node* temp=head;
    do{
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    while(temp!=head);
}

int main(){
    circular aa;
    int data;
    for(int i=0;i<5;i++){
        cout<<"Enter your no :";
        cin>>data;
        insert(aa.head,data);
    }
    display(aa.head);
    return 0;
}