// remove the duplicate Element from linked list
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
void insert_tail(Node* &head,int data){
    Node* temp=new Node(data);
    Node* head1=head;
    while(head1->next!=NULL){
        head1=head1->next;
    }
    head1->next=temp;
}

void remove_duplicate(Node* &head){
    Node* current=head;
    while(current!=NULL && current->next!=NULL){
        if(current->data==current->next->data){
            Node* temp=current->next;
            current->next=current->next->next;
            free(temp);
        }
        current=current->next;
    }
}

Node* reverse(Node* &head){
    Node* head1=head;
    // base case
    if(head1==NULL && head1->next==NULL){
        return head;
    }
    //recursive case
    Node* new_node=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return new_node;
}
int len(Node* head){
    int leng=0;
    while(head!=NULL){
        head=head->next;
        leng++;
    }
    return leng;
}
int delete_k(Node* &head,int k){
    Node* head1=head;
    int count=len(head);
    int cur=count-k-1;
    int pos=0;
    while(pos!=cur){
        head1=head1->next;
        pos++;
    }
    Node* temp=head1->next;
    head1->next=head1->next->next;
    int val=temp->data;
    return val;
    }
void display(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    Node* head=new Node(1);
    insert_tail(head,2);
    insert_tail(head,2);
    insert_tail(head,3);
    insert_tail(head,4);
    insert_tail(head,4);
    remove_duplicate(head);
    display(head);
    cout<<endl;
   // display(head);
   // reverse(head);
   cout<<delete_k(head,3)<<endl;
    display(head);
    
    return 0;
}