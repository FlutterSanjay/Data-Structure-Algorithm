// Merge Two sorted Node
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

Node* merge(Node* &head1,Node* &head2){
   Node* dummy=new Node(-1);
   Node* ptr1=head1;
   Node* ptr2=head2;
   Node* ptr3=dummy;

   while(ptr1!=NULL && ptr2!=NULL){
    if(ptr1->val<ptr2->val){
        ptr3->next=ptr1;
        ptr1=ptr1->next;
    }
    else{
        ptr3->next=ptr2;
        ptr2=ptr2->next;
    }
    ptr3=ptr3->next;
   }
   if(ptr1!=NULL){
    ptr3->next=ptr1;
   }
   else{
    ptr3->next=ptr2;
   }
   return dummy->next;
}

void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
void insert_tail(Node* &head,int data){
    Node* temp=new Node(data);
    Node* lnode=head;

    while(lnode->next !=NULL){
        lnode=lnode->next;
    }
    lnode->next=temp;
}
int main(){
    Node* head1=NULL;
    Node* head2=NULL;

    insert(head1,1);
    int data;
    for(int i=0;i<2;i++){
        cout<<"Enter your no : ";
        cin>>data;
        insert_tail(head1,data);
    }
    display(head1);

    cout<< endl;

    insert(head2,2);
    
    for(int i=0;i<2;i++){
        cout<<"Enter your no : ";
        cin>>data;
        insert_tail(head2,data);
    }
    display(head2);
    Node* temp=merge(head1,head2);
    cout<<endl;
    display(temp);
    return 0;
}