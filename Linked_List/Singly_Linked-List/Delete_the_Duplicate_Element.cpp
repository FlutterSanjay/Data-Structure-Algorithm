// remove the duplicate elemen from the node
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

void duplicate(Node* &head){
    Node* current=head;
    while(current != NULL){
        while( current->next != NULL && current->val == current->next->val){
            Node* temp=current->next;
            current->next=current->next->next;
            free(temp);
        }
        current=current->next;
    }
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
    int data;
    for(int i=0;i<4;i++){
        cout<<"Enter your no : ";
        cin>>data;
        insert_tail(head,data);
    }
    display(head);
    cout<<endl;
    duplicate(head);
    display(head);
    cout<<endl;
    return 0;
}