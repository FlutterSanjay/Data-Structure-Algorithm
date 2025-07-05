// add the node at the End
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
void insert(Node* & head,int data){
    Node* new_node=new Node(data);
    if(head==NULL){
        head=new_node;
        head->next=head;
        return ;
    }
    Node* tail=head;
    while(tail!=head){
        tail=tail->next;
    }
    tail->next=new_node;
    new_node->next=head;
    head=new_node;
}
void insert_end(Node* &head,int data){
    Node* new_node=new Node(data);
    if(head==NULL){
        head=new_node;
        head->next=new_node;
        return ;
    }
    Node* tail=head;
    while(tail!=head){
        tail=tail->next;
    }
    tail->next=new_node;
    new_node->next=head;
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
    cout<<"Enter your no : ";
    cin>>data;
    insert(aa.head,data);
    for(int i=0;i<5;i++){
        cout<<"Enter your no :";
        cin>>data;
        insert_end(aa.head,data);
    }
    display(aa.head);
    return 0;
}