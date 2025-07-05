// Swap the Ajacent Element
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

void insert(Node* & head,int data){
    Node * temp=new Node(data);
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

Node* swap_adjacent(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* second=head->next;
    head->next=swap_adjacent(second->next);
    second->next=head;
    return second;
}

void display(Node* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}

int main(){
    Node* head=NULL;
    insert(head,1);
    int data;
    for(int i=0;i<4;i++){
        cout<<"Enter your no :";
        cin>>data;
        insert_tail(head,data);
    }
    display(head);

    Node* temp=swap_adjacent(head);
    cout<<endl;
    display(temp);
    return 0;
}