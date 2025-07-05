// add node at any position
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
void insert_pos(Node* &head,int data,int k){
Node* temp=head;
Node* node=new Node(data);
if(k==0){
    while(temp->next != head){
        temp=temp->next;
    }
    node->next=head;
    head=node;
    temp->next=node;
    return ;
}
int i=0;
while(i!=k-1 && temp->next!=head){
    i++;
    temp=temp->next;
}
node->next=temp->next;
temp->next=node;
return ;
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
    cout<<endl;
    insert_pos(aa.head,6,3);
    display(aa.head);
    return 0;
}