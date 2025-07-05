// Rotate the Node Kth Times from the Right side
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
    while(lnode->next!=NULL){
        lnode=lnode->next;
    }
    lnode->next=temp;
}

Node* rotate(Node* &head,int k){
    int n=0;
    Node* tail=head;
    while(tail->next!=NULL){
        n++;
        tail=tail->next;
    }
    n++;
    k=k%n;

    if(k==0) return head;
    tail->next=head;
    Node* temp=head;
    for(int i=1;i<n-k;i++){
        temp=temp->next;
    }

    Node* new_head=temp->next;
    temp->next=NULL;
    return new_head;
}
void diplay(Node* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}

int main(){
    Node* head=NULL;
    insert(head,1);
    int data;
    for(int i=0;i<6;i++){
        cout<<"Enter your no : ";
        cin>>data;
        insert_tail(head,data);
    }
    diplay(head);
    cout<< endl;
    Node* temp=rotate(head,2);
    diplay(temp);
    return 0;
}
