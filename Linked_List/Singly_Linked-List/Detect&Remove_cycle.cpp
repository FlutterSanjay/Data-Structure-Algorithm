// Detet and Remove the Linked List
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
void insert_tail(Node* & head,int data){
    Node* temp=new Node(data);
    Node* lnode=head;
    while(lnode->next!=NULL){
        lnode=lnode->next;
    }
    lnode->next=temp;
}

bool check_cycle(Node* head){
    if(head==NULL) return false;
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}
void remove_cycle(Node* head){
    Node* slow=head;
    Node* fast=head;

    do{
        slow=slow->next;
        fast=fast->next->next;
    }
    while(slow!=fast);
    fast=head;
    while(slow->next != fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
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
    for(int i=0;i<7;i++){
        cout<<"Enter your no : ";
        cin>>data;
        insert_tail(head,data);
    }
    display(head);
    cout<<endl;
     head->next->next->next->next->next->next->next->next=head->next->next->next;
    bool result=check_cycle(head);
    if(result==true) cout<<"Cycle is Present !";
    else cout<<"Cycle is Not Present !";
    
    remove_cycle(head);
    cout<<endl;
     bool resul=check_cycle(head);
    if(resul==true) cout<<"Cycle is Present !";
    else cout<<"Cycle is Not Present !";
    cout<<endl;
    display(head);
    return 0;
}