// Reverse the given node at k times
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

Node* reverse_k(Node* &head,int k){
    Node* prevptr=NULL;
    Node* currptr=head;

    int count=0;
    while(currptr !=NULL && count<k){
        Node* nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }

    if(currptr !=NULL){
        Node* new_head=reverse_k(currptr,k);
        head->next=new_head;
    }
    return prevptr;

}

void display(Node* head){
    Node* temp=head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

int main(){
    int k;
    Node* head=NULL;
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,6);
    display(head);
    cout<<endl;
    cout<<"Enter your position to change the node : ";
    cin>>k;
    Node* temp=reverse_k(head,k);
    display(temp);
    return 0;
}