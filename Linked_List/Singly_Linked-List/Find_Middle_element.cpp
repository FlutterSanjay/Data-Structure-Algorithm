// find the Middle Element 
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
    while(lnode->next !=NULL){
        lnode=lnode->next;
    }
    lnode->next=temp;
}

Node* middle(Node* &head){
    Node* ptr=head;
    Node* ptr1=head;
    while(ptr!=NULL && ptr1->next!=NULL){
        ptr=ptr->next;
        ptr1=ptr1->next->next;
    }
    return ptr;     
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
    for(int i=0;i<4;i++){
        cout<<"Enter your no : ";
        cin>>data;
        insert_tail(head,data);
    }
    display(head);
    cout<<endl;
    Node* temp=middle(head);
    cout<<temp->val;
    return 0;
}